//
//  BroadFastSearch.cpp
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/8/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#include "BroadFastSearch.hpp"

using namespace std;


BroadFastSearch :: BroadFastSearch(int _start, int _finish, const Graph &g)
{
    start = _start;
    finish = _finish;
    graph = g;
}
