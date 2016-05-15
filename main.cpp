#include <iostream>
#include <vector>
#include "GraphLibrary/GraphsImplementations/MatrixGraph.h"
#include "GraphLibrary/GraphLibrary.h"

using namespace std;
using namespace GraphLibrary;

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
    AStar<MatrixGraph> aStar(0, 34, distanceFunction, g);
    aStar.search();
    cout << aStar.distanceTo(5*7-1) << endl;

    WidthFastSearch<MatrixGraph> wfs(0, 34, g);
    wfs.search();
    cout << wfs.distanceTo(5*7-1) << endl;

    Dijkstra<MatrixGraph> d(0, 34, g);
    d.search();
    cout << d.distanceTo(5*7-1) << endl;

    Graph graph(6);
    graph.addEdge( Edge(0, 1));
    graph.addEdge( Edge(1, 2));
    graph.addEdge( Edge(2, 0));
    graph.addEdge( Edge(3, 4));
    graph.addEdge( Edge(4, 5));
    graph.addEdge( Edge(5, 3));
    graph.addEdge( Edge(2, 3));

    BridgeSearch<Graph> bridgeSearch(graph);
    bridgeSearch.search();
    vector<Edge> b = bridgeSearch.getBridges();
    for(int i = 0; i < b.size(); i ++) {
        cout << b[i].start << " " << b[i].finish << endl;
    }

    BiconnectedComponentSearch<Graph> biconnectedComponentSearch(graph);
    biconnectedComponentSearch.search();
    vector<vertex > a = biconnectedComponentSearch.getBiconnectedComponents();
    for(int i = 0; i < a.size(); i ++) {
        cout << a[i] << endl;
    }


    OrientedGraph g1(6);
    g1.addEdge(Edge(0, 1));
    g1.addEdge(Edge(1, 2));
    g1.addEdge(Edge(2, 0));
    g1.addEdge(Edge(3, 4));
    g1.addEdge(Edge(4, 5));
    g1.addEdge(Edge(5, 3));
    g1.addEdge(Edge(2, 3));

    OrientedGraph g2(6);
    g2.addEdge(Edge(1, 0));
    g2.addEdge(Edge(2, 1));
    g2.addEdge(Edge(0, 2));
    g2.addEdge(Edge(4, 3));
    g2.addEdge(Edge(5, 4));
    g2.addEdge(Edge(3, 5));
    g2.addEdge(Edge(3, 2));

    StrongConnectedComponentsSearch<OrientedGraph> strongConnectedComponentsSearch(g1, g2);
    strongConnectedComponentsSearch.search();
    vector<vector<vertex>> comp = strongConnectedComponentsSearch.getComponents();
    for(int j = 0; j < comp.size(); j ++) {
        vector<vertex> component = comp[j];
        for(int i = 0; i < component.size(); i ++) {
            cout << component[i] << " ";
        }
        cout << endl;
    }

}