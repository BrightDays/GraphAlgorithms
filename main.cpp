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

class A : public VertexData{
public:
    int a;
};

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
    cout << "AStar:" << endl;
    cout << aStar.distanceTo(5*7-1) << endl;

    WidthFastSearch<MatrixGraph> wfs(0, 34, g);
    wfs.search();
    cout << "WFS:" << endl;
    cout << wfs.distanceTo(5*7-1) << endl;

    Dijkstra<MatrixGraph> d(0, 34, g);
    d.search();
    cout << "Dijkstra:" << endl;
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
    cout << "Bridges:" << endl;
    for(int i = 0; i < b.size(); i ++) {
        cout << b[i].start << " " << b[i].finish << endl;
    }

    BiconnectedComponentSearch<Graph> biconnectedComponentSearch(graph);
    biconnectedComponentSearch.search();
    vector<vertex > a = biconnectedComponentSearch.getBiconnectedComponents();
    cout << "Biconnected Components:" << endl;
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
    cout << "Strong Connected Components:" << endl;
    for(int j = 0; j < comp.size(); j ++) {
        vector<vertex> component = comp[j];
        for(int i = 0; i < component.size(); i ++) {
            cout << component[i] << " ";
        }
        cout << endl;
    }

    OrientedGraph orientedGraphForSort(8);
    orientedGraphForSort.addEdge(Edge(1, 4));
    orientedGraphForSort.addEdge(Edge(1, 6));
    orientedGraphForSort.addEdge(Edge(2, 7));
    orientedGraphForSort.addEdge(Edge(3, 7));
    orientedGraphForSort.addEdge(Edge(3, 4));
    orientedGraphForSort.addEdge(Edge(4, 5));
    orientedGraphForSort.addEdge(Edge(7, 0));
    orientedGraphForSort.addEdge(Edge(7, 5));
    orientedGraphForSort.addEdge(Edge(7, 6));

    TopologicalSort<OrientedGraph> topologicalSort(orientedGraphForSort);
    topologicalSort.sort();
    vector<vertex> sortedVertexes = topologicalSort.getSortedVertexes();
    cout << "Topological Sort:" << endl;
    for(int i = 0; i < sortedVertexes.size(); i ++) {
        cout << sortedVertexes[i] << " ";
    }
    cout << endl;

    MinSpanTree<Graph> minSpanTree(graph);
    minSpanTree.build();
    vector<Edge> minSpanTreeEdges = minSpanTree.getSpanTreeEdges();
    cout << "Span tree:" << endl;
    for(int i = 0; i < minSpanTreeEdges.size(); i ++) {
        cout << minSpanTreeEdges[i].start << " " << minSpanTreeEdges[i].finish << endl;
    }

    Graph negativeCycleGraph(5);
    negativeCycleGraph.addEdge(Edge(0, 1, -1));
    negativeCycleGraph.addEdge(Edge(1, 2, 2));
    negativeCycleGraph.addEdge(Edge(2, 3, -4));
    negativeCycleGraph.addEdge(Edge(3, 0, 1));
    negativeCycleGraph.addEdge(Edge(4, 0, 1));

    NegativeCycleSearch<Graph> negativeCycleSearch(negativeCycleGraph);
    negativeCycleSearch.search();
    cout << "Negative Cycle Search:" << endl;
    if (negativeCycleSearch.isCycleExist()) {
        cout << "Cycle exist" << endl;
        vector<vertex> cycle = negativeCycleSearch.getCycleVertexes();
        for(int i = 0; i < cycle.size(); i ++) {
            cout << cycle[i] << " ";
        }
    } else {
        cout << "There is no cycle." << endl;
    }

    Graph lca(7);
    lca.addEdge(Edge(0, 1));
    lca.addEdge(Edge(1, 2));
    lca.addEdge(Edge(0, 3));
    lca.addEdge(Edge(3, 4));
    lca.addEdge(Edge(3, 5));
    lca.addEdge(Edge(5, 6));
    LCA<Graph> lcaAlgo(lca);
    lcaAlgo.search();
    cout << endl;
    cout << "LCA:" << endl;
    cout << lcaAlgo.findLca(6, 1) << endl;
    cout << lcaAlgo.findLca(4, 6) << endl;
    cout << lcaAlgo.findLca(5, 6) << endl;


    RelationTableReader reader("in.txt");
    RelationTableGraph<RelationTableReader> lcaRel(7, false);
    A aaa;
    lcaRel.addLine(0, 1);
    lcaRel.addLine(1, 2, aaa);
    lcaRel.addLine(0, 3, aaa);
    lcaRel.addLine(3, 4, aaa);
    lcaRel.addLine(3, 5, aaa);
    lcaRel.addLine(5, 6);
    LCA<RelationTableGraph<RelationTableReader>> lcaRelation(lcaRel);
    lcaRelation.search();
    cout << endl;
    cout << "LCA Relation:" << endl;
    cout << lcaRelation.findLca(6, 1) << endl;
    cout << lcaRelation.findLca(4, 6) << endl;
    cout << lcaRelation.findLca(5, 6) << endl;

    RelationTableGraph<RelationTableReader> relationTableGraph(false, reader);
    relationTableGraph.buildGraph();
    LCA<RelationTableGraph<RelationTableReader>> lcaRelationSearch(lcaRel);
    lcaRelation.search();
}