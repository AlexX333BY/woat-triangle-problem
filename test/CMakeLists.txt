cmake_minimum_required(VERSION 3.7)
project(woat_triangle_problem)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(woat_triangle_problem_test "test.cpp" "../src/Triangle.h" "../src/Triangle.cpp")
target_link_libraries(woat_triangle_problem_test ${Boost_LIBRARIES})
