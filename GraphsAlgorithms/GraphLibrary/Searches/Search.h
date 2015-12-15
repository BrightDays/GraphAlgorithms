//
//  Search.h
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/26/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef Search_h
#define Search_h

#include "Definitions.h"
#include <vector>
#include "Graph.hpp"

using namespace std;

namespace GraphLibrary
{
    
    class Search
    {
    public:
        virtual void search() = 0;
        virtual long long distanceTo(vertex) = 0;
        virtual vector<vertex> wayToVertex(vertex) = 0;
        virtual vector<long long> allDistances() = 0;
        virtual void setGraph(const BaseGraph&) = 0;
        virtual void setStart(vertex) = 0;
        virtual void setFinish(vertex) = 0;
        virtual void setNewData(int, int, const BaseGraph&) = 0;
    };
}
#endif /* Search_h */
