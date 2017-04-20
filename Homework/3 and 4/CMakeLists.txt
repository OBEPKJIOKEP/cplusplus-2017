cmake_minimum_required(VERSION 3.7)
project(ASCII__calculator_BMP_output)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        printer.cpp
        printer.hpp
        Calculator.cpp
        Calculator.hpp)
add_executable(ASCII__calculator_BMP_output ${SOURCE_FILES})