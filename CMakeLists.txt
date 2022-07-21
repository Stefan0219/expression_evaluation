cmake_minimum_required(VERSION 3.22)
project(expr)

set(CMAKE_CXX_STANDARD 14)

add_executable(expr main.cpp src/lexical_analysis.cpp include/lexical_analysis.h src/number.cpp include/number.h include/util.h src/syntatic_analysis.cpp include/syntatic_analysis.h src/evaluation.cpp include/evaluation.h)
