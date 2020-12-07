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
#include <bitset>
#include <string>
#include <tuple>

namespace {
template <size_t MIN, size_t MAX, char FORWARD, char BACKWARD>
constexpr size_t get_bit(const std::string_view srow) {
    size_t row_max = MAX;
    size_t row_min = MIN;
    for (const auto c : srow) {
        if (FORWARD == c) {
            row_max -= (row_max - row_min) / 2;
        } else if (BACKWARD == c) {
            row_min += (row_max - row_min) / 2;
        } else {
            continue; // optimize onegai
        }
    }
    assert(row_min == row_max - 1);
    return row_min;
}

std::tuple<size_t, size_t, size_t> getValues(std::string_view s) {
    size_t row = get_bit<0, 128, 'F', 'B'>(s);
    size_t seat = get_bit<0, 8, 'L', 'R'>(s);
    size_t id = row * 8 + seat;
    return {row, seat, id};
}
} // namespace

TEST_CASE("day05_1_sample") {
    {
        auto values = getValues(input::sample[0]);
        REQUIRE(std::get<0>(values) == 70);
        REQUIRE(std::get<1>(values) == 7);
        REQUIRE(std::get<2>(values) == 567);
    }
    {
        auto values = getValues(input::sample[1]);
        REQUIRE(std::get<0>(values) == 14);
        REQUIRE(std::get<1>(values) == 7);
        REQUIRE(std::get<2>(values) == 119);
    }
    {
        auto values = getValues(input::sample[2]);
        REQUIRE(std::get<0>(values) == 102);
        REQUIRE(std::get<1>(values) == 4);
        REQUIRE(std::get<2>(values) == 820);
    }
}

TEST_CASE("day05_1_puzzle") {
    size_t largest_id = 0;
    for (const auto& s : input::puzzle) {
        auto values = getValues(s);
        if (largest_id < std::get<2>(values)) {
            largest_id = std::get<2>(values);
        }
    }
    REQUIRE(largest_id == 885);
}

TEST_CASE("day05_2_sample") {
}

TEST_CASE("day05_2_puzzle") {
    std::vector<size_t> ids;
    for (const auto& s : input::puzzle) {
        auto values = getValues(s);
        ids.push_back(std::get<2>(values));
    }
    std::sort(ids.begin(), ids.end());
    std::vector<size_t> diffs;

    std::adjacent_difference(ids.cbegin(), ids.cend(), std::back_inserter(diffs));
    auto pos = std::find(diffs.cbegin(), diffs.cend(), 2);
    auto index = std::distance(diffs.cbegin(), pos);

    REQUIRE(ids[index] - 1 == 623);
}
