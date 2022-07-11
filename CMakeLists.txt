cmake_minimum_required(VERSION 3.22)
project(expr)

set(CMAKE_CXX_STANDARD 14)

add_executable(expr main.cpp lexical_analysis.cpp lexical_analysis.h)
