cmake_minimum_required(VERSION 3.15)
project(HammingAlgo)

set(CMAKE_CXX_STANDARD 14)

add_executable(HammingAlgo Test.cpp HammingCodes.h HammingCodes.cpp)