cmake_minimum_required(VERSION 3.13)
project(woat_triangle_problem)

find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

add_executable(woat_triangle_problem src/Main.cpp src/TriangleProblemApp.cpp src/TriangleProblemApp.h src/TriangleProblemFrame.cpp src/TriangleProblemFrame.h src/AnalyzeTriangleSidesEvent.cpp src/AnalyzeTriangleSidesEvent.h)
target_link_libraries(woat_triangle_problem ${wxWidgets_LIBRARIES})
