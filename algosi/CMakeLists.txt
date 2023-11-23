cmake_minimum_required(VERSION 3.24)
project(algosi)

set(CMAKE_CXX_STANDARD 17)

add_executable(algosi parse_url.cpp parse_url_test.cpp parse_url.h)
