# CMakeList.txt : CMake project for 2019, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("C:/Program Files/boost/boost_1_74_0")
set(Boost_INCLUDE_DIR "C:/Program Files/boost/boost_1_74_0")
set(Boost_LIBRARY_DIR "C:/Program Files/boost/boost_1_74_0/lib")
find_package(Boost 1.74.0 REQUIRED)

add_subdirectory ("day01")
add_subdirectory ("day02")
add_subdirectory ("day03")
add_subdirectory ("day04")