# CMakeList.txt : CMake project for 2019, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

# Add source to this project's executable.
add_executable (day09  "main.cpp" "day09.cpp")

target_link_libraries(day09 ${Boost_LIBRARIES})
target_link_libraries(day09 fmt::fmt)
target_link_libraries(day09 Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(day09)
