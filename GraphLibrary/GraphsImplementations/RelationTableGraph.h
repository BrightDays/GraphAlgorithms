//
// Created by Eugene Marchukevich on 5/17/16.
//

#ifndef GRAPHALGORITHMS_RELATIONTABLEGRAPH_H
#define GRAPHALGORITHMS_RELATIONTABLEGRAPH_H


#include "../Definitions.h"
#include <vector>

using namespace std;

namespace GraphLibrary
{
    class VertexData {
        public:
        int value;
    };

    template <class R>
    class RelationTableGraph
    {
    private:
        int n;
        int m;
        vector<vector<Edge>> matrix;
        vector<Edge> edges;
        vector<VertexData> data;
        bool oriented;
        R *reader;

    public:
        RelationTableGraph(int, bool);
        RelationTableGraph(bool, const R&);

        void addLine(vertex, vertex);
        void addLine(vertex, vertex, VertexData);
        void addLine(vertex, vector<vertex>, VertexData);

        void buildGraph();

        vector<Edge> :: iterator beginForVertex(vertex);
        vector<Edge> :: iterator endForVertex(vertex);

        vector<Edge> :: iterator begin();
        vector<Edge> :: iterator end();

        VertexData dataForVertex(vertex);

        int numberOfVertexes();
        int numberOfEdges();
        bool iteratorBased();
    };

    template <class R>
    RelationTableGraph<R> :: RelationTableGraph(int count, bool _oriented)
    {
        n = count;
        m = 0;
        oriented = _oriented;
        matrix.resize(n);
        data.resize(n);
    }

    template <class R>
    RelationTableGraph<R> :: RelationTableGraph(bool _oriented, const R&_reader)
    {
        m = 0;
        oriented = _oriented;
        reader = (R*)&_reader;
    }

    template <class R>
    void RelationTableGraph<R> :: addLine(vertex temp, vertex anc)
    {
        Edge edge(anc, temp);
        edges.push_back(edge);
        matrix[edge.start].push_back(edge);
        if (!oriented) {
            matrix[edge.finish].push_back(Edge(edge.finish, edge.start, edge.weight));
        }
    }

    template <class R>
    void RelationTableGraph<R> :: addLine(vertex temp, vertex anc, VertexData vertexData)
    {
        data[temp] = vertexData;
        addLine(temp, anc);
    }

    template <class R>
    void RelationTableGraph<R> :: addLine(vertex temp, vector<vertex> ancestors, VertexData vertexData)
    {
        data[temp] = vertexData;
        for(int i = 0; i < ancestors.size(); i++) {
            vertex anc = ancestors[i];
            addLine(temp, anc);
        }
    }

    template <class R>
    void RelationTableGraph<R> ::buildGraph()
    {
        int n = reader->numberOfVertexes();
        matrix.resize(n);
        data.resize(n);
        int count = reader->countOfLines();
        for(int i = 0; i < count; i++) {
            vertex temp = reader->currentVertex();
            vertex ancestor = reader->ancestorVertex();
            VertexData data = reader->currentVertexData();
            addLine(temp, ancestor, data);
        }
    }

    template <class R>
    VertexData RelationTableGraph<R> :: dataForVertex(vertex v)
    {
        return data[v];
    }

    template <class R>
    vector<Edge> :: iterator RelationTableGraph<R> :: beginForVertex(vertex v)
    {
        return matrix[v].begin();
    }

    template <class R>
    vector<Edge> :: iterator RelationTableGraph<R> :: endForVertex(vertex v)
    {
        return matrix[v].end();
    }

    template <class R>
    vector<Edge> :: iterator RelationTableGraph<R> :: begin()
    {
        return edges.begin();
    }

    template <class R>
    vector<Edge> :: iterator RelationTableGraph<R> :: end()
    {
        return edges.end();
    }

    template <class R>
    int RelationTableGraph<R> :: numberOfVertexes()
    {
        return n;
    }

    template <class R>
    int RelationTableGraph<R> :: numberOfEdges()
    {
        return m;
    }

    template <class R>
    bool RelationTableGraph<R> :: iteratorBased()
    {
        return true;
    }
}

#endif //GRAPHALGORITHMS_RELATIONTABLEGRAPH_H
