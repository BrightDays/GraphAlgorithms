//
//  FordBellman.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/7/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "FordBellman.hpp"

namespace GraphLibrary
{

    FordBellman :: FordBellman(vertex _start, vertex _finish, const BaseGraph& g)
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

    void FordBellman :: search()
    {
        distance[start] = 0;
        while (true)
        {
            bool anyChanges = false;
            vector<Edge> :: iterator itBegin;
            vector<Edge> :: iterator itEnd;
            vector<Edge> currentEdges;
            if (graph->iteratorBased())
            {
                itBegin = graph->begin();
                itEnd = graph->end();
            } else
            {
                currentEdges = graph->allEdges();
                itBegin = currentEdges.begin();
                itEnd = currentEdges.end();
            }
            for (vector<Edge> :: iterator it = itBegin; it != itEnd;it++)
            {
                Edge edge = *it;
                if (distance[edge.start] < MAX_DISTANCE)
                {
                    if (distance[edge.finish] > distance[edge.start] + edge.weight)
                    {
                        distance[edge.finish] = distance[edge.start] + edge.weight;
                        ancestors[edge.finish] = edge.start;
                        anyChanges = true;
                    }
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


    void FordBellman :: setNewData(int _start, int _finish, const BaseGraph &g)
    {
        start = _start;
        finish = _finish;
        graph = (BaseGraph*)&g;
    }

    void FordBellman :: setGraph(const BaseGraph &g)
    {
        graph = (BaseGraph*)&g;
        distance.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++)
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
}
