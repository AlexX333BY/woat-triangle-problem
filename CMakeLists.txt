cmake_minimum_required(VERSION 3.7)
project(woat_triangle_problem)

find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

source_group("Sources" FILES ${SOURCES})
source_group("Headers" FILES ${HEADERS})

add_executable(woat_triangle_problem ${SOURCES} ${HEADERS})
target_link_libraries(woat_triangle_problem ${wxWidgets_LIBRARIES})
