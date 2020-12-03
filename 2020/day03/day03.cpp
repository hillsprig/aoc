#include <catch2/catch.hpp>

#include "input.h"

#include <algorithm>
#include <array>
#include <fmt/core.h>
#include <iostream>
#include <optional>

namespace {
template <size_t SIZE>
constexpr size_t countTrees(const std::array<const char *, SIZE> &input,
                            const size_t right, const size_t down) {
    size_t x = 0;
    size_t trees = 0;

    for (size_t y = 0; y < input.size(); y = y + down) {
        std::string_view s = input.at(y);
        if (s[x] == '#') {
            ++trees;
        }
        x = (x + right) % s.size();
    }
    return trees;
}
} // namespace

TEST_CASE("day03_1_sample") {
    size_t x = 0;
    size_t trees = 0;

    for (size_t y = 0; y < input::sample.size(); ++y) {
        std::string_view s = input::sample.at(y);
        if (s[x] == '#') {
            ++trees;
        }
        x = (x + 3) % s.size();
    }
    REQUIRE(trees == 7);
}

TEST_CASE("day03_1_puzzle") {
    size_t x = 0;
    size_t trees = 0;

    for (size_t y = 0; y < input::puzzle.size(); ++y) {
        std::string_view s = input::puzzle.at(y);
        if (s[x] == '#') {
            ++trees;
        }
        x = (x + 3) % s.size();
    }
    REQUIRE(trees == 151);
}

TEST_CASE("day03_2_sample") {
    REQUIRE(countTrees<input::sample.size()>(input::sample, 1, 1) == 2);
    REQUIRE(countTrees<input::sample.size()>(input::sample, 3, 1) == 7);
    REQUIRE(countTrees<input::sample.size()>(input::sample, 5, 1) == 3);
    REQUIRE(countTrees<input::sample.size()>(input::sample, 7, 1) == 4);
    REQUIRE(countTrees<input::sample.size()>(input::sample, 1, 2) == 2);
}

TEST_CASE("day03_2_puzzle") {
    size_t product = 1;
    product *= countTrees<input::puzzle.size()>(input::puzzle, 1, 1);
    product *= countTrees<input::puzzle.size()>(input::puzzle, 3, 1);
    product *= countTrees<input::puzzle.size()>(input::puzzle, 5, 1);
    product *= countTrees<input::puzzle.size()>(input::puzzle, 7, 1);
    product *= countTrees<input::puzzle.size()>(input::puzzle, 1, 2);

    REQUIRE(product == 7540141059);
}
