cmake_minimum_required(VERSION 3.29)
project(FINAL)

set(CMAKE_CXX_STANDARD 20)

add_executable(FINAL main.cpp
        Videos.cpp
        Videos.h
        Movies.cpp
        Movies.h
        Chapters.cpp
        Chapters.h
        test.cpp
        test.h)
