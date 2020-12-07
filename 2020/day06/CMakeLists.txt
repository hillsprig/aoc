# CMakeList.txt : CMake project for 2019, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

# Add source to this project's executable.
add_executable (day06  "main.cpp" "day06.cpp")

target_link_libraries(day06 fmt::fmt)
target_link_libraries(day06 Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(day06)
