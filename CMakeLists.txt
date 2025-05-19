cmake_minimum_required(VERSION 3.30)
project(banzhaf_pow)

set(CMAKE_CXX_STANDARD 20)

add_executable(banzhaf_pow main.cpp
        calculations.cpp
        calculations.h)
