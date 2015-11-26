//
//  WidthFastSearch.hpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef WidthFastSearch_hpp
#define WidthFastSearch_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include "Graph.hpp"
#include "Search.h"

using namespace std;

class WidthFastSearch : virtual public Search
{
private:
    vertex start, finish;
    vector<long long> distance;
    vector<vertex> ancestors;
    queue<vertex> q;
    Graph graph;

public:
    WidthFastSearch(int, int, const Graph&);
    
    void search();
    long long distanceTo(vertex);
    vector<vertex> wayToVertex(vertex);
    vector<long long> allDistances();
    void setGraph(const Graph&);
    void setStart(vertex);
    void setFinish(vertex);
    void setNewData(int, int, const Graph&);
};


#endif /* WidthFastSearch_hpp */
