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

namespace {
size_t uniqueAnswers(const std::string &input) {
    size_t result = 0;
    std::istringstream iss(input);
    std::map<char, size_t> yes_answers;
    for (std::string line; std::getline(iss, line);) {
        if (line == "") {
            result += yes_answers.size();
            yes_answers.clear();
        } else {
            for (const auto c : line) {
                yes_answers[c]++;
            }
        }
    }
    return result;
}

size_t uniformAnswers(const std::string &input) {
    size_t result = 0;
    std::istringstream iss(input);
    std::map<char, size_t> yes_answers;
    for (std::string line; std::getline(iss, line);) {
        if (line == "") {
            if (yes_answers.contains('.')) {
                size_t participants = yes_answers['.'];
                yes_answers.erase('.');
                for (auto const &p : yes_answers) {
                    if (p.second == participants) {
                        result++;
                    }
                }
            }
            yes_answers.clear();
        } else {
            yes_answers['.']++;
            for (const auto c : line) {
                yes_answers[c]++;
            }
        }
    }
    return result;
}
} // namespace

TEST_CASE("day06_1_sample") {
    REQUIRE(uniqueAnswers(input::sample) == 11);
}

TEST_CASE("day06_1_sample2") {
    REQUIRE(uniqueAnswers(input::sample2) == 6);
}

TEST_CASE("day06_1_puzzle") {
    REQUIRE(uniqueAnswers(input::puzzle) == 6768);
}

TEST_CASE("day06_2_sample") {
    REQUIRE(uniformAnswers(input::sample) == 6);
}

TEST_CASE("day06_2_puzzle") {
    REQUIRE(uniformAnswers(input::puzzle) == 3489);
}
