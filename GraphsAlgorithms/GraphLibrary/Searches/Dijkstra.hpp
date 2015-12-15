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
#include <set>
#include "Search.h"

using namespace std;

namespace GraphLibrary
{
    class Dijkstra : public Search
    {
    private:
        vertex start, finish;
        vector<vertex> ancestors;
        BaseGraph *graph;
        vector<long long> distance;
        
    public:
        Dijkstra(vertex, vertex, const BaseGraph & g);
        
        void search();
        long long distanceTo(vertex);
        vector<vertex> wayToVertex(vertex);
        vector<long long> allDistances();
        void setGraph(const BaseGraph&);
        void setStart(vertex);
        void setFinish(vertex);
        void setNewData(int, int, const BaseGraph&);
    };
}
#endif /* Dijkstra_hpp */
