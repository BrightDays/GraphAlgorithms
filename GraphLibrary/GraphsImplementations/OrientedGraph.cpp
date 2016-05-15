//
// Created by Eugene Marchukevich on 5/15/16.
//

#include "OrientedGraph.h"
namespace GraphLibrary
{
    OrientedGraph :: OrientedGraph(int _n)
    {
        n = _n;
        m = 0;
        matrix.resize(n);
    }

    OrientedGraph :: OrientedGraph(int _n, const vector<Edge> &_edges)
    {
        n = _n;
        m = (int)_edges.size();
        edges = _edges;
        matrix.resize(n);
        for(int i = 0; i < edges.size(); i++)
        {
            Edge edge = _edges[i];
            matrix[edge.start].push_back(edge);
        }
    }

    vector<Edge> :: iterator OrientedGraph :: beginForVertex(vertex v)
    {
        return matrix[v].begin();
    }
    vector<Edge> :: iterator OrientedGraph :: endForVertex(vertex v)
    {
        return matrix[v].end();
    }

    vector<Edge> :: iterator OrientedGraph :: begin()
    {
        return edges.begin();
    }

    vector<Edge> :: iterator OrientedGraph :: end()
    {
        return edges.end();
    }


    void OrientedGraph :: addEdge(const Edge&edge)
    {
        edges.push_back(edge);
        matrix[edge.start].push_back(edge);
    }

    int OrientedGraph :: numberOfVertexes()
    {
        return n;
    }
    int OrientedGraph :: numberOfEdges()
    {
        return m;
    }
    bool OrientedGraph :: iteratorBased()
    {
        return true;
    }
}