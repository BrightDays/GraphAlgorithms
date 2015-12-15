//
// Created by Eugene Marchukevich on 12/16/15.
//

#ifndef TEST_MATRIXGRAPH_H
#define TEST_MATRIXGRAPH_H



#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include "GraphLibrary/Definitions.h"

using namespace std;

class MatrixGraph
{
private:
    int n,m;
    std::set<std::pair<int, int>> blockedCells;

private:
    bool checkCell(pair<int, int>);
    pair<int, int> cellForVertexNumber(GraphLibrary::vertex);
    GraphLibrary::vertex vertexNumberForCell(pair<int,int>);

public:
    MatrixGraph(int, int, vector<pair<int, int> >&);
    vector<GraphLibrary::Edge> edgesForVertex(GraphLibrary::vertex);

    bool iteratorBased();
    int numberOfVertexes();
    int numberOfEdges();
};


#endif //TEST_MATRIXGRAPH_H
