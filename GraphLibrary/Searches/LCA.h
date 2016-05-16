//
// Created by Eugene Marchukevich on 5/16/16.
//

#ifndef GRAPHALGORITHMS_LCA_H
#define GRAPHALGORITHMS_LCA_H


#include <vector>
#include <set>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{


    template <class G>
    class LCA
    {
        CREATE_CHECK_METHOD_PARAMS(beginForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(endForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(edgesForVertex, G);

    private:
        G *graph;
        vector<int> tin, tout;
        int timer;
        vector<vector<vertex>> up;
        int l;
        void dfs(vertex, vertex);
        bool upper(vertex, vertex);

    public:
        LCA(const G & g);
        void search();
        void setGraph(const G&);
        vertex findLca(vertex, vertex);
    };

    template <class G>
    LCA<G> :: LCA(const G &g)
    {
        graph = (G*)&g;
        int n = graph->numberOfVertexes();
        tin.resize(n);
        tout.resize(n);
        up.resize(n);
        l = 1;
        while ((1<<l) <= n)  ++l;
        for (int i = 0; i < n; ++i) {
            up[i].resize(l + 1);
            for (int i = 0; i < n; ++i) {
                up[i].resize(l + 1);
            }
        }
    }

    template <class G>
    void LCA<G> :: dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        CREATE_METHOD_CALLER(vector<Edge>::iterator, beginForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, endForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>, edgesForVertex, graph);

        for (int i = 1; i <= l; ++i) {
            up[v][i] = up[up[v][i-1]][i-1];
        }

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

        for(vector<Edge> :: iterator it = itBegin; it != itEnd; it++) {
            Edge edge = *it;
            int to = edge.finish;
            if (to != p) {
                dfs (to, v);
            }
        }
        tout[v] = ++timer;
    }

    template <class G>
    bool LCA<G> :: upper(vertex a, vertex b) {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    }

    template <class G>
    vertex LCA<G> ::findLca(vertex a, vertex b){
        if (upper (a, b))  return a;
        if (upper (b, a))  return b;
        for (int i = l; i >= 0; --i) {
            if (!upper(up[a][i], b)) {
                a = up[a][i];
            }
        }
        return up[a][0];
    }



    template <class G>
    void LCA<G> :: search()
    {
        dfs(0, 0);
    }

    template <class G>
    void LCA<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
        tin.clear();
        tout.clear();
        up.clear();
        timer = 0;
        int n = graph->numberOfVertexes();
        tin.resize(n);
        tout.resize(n);
        up.resize(n);
        l = 1;
        while ((1<<l) <= n)  ++l;
        for (int i = 0; i < n; ++i) {
            up[i].resize(l + 1);
            for (int i = 0; i < n; ++i) {
                up[i].resize(l + 1);
            }
        }
    }

}


#endif //GRAPHALGORITHMS_LCA_H
