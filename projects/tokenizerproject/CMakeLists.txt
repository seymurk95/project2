cmake_minimum_required(VERSION 3.29)
project(tokenizerproject)

set(CMAKE_CXX_STANDARD 20)

add_executable(tokenizerproject main.cpp
        tokenizer.h
        parser.h
        tokenizer.cpp
        parser.cpp)
