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

using namespace std;

class Graph
{
private:
    int n;
    int m;
    vector<vector<EdgeTo>> matrix;
    vector<int> iterators;
    vector<Edge> edges;
    
public:
    Graph(int, const vector<Edge>&);
    Graph(int);
    
    vector<Edge> allEdges();
    bool hasNextEdgeForVertex(vertex);
    vector<EdgeTo> edgesForVertex(vertex);
    Edge nextEdgeForVertex(vertex);
    void resetIteratorForVertex(vertex);
    void addEdge(const Edge&);
    int numberOfVertexes();
    int numberOfEdges();
    
};

#endif /* Graph_hpp */
