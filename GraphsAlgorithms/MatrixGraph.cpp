//
//  MatrixGraph.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/15/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "MatrixGraph.hpp"
#include <stdlib.h>

MatrixGraph::MatrixGraph(int _n, int _m, const vector<pair<int, int>>&blocked)
{
    n = _n;
    m = _m;
    vector<pair<int, int>> :: const_iterator it;
    for(it = blocked.begin(); it != blocked.end(); it++)
    {
        blockedCells.insert(*it);
    }
}


bool MatrixGraph::checkCell(pair<int, int> cell)
{
    if (cell.first < 0 || cell.first >= n || cell.second < 0 || cell.second >= m)
        return false;
    return blockedCells.find(cell) == blockedCells.end();
}

vector<GraphLibrary::Edge> MatrixGraph::edgesForVertex(GraphLibrary::vertex v)
{
    vector<GraphLibrary::Edge> edges;
    pair<int, int> cell = cellForVertexNumber(v);
    pair<int, int> newCell = cell;
    newCell.first --;
    if (checkCell(newCell))
        edges.push_back(GraphLibrary::Edge(v, vertexNumberForCell(newCell)));
    newCell = cell;
    newCell.first ++;
    if (checkCell(newCell))
        edges.push_back(GraphLibrary::Edge(v, vertexNumberForCell(newCell)));
    newCell = cell;
    newCell.second --;
    if (checkCell(newCell))
        edges.push_back(GraphLibrary::Edge(v, vertexNumberForCell(newCell)));
    newCell = cell;
    newCell.second ++;
    if (checkCell(newCell))
        edges.push_back(GraphLibrary::Edge(v, vertexNumberForCell(newCell)));
    newCell = cell;
    
    return edges;
}

GraphLibrary::vertex MatrixGraph::vertexNumberForCell(pair<int, int> cell)
{
    return cell.first * m + cell.second;
}

pair<int, int>MatrixGraph::cellForVertexNumber(GraphLibrary::vertex v)
{
    return make_pair(v / m, v % m);
}

bool MatrixGraph::iteratorBased()
{
    return false;
}

int MatrixGraph::numberOfEdges()
{
    return 0;
}

int MatrixGraph::numberOfVertexes()
{
    return n * m;
}
