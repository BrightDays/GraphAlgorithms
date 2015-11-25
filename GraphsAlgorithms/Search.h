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

class Search
{
public:
    virtual void search();
    virtual long long distanceTo(vertex);
    virtual vector<vertex> wayToVertex(vertex);
    virtual vector<long long> allDistances();
    virtual void setGraph(const Graph&);
    virtual void setStart(vertex);
    virtual void setFinish(vertex);
    virtual void setNewData(int, int, const Graph&);
};

#endif /* Search_h */
