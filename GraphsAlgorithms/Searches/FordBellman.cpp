//
//  FordBellman.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/7/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "FordBellman.hpp"

FordBellman :: FordBellman(int _start, int _finish, const Graph& g) : graph(g)
{
    start = _start;
    finish = _finish;
    ancestors.resize(graph.numberOfVertexes());
    for(int i = 0; i < graph.numberOfVertexes(); i++)
    {
        distance.push_back(MAX_DISTANCE);
    }
}

void FordBellman :: search()
{
    distance[start] = 0;
    while (true)
    {
        bool anyChanges = false;
        vector<Edge> edges = graph.allEdges();
        for (int j = 0; j < edges.size(); j++)
            if (distance[edges[j].start] < MAX_DISTANCE)
            {
                if (distance[edges[j].finish] > distance[edges[j].start] + edges[j].weight)
                {
                    distance[edges[j].finish] = distance[edges[j].start] + edges[j].weight;
                    ancestors[edges[j].finish] = edges[j].start;
                    anyChanges = true;
                }
            }
        if (!anyChanges)
            break;
    }
}


long long FordBellman :: distanceTo(vertex v)
{
    if (distance[v] == MAX_DISTANCE)
        return -1;
    return distance[v];
}

vector<vertex> FordBellman :: wayToVertex(vertex v)
{
    vector<vertex> way;
    if (distance[v] == MAX_DISTANCE)
        return way;
    
    for (vertex v = finish; v != -1; v = ancestors[v])
        way.push_back(v);
    reverse(way.begin(), way.end());
    return way;
}

vector<long long> FordBellman :: allDistances()
{
    return distance;
}


void FordBellman :: setNewData(int _start, int _finish, const Graph &g)
{
    start = _start;
    finish = _finish;
    graph = g;
}

void FordBellman :: setGraph(const Graph &g)
{
    graph = g;
    distance.resize(graph.numberOfVertexes());
    for(int i = 0; i < graph.numberOfVertexes(); i++)
    {
        distance.push_back(MAX_DISTANCE);
    }
    
}

void FordBellman :: setStart(vertex s)
{
    start = s;
}

void FordBellman :: setFinish(vertex f)
{
    finish = f;
}
