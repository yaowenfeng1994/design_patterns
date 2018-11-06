cmake_minimum_required(VERSION 3.12)
project(design_patterns)

set(CMAKE_CXX_STANDARD 11)

include_directories(strategy)

add_executable(design_patterns main.cpp strategy/strategy.cpp)