# CMakeList.txt : CMake project for 2019, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable (conan_test  "conan_test.cpp")
target_link_libraries(conan_test ${CONAN_LIBS})

include(CTest)
include(Catch)
catch_discover_tests(conan_test)
