cmake_minimum_required(VERSION 3.16)
project(create-cpp-project)

add_subdirectory(src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_BUILD_TYPE Debug)