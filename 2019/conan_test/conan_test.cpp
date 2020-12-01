#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <fmt/core.h>
#include <Poco/MD5Engine.h>

TEST_CASE("conan_test") {
    Poco::MD5Engine md5;
}
