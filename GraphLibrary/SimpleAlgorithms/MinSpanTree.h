//
// Created by Eugene Marchukevich on 5/15/16.
//

#ifndef GRAPHALGORITHMS_MINSPANTREE_H
#define GRAPHALGORITHMS_MINSPANTREE_H


#include <stdio.h>
#include <vector>
#include <math.h>
#include <cstdlib>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{
    template <class G>
    class MinSpanTree
    {

        CREATE_CHECK_METHOD_NO_PARAMS(begin, G);
        CREATE_CHECK_METHOD_NO_PARAMS(end, G);

    private:
        G *graph;
        vector<Edge> spanTree;
        long long cost;
        vector<int> p;
        int dsuGet(vertex);
        void dsuUnite(vertex, vertex);

    public:
        MinSpanTree(const G&);
        void build();
        vector<Edge> getSpanTreeEdges();
        long long getCost();
        void setGraph(const G&);
    };

    template <class G>
    MinSpanTree<G> :: MinSpanTree(const G &g)
    {
        graph = (G*)&g;
        cost = 0;
        int n = graph->numberOfVertexes();
        p.resize(n);
    }


    bool comparator(Edge a, Edge b)  {
        return (a.weight < b.weight);
    }

    template <class G>
    void MinSpanTree<G> :: build() {
        CREATE_METHOD_CALLER(vector<Edge> :: iterator, begin, graph);
        CREATE_METHOD_CALLER(vector<Edge> :: iterator, end, graph);

        sort(callMethod_begin(), callMethod_end(), comparator);
        for (int i = 0; i < graph->numberOfVertexes(); i++) {
            p[i] = i;
        }
        for (vector<Edge> :: iterator it = callMethod_begin(); it != callMethod_end(); it++) {
            Edge edge = *it;
            vertex a = edge.start, b = edge.finish;
            long long l = edge.weight;
            if (dsuGet(a) != dsuGet(b)) {
                cost += l;
                spanTree.push_back(edge);
                dsuUnite(a, b);
            }
        }
    }
    template <class G>
    int MinSpanTree<G> :: dsuGet(vertex v) {
        return (v == p[v]) ? v : (p[v] = dsuGet(p[v]));
    }

    template <class G>
    void MinSpanTree<G> :: dsuUnite (int a, int b) {
        a = dsuGet(a);
        b = dsuGet(b);
        if (rand() & 1) {
            swap(a, b);
        }
        if (a != b) {
            p[a] = b;
        }
    }


    template <class G>
    vector<Edge> MinSpanTree<G> ::getSpanTreeEdges()
    {
        return spanTree;
    }

    template <class G>
    long long MinSpanTree<G> ::getCost()
    {
        return cost;
    }


    template <class G>
    void MinSpanTree<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
        cost = 0;
        p.clear();
        spanTree.clear();
        int n = graph->numberOfVertexes();
        p.resize(n);
    }
}

#endif //GRAPHALGORITHMS_MINSPANTREE_H
