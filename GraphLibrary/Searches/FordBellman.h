//
// Created by Eugene Marchukevich on 12/16/15.
//

#ifndef GRAPHALGORITHMS_FORDBELLMAN_H
#define GRAPHALGORITHMS_FORDBELLMAN_H

#include <iostream>
#include <vector>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{
    template <class G>
    class FordBellman
    {
        CREATE_CHECK_METHOD_NO_PARAMS(begin, G);
        CREATE_CHECK_METHOD_NO_PARAMS(end, G);
        CREATE_CHECK_METHOD_NO_PARAMS(allEdges, G);

    private:
        vertex start, finish;
        vector<long long> distance;
        vector<vertex> ancestors;
        G *graph;

    public:
        FordBellman(vertex, vertex, const G&);

        void search();
        long long distanceTo(vertex);
        vector<vertex> wayToVertex(vertex);
        vector<long long> allDistances();
        void setGraph(const G&);
        void setStart(vertex);
        void setFinish(vertex);
        void setNewData(int, int, const G&);
    };

    template <class G>
    FordBellman<G> :: FordBellman(vertex _start, vertex _finish, const G& g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
        ancestors.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++)
        {
            distance.push_back(MAX_DISTANCE);
        }
    }

    template <class G>
    void FordBellman<G> :: search()
    {
        CREATE_METHOD_CALLER(vector<Edge>::iterator, begin, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, end, graph);
        CREATE_METHOD_CALLER(vector<Edge>, allEdges, graph);

        distance[start] = 0;
        while (true)
        {
            bool anyChanges = false;
            vector<Edge> :: iterator itBegin;
            vector<Edge> :: iterator itEnd;
            vector<Edge> currentEdges;
            if (graph->iteratorBased())
            {
                itBegin = callMethod_begin();
                itEnd = callMethod_end();
            } else
            {
                currentEdges = callMethod_allEdges();
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

    template <class G>
    long long FordBellman<G> :: distanceTo(vertex v)
    {
        if (distance[v] == MAX_DISTANCE)
            return -1;
        return distance[v];
    }
    template <class G>
    vector<vertex> FordBellman<G> :: wayToVertex(vertex v)
    {
        vector<vertex> way;
        if (distance[v] == MAX_DISTANCE)
            return way;

        for (vertex v = finish; v != -1; v = ancestors[v])
            way.push_back(v);
        reverse(way.begin(), way.end());
        return way;
    }
    template <class G>
    vector<long long> FordBellman<G> :: allDistances()
    {
        return distance;
    }

    template <class G>
    void FordBellman<G> :: setNewData(int _start, int _finish, const G &g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
    }
    template <class G>
    void FordBellman<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
        distance.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++)
        {
            distance.push_back(MAX_DISTANCE);
        }

    }
    template <class G>
    void FordBellman<G> :: setStart(vertex s)
    {
        start = s;
    }
    template <class G>
    void FordBellman<G> :: setFinish(vertex f)
    {
        finish = f;
    }
}



#endif //GRAPHALGORITHMS_FORDBELLMAN_H
