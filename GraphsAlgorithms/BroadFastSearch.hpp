//
//  BroadFastSearch.hpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef BroadFastSearch_hpp
#define BroadFastSearch_hpp

#include <stdio.h>
#include "Search.h"
#include <vector>
#include "Graph.hpp"

using namespace std;

class BroadFastSearch : Search
{
private:
    vertex start, finish;
    vector<long long> distance;
    vector<vertex> ancestors;
    Graph graph;


public:
    BroadFastSearch(int, int, const Graph&);

};

#endif /* BroadFastSearch_hpp */
