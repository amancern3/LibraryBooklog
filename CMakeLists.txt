cmake_minimum_required(VERSION 3.13)
project(p1_phase)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(p1_phase main.cpp SearchNewBooks.h)
