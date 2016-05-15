//
// Created by Eugene Marchukevich on 5/15/16.
//

#ifndef GRAPHALGORITHMS_ORIENTEDGRAPH_H
#define GRAPHALGORITHMS_ORIENTEDGRAPH_H
#include "../Definitions.h"
#include <vector>

using namespace std;

namespace GraphLibrary
{
    class OrientedGraph
    {
    private:
        int n;
        int m;
        vector<vector<Edge>> matrix;
        vector<Edge> edges;
    public:
        OrientedGraph(int, const vector<Edge>&);
        OrientedGraph(int);
        void addEdge(const Edge&);

        vector<Edge> :: iterator beginForVertex(vertex);
        vector<Edge> :: iterator endForVertex(vertex);

        vector<Edge> :: iterator begin();
        vector<Edge> :: iterator end();

        int numberOfVertexes();
        int numberOfEdges();
        bool iteratorBased();
    };
}

#endif //GRAPHALGORITHMS_ORIENTEDGRAPH_H
