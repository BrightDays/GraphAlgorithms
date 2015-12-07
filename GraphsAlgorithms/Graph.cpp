//
//  Graph.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "Graph.hpp"
#include <vector>

using namespace std;


Graph :: Graph(int _n)
{
    n = _n;
    m = 0;
    matrix.resize(n);
    iterators.resize(n, 0);
}

Graph :: Graph(int _n, const vector<Edge> &_edges)
{
    n = _n;
    m = (int)_edges.size();
    edges = _edges;
    matrix.resize(n);
    iterators.resize(n, 0);
    for(int i = 0; i < edges.size(); i++)
    {
        Edge edge = _edges[i];
        matrix[edge.start].push_back(EdgeTo(edge.finish, edge.weight));
    }
}

vector<Edge> Graph :: allEdges()
{
    return edges;
}

void Graph :: addEdge(const Edge& edge)
{
    m++;
    matrix[edge.start].push_back(EdgeTo(edge.finish, edge.weight));
}


vector<EdgeTo> Graph :: edgesForVertex(vertex v)
{
    vector<EdgeTo> edges = matrix[v];
    return edges;
}

bool Graph :: hasNextEdgeForVertex(vertex v)
{
    bool hasNext =  matrix[v].size() - 1 > iterators[v];
    return hasNext;
}

Edge Graph :: nextEdgeForVertex(vertex v)
{
    EdgeTo edgeTo = matrix[v][iterators[v]];
    Edge edge = Edge(v, edgeTo);
    iterators[v]++;
    return edge;
}

void Graph :: resetIteratorForVertex(vertex v)
{
    iterators[v] = 0;
}

int Graph :: numberOfVertexes()
{
    return n;
}
int Graph :: numberOfEdges()
{
    return m;
}


