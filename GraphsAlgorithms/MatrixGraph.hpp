//
//  MatrixGraph.hpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/15/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef MatrixGraph_hpp
#define MatrixGraph_hpp

#include <stdio.h>
#include <set>
#include "GraphLibrary/Graph.hpp"

class MatrixGraph : public GraphLibrary::BaseGraph
{
private:
    int n,m;
    std::set<std::pair<int, int>> blockedCells;

private:
    bool checkCell(pair<int, int>);
    pair<int, int> cellForVertexNumber(GraphLibrary::vertex);
    GraphLibrary::vertex vertexNumberForCell(pair<int,int>);
    
public:
    MatrixGraph(int, int, const vector<pair<int, int>>&);
    vector<GraphLibrary::Edge> edgesForVertex(GraphLibrary::vertex);
    
    bool iteratorBased();
    
    int numberOfVertexes();
    int numberOfEdges();
};


#endif /* MatrixGraph_hpp */
