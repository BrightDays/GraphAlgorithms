//
// Created by Eugene Marchukevich on 12/16/15.
//

#ifndef GRAPHALGORITHMS_WIDTHFASTSEARCH_H
#define GRAPHALGORITHMS_WIDTHFASTSEARCH_H


#include <stdio.h>
#include <vector>
#include <queue>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{
    template <class G>
    class WidthFastSearch
    {
        CREATE_CHECK_METHOD_PARAMS(beginForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(endForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(edgesForVertex, G);

    private:
        vertex start, finish;
        vector<long long> distance;
        vector<vertex> ancestors;
        queue<vertex> q;
        G *graph;

    public:
        WidthFastSearch(vertex, vertex, const G&);

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
    WidthFastSearch<G> :: WidthFastSearch(vertex _start, vertex _finish, const G &g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
        int n = graph->numberOfVertexes();
        ancestors.resize(n);
        for(int i = 0; i < graph->numberOfVertexes(); i++)
        {
            distance.push_back(MAX_DISTANCE);
        }
    }

    template <class G>
    void WidthFastSearch<G> :: search()
    {
        CREATE_METHOD_CALLER(vector<Edge>::iterator, beginForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, endForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>, edgesForVertex, graph);

        q.push(start);
        distance[start] = 0;
        ancestors[start] = -1;
        while (!q.empty())
        {
            vertex v = q.front();
            q.pop();
            vector<Edge> :: iterator itBegin;
            vector<Edge> :: iterator itEnd;
            vector<Edge> currentEdges;
            if (graph->iteratorBased())
            {
                itBegin = callMethod_beginForVertex(v);
                itEnd = callMethod_endForVertex(v);
            } else
            {
                currentEdges = callMethod_edgesForVertex(v);
                itBegin = currentEdges.begin();
                itEnd = currentEdges.end();
            }
            for(vector<Edge> :: iterator it = itBegin; it!=itEnd; it++)
            {
                Edge edge = *it;
                if (distance[edge.finish] > distance[v] + edge.weight)
                {
                    distance[edge.finish] = distance[v] + edge.weight;
                    q.push(edge.finish);
                    ancestors[edge.finish] = v;
                }
            }
        }
    }


    template <class G>
    long long WidthFastSearch<G> :: distanceTo(vertex v)
    {
        if (distance[v] == MAX_DISTANCE)
            return -1;
        return distance[v];
    }

    template <class G>
    vector<vertex> WidthFastSearch<G> :: wayToVertex(vertex v)
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
    vector<long long> WidthFastSearch<G> :: allDistances()
    {
        return distance;
    }


    template <class G>
    void WidthFastSearch<G> :: setNewData(int _start, int _finish, const G &g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
    }

    template <class G>
    void WidthFastSearch<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
        distance.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++)
        {
            distance.push_back(MAX_DISTANCE);
        }

    }

    template <class G>
    void WidthFastSearch<G> :: setStart(vertex s)
    {
        start = s;
    }

    template <class G>
    void WidthFastSearch<G> :: setFinish(vertex f)
    {
        finish = f;
    }
}


#endif //GRAPHALGORITHMS_WIDTHFASTSEARCH_H
