//
// Created by Eugene Marchukevich on 5/15/16.
//

#ifndef GRAPHALGORITHMS_STRONGCONNECTEDCOMPONENTSSEARCH_H
#define GRAPHALGORITHMS_STRONGCONNECTEDCOMPONENTSSEARCH_H


#include <stdio.h>
#include <vector>
#include <math.h>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{
    template <class G>
    class StrongConnectedComponentsSearch
    {
        CREATE_CHECK_METHOD_PARAMS(beginForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(endForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(edgesForVertex, G);

    private:
        G *graph;
        G *graphReversed;
        vector<bool> used;
        vector<int> order;
        vector<vertex> component;
        vector<vector<vertex>> components;
        void dfs1(vertex);
        void dfs2(vertex);

    public:
        StrongConnectedComponentsSearch(const G&, const G&);
        void search();
        vector<vector<vertex>> getComponents();
        void setGraph(const G&, const G&);
    };

    template <class G>
    StrongConnectedComponentsSearch<G> :: StrongConnectedComponentsSearch(const G &g, const G&gRev)
    {
        graph = (G*)&g;
        graphReversed = (G*)&gRev;
        int n = graph->numberOfVertexes();
        used.resize(n);
    }


    template <class G>
    void StrongConnectedComponentsSearch<G> :: dfs1 (vertex v)
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
                dfs1(to);
            }
            order.push_back(v);
        }
    }

    template <class G>
    void StrongConnectedComponentsSearch<G> :: dfs2 (vertex v)
    {
        CREATE_METHOD_CALLER(vector<Edge>::iterator, beginForVertex, graphReversed);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, endForVertex, graphReversed);
        CREATE_METHOD_CALLER(vector<Edge>, edgesForVertex, graphReversed);

        used[v] = true;
        component.push_back(v);

        vector<Edge> :: iterator itBegin;
        vector<Edge> :: iterator itEnd;
        vector<Edge> currentEdges;
        if (graphReversed->iteratorBased()) {
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
                dfs2(to);
            }
        }
    }

    template <class G>
    void StrongConnectedComponentsSearch<G> :: search()
    {
        int n = graph->numberOfVertexes();
        used.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs1(i);
            }
        }
        used.assign (n, false);
        for (int i = 0; i < n; i++) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2(v);
                components.push_back(component);
                component.clear();
            }
        }
    }


    template <class G>
    vector<vector<vertex>> StrongConnectedComponentsSearch<G> ::getComponents()
    {
        return components;
    }


    template <class G>
    void StrongConnectedComponentsSearch<G> :: setGraph(const G &g, const G &gRev)
    {
        graph = (G*)&g;
        graphReversed = (G*)&gRev;
        int n = graph->numberOfVertexes();
        used.clear();
        component.clear();
        components.clear();
        order.clear();
        used.resize(n);
    }
}

#endif //GRAPHALGORITHMS_STRONGCONNECTEDCOMPONENTSSEARCH_H
