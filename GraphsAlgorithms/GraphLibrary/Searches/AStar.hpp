//
//  AStar.hpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/14/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef AStar_hpp
#define AStar_hpp

#include <stdio.h>
#include "Search.h"
#include <map>

namespace GraphLibrary
{
    
    class AStar : public Search
    {
    private:
        vertex start, finish;
        BaseGraph *graph;
        long long(*distanceFunction)(vertex, vertex);
        map<int, long long> distance;
        
    public:
        AStar(vertex, vertex, long long(*)(vertex, vertex), const BaseGraph& g);
        
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
#endif /* AStar_hpp */
