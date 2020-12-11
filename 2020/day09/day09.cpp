#include <catch2/catch.hpp>

#include "input.h"

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <regex>
#include <sstream>
#include <vector>
#include <span>
//#include <execution>

namespace {
bool isValid(std::span<const long> cache, long value) {
    for (const long &i : cache) {
        if (i < value) {
        for (const long &j : cache) {
            if (i + j == value) {
                return true;
            }
        }
        }
    }
    return false;
}

template <size_t N, size_t PREAMBLE> long find_invalid(const std::array<long, N> input) {
    const std::span cache(input);
    for (size_t i = PREAMBLE; i < input.size(); ++i) {
        if (!isValid(cache.subspan(i - PREAMBLE, PREAMBLE), input[i])) {
            return input[i];
        }
    }
    return 0;
}

long find_contiguous(const std::span<const long> &input, long value) {
    auto accu = [value](std::span<const long>::iterator it) -> long {
        std::vector<long> result;
        long total = *it;
        result.push_back(total);
        ++it;
        do {
            long n = *it;
            result.push_back(n);
            total += n;
            ++it;
        } while (total < value);
        if (total == value) {
            std::sort(result.begin(), result.end());
            return *result.cbegin() + *std::prev(result.cend());
        }
        return 0;
    };

    for (std::span<const long>::iterator it = input.begin(); it != input.end(); ++it) {
        if (*it < value) {
            if (long result = accu(it)) {
                return result;
            }
        }
    }
    return 0;
}
} // namespace

TEST_CASE("day09_1_sample") { REQUIRE(find_invalid<input::sample.size(), 5>(input::sample) == 127); }

TEST_CASE("day09_1_puzzle") { REQUIRE(find_invalid<input::puzzle.size(), 25>(input::puzzle) == 400480901); }

TEST_CASE("day09_2_sample") {
    const std::span input(input::sample);
    long value = find_invalid<input::sample.size(), 5>(input::sample);
    REQUIRE(find_contiguous(input, value) == 62);
}

TEST_CASE("day09_2_puzzle") {
    const std::span input(input::puzzle);
    long value = find_invalid<input::puzzle.size(), 25>(input::puzzle);
    REQUIRE(find_contiguous(input, value) == 67587168);
}
