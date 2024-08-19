cmake_minimum_required(VERSION 3.20)

project(CurvesTask VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(curves-library)
add_subdirectory(curves-executable)
