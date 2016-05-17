//
// Created by Eugene Marchukevich on 5/17/16.
//


#include "RelationTableGraph.h"


namespace GraphLibrary
{

    RelationTableGraph :: RelationTableGraph(int count, bool _oriented)
    {
        n = count;
        m = 0;
        oriented = _oriented;
        matrix.resize(n);
        data.resize(n);
    }

    void RelationTableGraph :: addLine(vertex temp, vertex anc)
    {
        Edge edge(anc, temp);
        edges.push_back(edge);
        matrix[edge.start].push_back(edge);
        if (!oriented) {
            matrix[edge.finish].push_back(Edge(edge.finish, edge.start, edge.weight));
        }
    }

    void RelationTableGraph :: addLine(vertex temp, vertex anc, VertexData vertexData)
    {
        data[temp] = vertexData;
        addLine(temp, anc);
    }

    void RelationTableGraph :: addLine(vertex temp, vector<vertex> ancestors, VertexData vertexData)
    {
        data[temp] = vertexData;
        for(int i = 0; i < ancestors.size(); i++) {
            vertex anc = ancestors[i];
            addLine(temp, anc);
        }
    }

    vector<Edge> :: iterator RelationTableGraph :: beginForVertex(vertex v)
    {
        return matrix[v].begin();
    }
    vector<Edge> :: iterator RelationTableGraph :: endForVertex(vertex v)
    {
        return matrix[v].end();
    }

    vector<Edge> :: iterator RelationTableGraph :: begin()
    {
        return edges.begin();
    }

    vector<Edge> :: iterator RelationTableGraph :: end()
    {
        return edges.end();
    }

    int RelationTableGraph :: numberOfVertexes()
    {
        return n;
    }
    int RelationTableGraph :: numberOfEdges()
    {
        return m;
    }
    bool RelationTableGraph :: iteratorBased()
    {
        return true;
    }
}
