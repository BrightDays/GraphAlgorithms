//
// Created by Eugene Marchukevich on 12/16/15.
//

#ifndef GRAPHALGORITHMS_DIJKSTRA_H
#define GRAPHALGORITHMS_DIJKSTRA_H

#include <vector>
#include <set>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary
{


    template <class G>
    class Dijkstra
    {
        CREATE_CHECK_METHOD_PARAMS(beginForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(endForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(edgesForVertex, G);

    private:
        vertex start, finish;
        vector<vertex> ancestors;
        G *graph;
        vector<long long> distance;

    public:
        Dijkstra(vertex, vertex, const G & g);

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
    Dijkstra<G> :: Dijkstra(vertex _start, vertex _finish, const G &g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
        ancestors.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++) {
            distance.push_back(MAX_DISTANCE);
        }
    }


    template <class G>
    void Dijkstra<G> :: search()
    {

        CREATE_METHOD_CALLER(vector<Edge>::iterator, beginForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, endForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>, edgesForVertex, graph);

        set < pair<long long,int> > q;
        distance[start] = 0;
        q.insert (make_pair (0, start));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase (q.begin());
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

            for(vector<Edge> :: iterator it = itBegin; it!=itEnd; it++)  {
                Edge edge = *it;
                int to = edge.finish;
                long long length = edge.weight;
                if (distance[v] + length < distance[to]) {
                    q.erase (make_pair (distance[to], to));
                    distance[to] = distance[v] + length;
                    ancestors[to] = v;
                    q.insert (make_pair(distance[to], to));
                }
            }
        }
    }

    template <class G>
    long long Dijkstra<G> :: distanceTo(vertex v)
    {
        if (distance[v] == MAX_DISTANCE)
            return -1;
        return distance[v];
    }

    template <class G>
    vector<vertex> Dijkstra<G> :: wayToVertex(vertex v)
    {
        vector<vertex> way;
        if (distance[v] == MAX_DISTANCE) {
            return way;
        }

        for (vertex v = finish; v != -1; v = ancestors[v]) {
            way.push_back(v);
        }
        reverse(way.begin(), way.end());
        return way;
    }

    template <class G>
    vector<long long> Dijkstra<G> :: allDistances()
    {
        return distance;
    }


    template <class G>
    void Dijkstra<G> :: setNewData(int _start, int _finish, const G &g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
    }

    template <class G>
    void Dijkstra<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
        distance.resize(graph->numberOfVertexes());
        for(int i = 0; i < graph->numberOfVertexes(); i++) {
            distance.push_back(MAX_DISTANCE);
        }
    }

    template <class G>
    void Dijkstra<G> :: setStart(vertex s)
    {
        start = s;
    }

    template <class G>
    void Dijkstra<G> :: setFinish(vertex f)
    {
        finish = f;
    }
}




#endif //GRAPHALGORITHMS_DIJKSTRA_H
