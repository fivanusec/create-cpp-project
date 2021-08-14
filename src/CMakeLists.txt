cmake_minimum_required(VERSION 3.16)

project(src VERSION 1)
set(CMAKE_CXX_STANDARD 17)
add_executable(create-cpp-project Directory.cpp Directory.h Files.cpp Files.h main.cpp)
include_directories(${CMAKE_SOURCE_DIR})
set(CMAKE_BUILD_TYPE Debug)

target_link_libraries(create-cpp-project PUBLIC stdc++fs)
