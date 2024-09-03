cmake_minimum_required(VERSION 3.25)
project(DS_design)

set(CMAKE_CXX_STANDARD 14)

include_directories(exp5)

add_executable(DS_design
        exp5/main.cpp
        exp5/suffixTree.cpp
        exp5/suffixTree.h exp2/src/externalSort.cpp exp2/src/externalSort.h exp2/src/main.cpp)
