#include <iostream>
#include <vector>
#include "MatrixGraph.h"
#include "GraphLibrary/Definitions.h"
#include "GraphLibrary/Searches/AStar.h"

using namespace std;

long long distanceFunction(GraphLibrary::vertex a, GraphLibrary::vertex b)
{
    return abs(a - b);
}

int main()
{
    vector<pair<int, int> > blocked;
    blocked.push_back(make_pair(1, 3));
    blocked.push_back(make_pair(2, 1));
    blocked.push_back(make_pair(2, 3));
    blocked.push_back(make_pair(3, 1));
    blocked.push_back(make_pair(3, 2));
    blocked.push_back(make_pair(3, 3));

    MatrixGraph g(5, 7, blocked);
    GraphLibrary::AStar<MatrixGraph> aStar(0, 5*7 - 1, distanceFunction, g);
    aStar.search();
    cout << aStar.distanceTo(5*7-1);
}