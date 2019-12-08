# CMakeList.txt : CMake project for 2019, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

# Add source to this project's executable.
add_executable (day03  "day03.cpp")

target_link_libraries(day03 ${Boost_LIBRARIES})
target_link_libraries(day03 fmt::fmt)
target_link_libraries(day03 Catch2::Catch2)

target_compile_options(day03 PRIVATE -Werror)
