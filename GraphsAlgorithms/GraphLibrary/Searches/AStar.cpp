//
//  AStar.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/14/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "AStar.hpp"
#include <set>

namespace GraphLibrary
{
    
    AStar :: AStar (vertex _start, vertex _finish, long long(*_distanceFunction)(vertex, vertex), const BaseGraph & g)
    {
        start = _start;
        finish = _finish;
        graph = (Graph*)&g;
        distanceFunction = _distanceFunction;
    }
    
    void AStar::search()
    {
        set < pair<long long, int> > q;
        q.insert (make_pair(distanceFunction(start, finish), start));
        distance[start] = 0;
        while (!q.empty())
        {
            int v = q.begin()->second;
            long long d = distance[v];
            if (v == finish)
            {
                return;
            }
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
                auto iter = std::find_if(q.begin(), q.end(), [&to](const pair<int, int>& p) { return p.second == to;});
                if (distance.find(to) == distance.end() || d + length < distance[to])
                {
                    q.erase(*iter);
                    distance[to] = d + length;
                    q.insert(make_pair(d + length + distanceFunction(v, to), to));
                }
            }
        }
    }
    
    
    long long AStar :: distanceTo(vertex v)
    {
        if (distance.find(v) == distance.end())
            return -1;
        return distance[v];
    }
    
    vector<vertex> AStar :: wayToVertex(vertex v)
    {
        vector<vertex> way;
        return way;
    }
    
    vector<long long> AStar :: allDistances()
    {
        vector<long long> distance;
        return distance;
    }
    
    
    void AStar :: setNewData(int _start, int _finish, const BaseGraph &g)
    {
        start = _start;
        finish = _finish;
        graph = (BaseGraph*)&g;
    }
    
    void AStar :: setGraph(const BaseGraph &g)
    {
        graph = (BaseGraph*)&g;
    }
    
    void AStar :: setStart(vertex s)
    {
        start = s;
    }
    
    void AStar :: setFinish(vertex f)
    {
        finish = f;
    }
    
}