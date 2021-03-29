cmake_minimum_required(VERSION 3.17)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Assignment_1)

add_executable(Assignment_1
        Assignment_1/Assignment_1.cpp
        Assignment_1/GradeReport.cpp
        Assignment_1/GradeReport.h)
