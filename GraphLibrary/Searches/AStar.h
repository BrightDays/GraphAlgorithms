//
// Created by Eugene Marchukevich on 12/16/15.
//

#ifndef TEST_ASTAR_H
#define TEST_ASTAR_H

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

namespace GraphLibrary
{

    template <class G>
    class AStar
    {

        CREATE_CHECK_METHOD_PARAMS(beginForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(endForVertex, G);
        CREATE_CHECK_METHOD_PARAMS(edgesForVertex, G);

    private:
        vertex start, finish;
        G *graph;
        long long(*distanceFunction)(vertex, vertex);
        map<int, long long> distance;

    public:
        AStar(vertex, vertex, long long(*)(vertex, vertex),const G& g);

        void search();
        long long distanceTo(vertex);
        vector<vertex> wayToVertex(vertex);
        vector<long long> allDistances();
        void setGraph(const G&);
        void setStart(vertex);
        void setFinish(vertex);
        void setNewData(int, int, const G&);
    };

    template<class G> AStar<G> :: AStar (vertex _start, vertex _finish, long long(*_distanceFunction)(vertex, vertex), const G & g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
        distanceFunction = _distanceFunction;
    }

    template<class G> void AStar<G>::search()
    {

        CREATE_METHOD_CALLER(vector<Edge>::iterator, beginForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, endForVertex, graph);
        CREATE_METHOD_CALLER(vector<Edge>, edgesForVertex, graph);

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


    template<class G> long long AStar<G> :: distanceTo(vertex v)
    {
        if (distance.find(v) == distance.end())
            return -1;
        return distance[v];
    }

    template<class G> vector<vertex> AStar<G> :: wayToVertex(vertex v)
    {
        vector<vertex> way;
        return way;
    }

    template<class G> vector<long long> AStar<G> :: allDistances()
    {
        vector<long long> distance;
        return distance;
    }


    template<class G> void AStar<G> :: setNewData(int _start, int _finish, const G &g)
    {
        start = _start;
        finish = _finish;
        graph = (G*)&g;
    }

    template<class G> void AStar<G> :: setGraph(const G &g)
    {
        graph = (G*)&g;
    }

    template<class G> void AStar<G> :: setStart(vertex s)
    {
        start = s;
    }

    template<class G> void AStar<G> :: setFinish(vertex f)
    {
        finish = f;
    }
}


#endif //TEST_ASTAR_H
