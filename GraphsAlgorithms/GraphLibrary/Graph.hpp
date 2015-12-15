//
//  Graph.hpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include "Definitions.h"
#include "BaseGraph.h"

using namespace std;

namespace GraphLibrary
{
    class Graph : public BaseGraph
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
#endif /* Graph_hpp */
