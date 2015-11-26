//
//  Definitions.h
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 11/26/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef Definitions_h
#define Definitions_h

typedef int vertex;

struct EdgeTo
{
    int finish;
    long long weight;
    EdgeTo(int _finish, long long _weight)
    {
        finish = _finish;
        weight = _weight;
    }
};

struct Edge
{
    int start, finish;
    long long weight;
    Edge(int _start, int _finish, long long _weight)
    {
        start = _start;
        finish = _finish;
        weight = _weight;
    }
    
    Edge(int _start, int _finish)
    {
        start = _start;
        finish = _finish;
        weight = 1;
    }
    Edge(int _start, EdgeTo edgeTo)
    {
        start = _start;
        finish = edgeTo.finish;
        weight = edgeTo.weight;
    }
};

#endif /* Definitions_h */
