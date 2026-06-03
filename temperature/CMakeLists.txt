cmake_minimum_required(VERSION 3.31)
project(temperature)

set(CMAKE_CXX_STANDARD 23)

add_executable(temperature main.cpp
        test.cpp
        test.h)
