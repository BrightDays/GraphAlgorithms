//
// Created by Eugene Marchukevich on 5/15/16.
//

#ifndef GRAPHALGORITHMS_TOPOLOGICALSORT_H
#define GRAPHALGORITHMS_TOPOLOGICALSORT_H


#include <stdio.h>
#include <vector>
#include <math.h>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{
    template <class G>
    class TopologicalSort
    {
        CREATE_CHECK_METHOD_PARAMS(beginForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(endForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(edgesForVertex, G);

    private:
        G *graph;
        vector<bool> used;
        vector<vertex> sortedVertexes;
        void dfs(vertex);

    public:
        TopologicalSort(const G&);
        void sort();
        vector<vertex> getSortedVertexes();
        void setGraph(const G&);
    };

    template <class G>
    TopologicalSort<G> :: TopologicalSort(const G &g)
    {
        graph = (G*)&g;
        int n = graph->numberOfVertexes();
        used.resize(n);
    }


    template <class G>
    void TopologicalSort<G> :: dfs(vertex v)
    {
        CREATE_METHOD_CALLER(vector<Edge>::iterator, beginForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, endForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>, edgesForVertex, graph);

        used[v] = true;

        vector<Edge> :: iterator itBegin;
        vector<Edge> :: iterator itEnd;
        vector<Edge> currentEdges;
        if (graph->iteratorBased()) {
            itBegin = callMethod_beginForVertex(v);
            itEnd = callMethod_endForVertex(v);
        } else {
            currentEdges = callMethod_edgesForVertex(v);
            itBegin = currentEdges.begin();
            itEnd = currentEdges.end();
        }
        for(vector<Edge> :: iterator it = itBegin; it != itEnd; it++)  {
            Edge edge = *it;
            int to = edge.finish;
            if (!used[to]) {
                dfs(to);
            }
        }
        sortedVertexes.push_back(v);
    }


    template <class G>
    void TopologicalSort<G> :: sort()
    {
        int n = graph->numberOfVertexes();
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }
        reverse(sortedVertexes.begin(), sortedVertexes.end());
    }


    template <class G>
    vector<vertex> TopologicalSort<G> ::getSortedVertexes()
    {
        return sortedVertexes;
    }


    template <class G>
    void TopologicalSort<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
        int n = graph->numberOfVertexes();
        used.clear();
        sortedVertexes.clear();
        used.resize(n);
    }
}

#endif //GRAPHALGORITHMS_TOPOLOGICALSORT_H
