//
// Created by Eugene Marchukevich on 3/18/16.
//

#ifndef GRAPHALGORITHMS_BICONNECTEDCOMPONENTSEARCH_H
#define GRAPHALGORITHMS_BICONNECTEDCOMPONENTSEARCH_H


#include <stdio.h>
#include <vector>
#include <math.h>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{
    template <class G>
    class BiconnectedComponentSearch
    {
        CREATE_CHECK_METHOD_PARAMS(beginForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(endForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(edgesForVertex, G);

    private:
        vector<bool> used;
        int timer;
        vector<int> timeIn;
        vector<int> fup;
        G *graph;
        vector<vertex> biconnectedComponents;
        void dfs (vertex, vertex);

    public:
        BiconnectedComponentSearch(const G&);
        void search();
        vector<vertex> getBiconnectedComponents();
        void setGraph(const G&);
        void setNewData(const G&);
    };

    template <class G>
    BiconnectedComponentSearch<G> :: BiconnectedComponentSearch(const G &g)
    {
        graph = (G*)&g;
        int n = graph->numberOfVertexes();
        timer = 0;
        timeIn.resize(n);
        fup.resize(n);
        for(int i = 0; i < n; i++)  {
            used.push_back(false);
        }
    }


    template <class G>
    void BiconnectedComponentSearch<G> :: dfs (vertex v, vertex p)
    {
        CREATE_METHOD_CALLER(vector<Edge>::iterator, beginForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, endForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>, edgesForVertex, graph);

        used[v] = true;
        timeIn[v] = fup[v] = timer++;
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
        int children = 0;
        for(vector<Edge> :: iterator it = itBegin; it != itEnd; it++)  {
            Edge edge = *it;
            int to = edge.finish;
            if (to == p) {
                continue;
            }
            if (used[to]) {
                fup[v] = min(fup[v], timeIn[to]);
            } else {
                dfs (to, v);
                fup[v] = min (fup[v], fup[to]);
                if (fup[to] >= timeIn[v] && p != -1) {
                    biconnectedComponents.push_back(v);
                }
                ++children;
            }
        }
        if (p == -1 && children > 1) {
            biconnectedComponents.push_back(v);
        }
    }

    template <class G>
    void BiconnectedComponentSearch<G> :: search()
    {
        dfs(0, -1);
    }


    template <class G>
    vector<vertex> BiconnectedComponentSearch<G> ::getBiconnectedComponents()
    {
        return biconnectedComponents;
    }

    template <class G>
    void BiconnectedComponentSearch<G> :: setNewData(const G &g)
    {
        graph = (G*)&g;
    }

    template <class G>
    void BiconnectedComponentSearch<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
        int n = graph->numberOfVertexes();
        timeIn.clear();
        fup.clear();
        used.clear();
        timer = 0;
        timeIn.resize(n);
        fup.resize(n);
        for(int i = 0; i < n; i++)  {
            used.push_back(false);
        }
    }
}

#endif //GRAPHALGORITHMS_BICONNECTEDCOMPONENTSEARCH_H
