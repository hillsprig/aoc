#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <vector>
#include <array>
#include <algorithm>
#include <fmt/core.h>
#include <iostream>
#include <ranges>

using Catch::Matchers::Contains;
using Catch::Matchers::EndsWith;

namespace {
    using Password = std::array<int, 6>;
}

template<>
struct fmt::formatter<Password> {
    template<typename ParseContext>
    constexpr auto parse(ParseContext &ctx) {
        return ctx.begin();
    }

    template<typename FormatContext>
    auto format(Password const &password, FormatContext &ctx) {
        for (auto &p : password) {
            fmt::format_to(ctx.out(), "{}", p);
        }
        return ctx.out();
    }
};

std::array<int, 6> to_array(int n) {

    Password ret;
    for (int i = 5; i >= 0; --i) {
        ret[i] = n % 10;
        n /= 10;
    }
    return ret;
}

TEST_CASE("Day04") {
    std::vector<Password> pp;
    pp.reserve(675810 - 134792);

    for (int i = 134792; i <= 675810; ++i) {
        pp.push_back(to_array(i));
    }

    auto results = pp
                   |
                   std::ranges::views::filter([](Password const &p) {
                       for (auto it = p.begin(); std::next(it) != p.end(); ++it) {
                           if (*it > *std::next(it)) {
                               return false;
                           }
                       }
                       return true;
                   })
                   |
                   std::ranges::views::filter([](Password const &p) {
                       for (auto it = p.begin(); std::next(it) != p.end(); ++it) {
                           if ((*it == *std::next(it)) && 2 == std::count(p.begin(), p.end(), *it)) {
                               return true;
                           }
                       }
                       return false;
                   });

    std::cout << std::distance(results.begin(), results.end());

    std::string const Jonas { "TechLead" };
    CHECK(Jonas == "TechLead2");
    REQUIRE(Jonas == "TechLead");
    REQUIRE_THAT(Jonas, Contains("Techlead") && EndsWith("Forever"));
}
