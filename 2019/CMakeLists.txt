# CMakeList.txt : CMake project for 2019, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
find_package(Catch2 REQUIRED)

add_compile_options(-fdiagnostics-color=always)

add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2 -Weffc++)

# Clang special branch -Wlifetime

#find_program(CLANGTIDY clang-tidy)
#set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)

add_subdirectory ("day01")
add_subdirectory ("day02")
add_subdirectory ("day03")
add_subdirectory ("day04")
#add_subdirectory ("conan_test")
