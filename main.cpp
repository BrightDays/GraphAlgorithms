#include <iostream>
#include <vector>
#include "MatrixGraph.h"
#include "GraphLibrary/GraphLibrary.h"

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
    GraphLibrary::AStar<MatrixGraph> aStar(0, 34, distanceFunction, g);
    aStar.search();
    cout << aStar.distanceTo(5*7-1) << endl;

    GraphLibrary::WidthFastSearch<MatrixGraph> wfs(0, 34, g);
    wfs.search();
    cout << wfs.distanceTo(5*7-1) << endl;

    GraphLibrary::Dijkstra<MatrixGraph> d(0, 34, g);
    d.search();
    cout << d.distanceTo(5*7-1) << endl;

    GraphLibrary::Graph graph(6);
    graph.addEdge(GraphLibrary:: Edge(0, 1));
    graph.addEdge(GraphLibrary:: Edge(1, 2));
    graph.addEdge(GraphLibrary:: Edge(2, 0));
    graph.addEdge(GraphLibrary:: Edge(3, 4));
    graph.addEdge(GraphLibrary:: Edge(4, 5));
    graph.addEdge(GraphLibrary:: Edge(5, 3));
    graph.addEdge(GraphLibrary:: Edge(2, 3));

    GraphLibrary::BridgeSearch<GraphLibrary::Graph> bridgeSearch(graph);
    bridgeSearch.search();
    vector<GraphLibrary::Edge> b = bridgeSearch.getBridges();
    for(int i = 0; i < b.size(); i ++) {
        cout << b[i].start << " " << b[i].finish << endl;
    }

}