cmake_minimum_required(VERSION 3.3)
project(GraphAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MatrixGraph.cpp GraphLibrary/Graph.cpp GraphLibrary/Graph.h GraphLibrary/Searches/Dijkstra.h GraphLibrary/Searches/AStar.h GraphLibrary/Searches/FordBellman.h GraphLibrary/Searches/WidthFastSearch.h GraphLibrary/Searches/GraphLibrary.h)
add_executable(GraphAlgorithms ${SOURCE_FILES})