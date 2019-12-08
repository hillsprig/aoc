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
const std::string BirthYear = "byr";
const std::string IssueYear = "iyr";
const std::string ExpirationYear = "eyr";
const std::string Height = "hgt";
const std::string HairColor = "hcl";
const std::string EyeColor = "ecl";
const std::string PassportID = "pid";
const std::string CountryID = "cid";

const std::array valid1 = {BirthYear, IssueYear, ExpirationYear, Height,
                           HairColor, EyeColor,  PassportID};

std::regex field_regex = std::regex(R"((\w{3}):(\S+))");

auto mapResult(const std::string s) {
    std::vector<std::string> key{
        std::sregex_token_iterator(s.cbegin(), s.cend(), field_regex, 1),
        std::sregex_token_iterator()};

    std::vector<std::string> value{
        std::sregex_token_iterator(s.cbegin(), s.cend(), field_regex, 2),
        std::sregex_token_iterator()};

    std::map<const std::string, const std::string> fields;
    std::transform(key.cbegin(), key.cend(), value.cbegin(),
                   std::inserter(fields, fields.end()),
                   [](const std::string a, const std::string b) {
                       return std::make_pair(a, b);
                   });

    return fields;
}
bool isValid(auto fields) {
    bool ret = true;
    for (const auto &c : valid1) {
        ret &= fields.contains(c);
    }
    return ret;
}

bool isValid2(auto fields) {
    bool ret = true;
    if (ret &= fields.contains(BirthYear)) {
        size_t byr = std::stoul(fields.at(BirthYear));
        ret &= (byr >= 1920 && byr <= 2002);
    }
    if (ret &= fields.contains(IssueYear)) {
        size_t iyr = std::stoul(fields.at(IssueYear));
        ret &= (iyr >= 2010 && iyr <= 2020);
    }
    if (ret &= fields.contains(ExpirationYear)) {
        size_t eyr = std::stoul(fields.at(ExpirationYear));
        ret &= (eyr >= 2020 && eyr <= 2030);
    }
    if (ret &= fields.contains(Height)) {
        std::string h = fields.at(Height);
        if (h.ends_with("cm")) {
            h.erase(std::prev(std::prev(h.end())), h.end());
            size_t hgt = std::stoul(h);
            ret &= (hgt >= 150 && hgt <= 193);
        } else if (h.ends_with("in")) {
            h.erase(std::prev(std::prev(h.end())), h.end());
            size_t hgt = std::stoul(h);
            ret &= (hgt >= 59 && hgt <= 76);
        } else {
            ret &= false;
        }
    }
    if (ret &= fields.contains(HairColor)) {
        std::regex hairex = std::regex(R"(^#[a-f0-9]{6}$)");
        std::string hcl = fields.at(HairColor);
        ret &= std::regex_match(hcl, hairex);
    }
    if (ret &= fields.contains(EyeColor)) {
        const std::vector<std::string> colors{"amb", "blu", "brn", "gry",
                                              "grn", "hzl", "oth"};
        std::string ecl = fields.at(EyeColor);
        ret &= std::find(std::cbegin(colors), std::cend(colors), ecl) !=
               std::end(colors);
    }
    if (ret &= fields.contains(PassportID)) {
        std::string pid = fields.at(PassportID);
        std::regex pidex = std::regex(R"(^[0-9]{9}$)");
        ret &= std::regex_match(pid, pidex);
    }

    return ret;
}
} // namespace

TEST_CASE("day04_1_sample") {
    std::istringstream iss(input::sample);

    size_t validPassports = 0;
    std::string s;
    for (std::string line; std::getline(iss, line);) {
        if (line == "") {
            if (isValid(mapResult(s))) {
                ++validPassports;
            }
            s.clear();
        } else {
            s += line + " ";
        }
    }
    if (isValid(mapResult(s))) {
        ++validPassports;
    }

    REQUIRE(validPassports == 2);
}

TEST_CASE("day04_1_puzzle") {
    std::istringstream iss(input::puzzle);

    size_t validPassports = 0;
    std::string s;
    for (std::string line; std::getline(iss, line);) {
        if (line == "") {
            if (isValid(mapResult(s))) {
                ++validPassports;
            }
            s.clear();
        } else {
            s += line + " ";
        }
    }
    if (isValid(mapResult(s))) {
        ++validPassports;
    }

    REQUIRE(validPassports == 233);
}

TEST_CASE("day04_2_sample") {
    std::istringstream iss(input::sample2);

    size_t validPassports = 0;
    std::string s;
    for (std::string line; std::getline(iss, line);) {
        if (line == "") {
            if (isValid2(mapResult(s))) {
                ++validPassports;
            }
            s.clear();
        } else {
            s += line + " ";
        }
    }
    if (isValid2(mapResult(s))) {
        ++validPassports;
    }

    REQUIRE(validPassports == 4);
}

TEST_CASE("day04_2_puzzle") {
    std::istringstream iss(input::puzzle);

    size_t validPassports = 0;
    std::string s;
    for (std::string line; std::getline(iss, line);) {
        if (line == "") {
            if (isValid2(mapResult(s))) {
                ++validPassports;
            }
            s.clear();
        } else {
            s += line + " ";
        }
    }
    if (isValid2(mapResult(s))) {
        ++validPassports;
    }

    REQUIRE(validPassports == 111);
}
