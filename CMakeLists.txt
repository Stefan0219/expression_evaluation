cmake_minimum_required(VERSION 3.22)
project(expr)

set(CMAKE_CXX_STANDARD 14)

add_executable(expr main.cpp src/lexical_analysis.cpp headers/lexical_analysis.h src/number.cpp headers/number.h headers/util.h src/syntatic_analysis.cpp headers/syntatic_analysis.h src/evaluation.cpp headers/evaluation.h)
