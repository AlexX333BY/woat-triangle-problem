cmake_minimum_required(VERSION 3.7)
project(woat_triangle_problem)

find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(woat_triangle_problem "test.cpp" "../src/Triangle.h" "../src/Triangle.cpp")
target_link_libraries(woat_triangle_problem ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})
