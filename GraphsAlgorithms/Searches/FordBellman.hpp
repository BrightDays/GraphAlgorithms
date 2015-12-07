//
//  FordBellman.hpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/7/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef FordBellman_hpp
#define FordBellman_hpp

#include <stdio.h>
#include "Search.h"

using namespace std;

class FordBellman : virtual public Search
{
private:
    vertex start, finish;
    vector<long long> distance;
    vector<vertex> ancestors;
    Graph graph;
    
public:
    FordBellman(int, int, const Graph&);
    
    void search();
    long long distanceTo(vertex);
    vector<vertex> wayToVertex(vertex);
    vector<long long> allDistances();
    void setGraph(const Graph&);
    void setStart(vertex);
    void setFinish(vertex);
    void setNewData(int, int, const Graph&);
};


#endif /* FordBellman_hpp */
