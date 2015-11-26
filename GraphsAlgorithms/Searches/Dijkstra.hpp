//
//  Dijkstra.hpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef Dijkstra_hpp
#define Dijkstra_hpp

#include <stdio.h>
#include "Graph.hpp"
#include <set>
#include "Search.h"
#include "Definitions.h"

using namespace std;

class Dijkstra : virtual public Search
{
private:
    vertex start, finish;
    vector<long long> distance;
    vector<vertex> ancestors;
    Graph graph;
    
public:
    Dijkstra(int, int, const Graph&);
    
    void search();
    long long distanceTo(vertex);
    vector<vertex> wayToVertex(vertex);
    vector<long long> allDistances();
    void setGraph(const Graph&);
    void setStart(vertex);
    void setFinish(vertex);
    void setNewData(int, int, const Graph&);
};

#endif /* Dijkstra_hpp */
