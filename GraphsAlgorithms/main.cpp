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
#include "Dijkstra.hpp"
#include "WidthFastSearch.hpp"
#include "FordBellman.hpp"
#include "AStar.hpp"
#include "MatrixGraph.hpp"
#include <vector>

using namespace std;

long long distanceFunction(GraphLibrary::vertex a, GraphLibrary::vertex b)
{
    return abs(a - b);
}


int main(int argc, const char * argv[])
{
    vector<pair<int, int>> blocked;
    blocked.push_back(make_pair(1, 3));
    blocked.push_back(make_pair(2, 1));
    blocked.push_back(make_pair(2, 3));
    blocked.push_back(make_pair(3, 1));
    blocked.push_back(make_pair(3, 2));
    blocked.push_back(make_pair(3, 3));
    
    MatrixGraph g(5, 7, blocked);
    GraphLibrary::AStar aStar(0, 5*7 - 1, distanceFunction, g);
    aStar.search();
    cout << aStar.distanceTo(5*7-1);

//    vector<pair<int, int>> blocked;
//    blocked.push_back(make_pair(1, 1));
//    
//    MatrixGraph g(3, 3, blocked);
//    GraphLibrary::AStar aStar(0, 3 * 3 - 1, distanceFunction, g);
//    aStar.search();
//    cout << aStar.distanceTo(8);
//    GraphLibrary::Dijkstra d(0, 7, g);
//    d.search();
//    cout << d.distanceTo(7);
    return 0;
}
