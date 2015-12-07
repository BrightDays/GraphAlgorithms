//
//  Dijkstra.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "Dijkstra.hpp"



Dijkstra :: Dijkstra(int _start, int _finish, const Graph& g)
{
    start = _start;
    finish = _finish;
    graph = g;
    for(int i = 0; i < graph.numberOfVertexes(); i++)
    {
        distance.push_back(MAX_DISTANCE);
    }
}

void Dijkstra :: search()
{
    distance[start] = 0;
    set < pair<int,int> > q;
    q.insert (make_pair (distance[start], start));
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase (q.begin());
        vector<EdgeTo> edges = graph.getEdgesForVertex(v);
        for (int i = 0; i < edges.size(); i++)
        {
            int to = graph[v][i].finish;
            long long length = graph[v][i].weight;
            if (distance[v] + length < distance[to])
            {
                q.erase (make_pair (distance[to], to));
                distance[to] = distance[v] + length;
                ancestors[to] = v;
                q.insert (make_pair(distance[to], to));
            }
        }
    }
}


long long Dijkstra :: distanceTo(vertex v)
{
    if (distance[v] == MAX_DISTANCE)
        return -1;
    return distance[v];
}

vector<vertex> Dijkstra :: wayToVertex(vertex v)
{
    vector<vertex> way;
    if (distance[v] == MAX_DISTANCE)
        return way;
    
    for (vertex v = finish; v != -1; v = ancestors[v])
        way.push_back(v);
    reverse(way.begin(), way.end());
    return way;
}

vector<long long> Dijkstra :: allDistances()
{
    return distance;
}


void Dijkstra :: setNewData(int _start, int _finish, const Graph &g)
{
    start = _start;
    finish = _finish;
    graph = g;
}

void Dijkstra :: setGraph(const Graph &g)
{
    graph = g;
    distance.resize(graph.numberOfVertexes());
    for(int i = 0; i < graph.numberOfVertexes(); i++)
    {
        distance.push_back(MAX_DISTANCE);
    }
}

void Dijkstra :: setStart(vertex s)
{
    start = s;
}

void Dijkstra :: setFinish(vertex f)
{
    finish = f;
}
