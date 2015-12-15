//
//  Graph.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "Graph.hpp"
#include <vector>

using namespace std;

namespace GraphLibrary
{

    Graph :: Graph(int _n)
    {
        n = _n;
        m = 0;
        matrix.resize(n);
    }

    Graph :: Graph(int _n, const vector<Edge> &_edges)
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

    vector<Edge> :: iterator Graph :: beginForVertex(vertex v)
    {
        return matrix[v].begin();
    }
    vector<Edge> :: iterator Graph :: endForVertex(vertex v)
    {
        return matrix[v].end();
    }

    vector<Edge> :: iterator Graph :: begin()
    {
        return edges.begin();
    }

    vector<Edge> :: iterator Graph :: end()
    {
        return edges.end();
    }


    void Graph :: addEdge(const Edge&edge)
    {
        edges.push_back(edge);
        matrix[edge.start].push_back(edge);
    }

    int Graph :: numberOfVertexes()
    {
        return n;
    }
    int Graph :: numberOfEdges()
    {
        return m;
    }
    bool Graph :: iteratorBased()
    {
        return true;
    }
}

