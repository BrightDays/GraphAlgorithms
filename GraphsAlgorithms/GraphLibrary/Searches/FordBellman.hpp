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

namespace GraphLibrary
{
    class FordBellman : public Search
    {
    private:
        vertex start, finish;
        vector<long long> distance;
        vector<vertex> ancestors;
        BaseGraph *graph;
        
    public:
        FordBellman(vertex, vertex, const BaseGraph&);
        
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

#endif /* FordBellman_hpp */
