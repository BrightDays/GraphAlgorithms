//
//  main.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include <iostream>
#include "Definitions.h"
#include "Graph.hpp"
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    vector<Edge> a;
    a.push_back(Edge(0,1));
    Graph g = Graph(2, a);
    return 0;

}
