//
// Created by Eugene Marchukevich on 12/16/15.
//

#ifndef GRAPHALGORITHMS_GRAPH_H
#define GRAPHALGORITHMS_GRAPH_H

#include "Definitions.h"
#include <vector>

using namespace std;

namespace GraphLibrary
{
    class Graph
    {
    private:
        int n;
        int m;
        vector<vector<Edge>> matrix;
        vector<Edge> edges;

    public:
        Graph(int, const vector<Edge>&);
        Graph(int);
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


#endif //GRAPHALGORITHMS_GRAPH_H
