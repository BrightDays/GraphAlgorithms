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

    };

    class RelationTableGraph
    {
    private:
        int n;
        int m;
        vector<vector<Edge>> matrix;
        vector<Edge> edges;
        vector<VertexData> data;
        bool oriented;

    public:
        RelationTableGraph(int, bool);


        void addLine(vertex, vertex);
        void addLine(vertex, vertex, VertexData);
        void addLine(vertex, vector<vertex>, VertexData);

        vector<Edge> :: iterator beginForVertex(vertex);
        vector<Edge> :: iterator endForVertex(vertex);

        vector<Edge> :: iterator begin();
        vector<Edge> :: iterator end();

        VertexData dataForVertex(vertex);

        int numberOfVertexes();
        int numberOfEdges();
        bool iteratorBased();
    };
}

#endif //GRAPHALGORITHMS_RELATIONTABLEGRAPH_H
