//
//  Dijkstra.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "Dijkstra.hpp"

namespace GraphLibrary
{
    Dijkstra :: Dijkstra(vertex _start, vertex _finish, const BaseGraph &g)
    {
        start = _start;
        finish = _finish;
        graph = (BaseGraph*)&g;
        ancestors.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++)
        {
            distance.push_back(MAX_DISTANCE);
        }
    }


    void Dijkstra :: search()
    {
        set < pair<long long,int> > q;
        distance[start] = 0;
        q.insert (make_pair (0, start));
        while (!q.empty())
        {
            int v = q.begin()->second;
            q.erase (q.begin());
            vector<Edge> :: iterator itBegin;
            vector<Edge> :: iterator itEnd;
            vector<Edge> currentEdges;
            if (graph->iteratorBased())
            {
                itBegin = graph->beginForVertex(v);
                itEnd = graph->endForVertex(v);
            } else
            {
                currentEdges = graph->edgesForVertex(v);
                itBegin = currentEdges.begin();
                itEnd = currentEdges.end();
            }
            
            for(vector<Edge> :: iterator it = itBegin; it!=itEnd; it++)
            {
                Edge edge = *it;
                int to = edge.finish;
                long long length = edge.weight;
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


    void Dijkstra :: setNewData(int _start, int _finish, const BaseGraph &g)
    {
        start = _start;
        finish = _finish;
        graph = (BaseGraph*)&g;
    }

    void Dijkstra :: setGraph(const BaseGraph &g)
    {
        graph = (BaseGraph*)&g;
        distance.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++)
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
}