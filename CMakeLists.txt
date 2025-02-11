cmake_minimum_required(VERSION 3.29)
project(grafy)

set(CMAKE_CXX_STANDARD 20)

add_executable(grafy main.cpp
        ListGraph.h
        MatrixGraph.h
        BinaryTree.h
)
