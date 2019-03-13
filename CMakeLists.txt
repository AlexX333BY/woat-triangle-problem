cmake_minimum_required(VERSION 3.13)
project(woat_triangle_problem)

find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

add_executable(woat_triangle_problem src/main.cpp)
target_link_libraries(woat_triangle_problem ${wxWidgets_LIBRARIES})
