cmake_minimum_required(VERSION 3.12)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Graph
        Graph.cpp
        Graph.h
        List.cpp
        List.h
        main.cpp
        Node.cpp
        Node.h)
