#include <catch2/catch.hpp>

#include "input.h"

#include <algorithm>
#include <array>
#include <fmt/core.h>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <regex>
#include <sstream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>

namespace {
using EdgeProperty = boost::property<boost::edge_weight_t, int>;
using VertexProperty = boost::property<boost::vertex_name_t, std::string>;
using DirectedGraph =
    boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, VertexProperty, EdgeProperty>;
using Vertex = boost::graph_traits<DirectedGraph>::vertex_descriptor;
using EdgeIterator = boost::graph_traits<DirectedGraph>::edge_iterator;
using VertexIterator = boost::graph_traits<DirectedGraph>::vertex_iterator;
using VertexNamePropertyMap = boost::property_map<DirectedGraph, boost::vertex_name_t>::type;
using EdgeWeightPropertyMap = boost::property_map<DirectedGraph, boost::edge_weight_t>::type;
using Rule = std::vector<std::tuple<int, std::string>>;
using IdMap = std::map<std::string, Vertex>;

Vertex translate(const std::string &s, IdMap &t, DirectedGraph &g) {
    if (!t.contains(s)) {
        t[s] = boost::add_vertex(s, g);
    }
    return t[s];
}

std::regex bag_regex = std::regex(R"(((\d*)\s*(\w+ \w+ bag)))");
auto parse_line(const std::string &s) {
    std::vector<std::string> bag_colors{std::sregex_token_iterator(s.cbegin(), s.cend(), bag_regex, 3),
                                        std::sregex_token_iterator()};

    std::vector<std::string> bag_numbers{std::sregex_token_iterator(s.cbegin(), s.cend(), bag_regex, 2),
                                         std::sregex_token_iterator()};

    std::replace(bag_numbers.begin(), bag_numbers.end(), std::string(""), std::string("0"));

    Rule rule;
    std::transform(bag_numbers.cbegin(), bag_numbers.cend(), bag_colors.cbegin(), std::back_inserter(rule),
                   [](const std::string lhs, const std::string rhs) { return std::make_tuple(std::stoi(lhs), rhs); });

    return rule;
}
auto create_graph(const std::string &input, IdMap &ids) {
    DirectedGraph g;
    std::istringstream iss(input);
    for (std::string line; std::getline(iss, line);) {
        auto rule = parse_line(line);
        [[maybe_unused]] auto [n_origin, c_origin] = rule.at(0);
        size_t id_origin = translate(c_origin, ids, g);
        for (size_t i = 1; i < rule.size(); ++i) {
            auto [n_target, c_target] = rule.at(i);
            if ("no other bag" != c_target) {
                size_t id_target = translate(c_target, ids, g);
                boost::add_edge(id_origin, id_target, n_target, g);
            }
        }
    }

    return g;
}

bool leads_to_golden(Vertex from, Vertex to, DirectedGraph &g, bool result) {
    for (auto ed : boost::make_iterator_range(boost::out_edges(from, g))) {
        Vertex target = boost::target(ed, g);
        if (target == to) {
            return true;
        }
        result |= leads_to_golden(target, to, g, false);
    }
    return result;
}

int paths_to_the_golden_baggu(Vertex to, DirectedGraph &g) {
    int result = 0;
    for (auto vd : boost::make_iterator_range(boost::vertices(g))) {
        if (leads_to_golden(vd, to, g, false)) {
            ++result;
        }
    }
    return result;
}

int find_paths(const std::string &input) {
    IdMap ids;
    DirectedGraph g = create_graph(input, ids);
    int paths = paths_to_the_golden_baggu(ids["shiny gold bag"], g);

    return paths;
}

int bags_in_golden_bag(Vertex bag, DirectedGraph &g) {
    //VertexNamePropertyMap vertName = boost::get(boost::vertex_name, g);
    EdgeWeightPropertyMap edgeWeight = boost::get(boost::edge_weight, g);

    int n_bags = 0;
    for (auto ed : boost::make_iterator_range(boost::out_edges(bag, g))) {
        n_bags += edgeWeight[ed];
        Vertex target = boost::target(ed, g);
        for (int i = edgeWeight[ed]; i > 0; --i) {
            n_bags += bags_in_golden_bag(target, g);
        }
    }
    return n_bags;
}

int bag_of_holding(const std::string &input) {
    IdMap ids;
    DirectedGraph g = create_graph(input, ids);

    Vertex golden = ids["shiny gold bag"];
    int n_bags = bags_in_golden_bag(golden, g);

    return n_bags;
}

} // namespace

TEST_CASE("day07_1_sample") { REQUIRE(find_paths(input::sample) == 4); }

TEST_CASE("day07_1_puzzle") { REQUIRE(find_paths(input::puzzle) == 254); }

TEST_CASE("day07_2_sample") { REQUIRE(bag_of_holding(input::sample) == 32); }

TEST_CASE("day07_2_sample2") { REQUIRE(bag_of_holding(input::sample2) == 126); }

TEST_CASE("day07_2_puzzle") { REQUIRE(bag_of_holding(input::puzzle) == 6006); }
