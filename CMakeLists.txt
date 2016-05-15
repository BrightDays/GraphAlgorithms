cmake_minimum_required(VERSION 3.3)
project(GraphAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp

        GraphLibrary/GraphsImplementations/MatrixGraph.cpp
        GraphLibrary/GraphsImplementations/MatrixGraph.h
        GraphLibrary/GraphsImplementations/Graph.cpp
        GraphLibrary/GraphsImplementations/Graph.h
        GraphLibrary/GraphsImplementations/OrientedGraph.cpp
        GraphLibrary/GraphsImplementations/OrientedGraph.h

        GraphLibrary/SimpleAlgorithms/StrongConnectedComponentsSearch.h
        GraphLibrary/SimpleAlgorithms/BiconnectedComponentSearch.h
        GraphLibrary/SimpleAlgorithms/BridgeSearch.h
        GraphLibrary/SimpleAlgorithms/TopologicalSort.h
        GraphLibrary/SimpleAlgorithms/MinSpanTree.h

        GraphLibrary/Searches/AStar.h
        GraphLibrary/Searches/FordBellman.h
        GraphLibrary/Searches/WidthFastSearch.h
        GraphLibrary/Searches/Dijkstra.h

        GraphLibrary/SimpleAlgorithms/NegativeCycleSearch.h

        GraphLibrary/GraphLibrary.h
        GraphLibrary/Definitions.h)
add_executable(GraphAlgorithms ${SOURCE_FILES})