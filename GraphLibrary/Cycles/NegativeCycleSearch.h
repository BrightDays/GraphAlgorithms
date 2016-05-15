//
// Created by Eugene Marchukevich on 4/16/16.
//

#ifndef GRAPHALGORITHMS_NEGATIVECYCLESEARCH_H
#define GRAPHALGORITHMS_NEGATIVECYCLESEARCH_H


#include <iostream>
#include <vector>
#include "../Definitions.h"

using namespace std;

namespace GraphLibrary {
    template<class G>
    class NegativeCycleSearch {
        CREATE_CHECK_METHOD_NO_PARAMS(begin, G);
        CREATE_CHECK_METHOD_NO_PARAMS(end, G);
        CREATE_CHECK_METHOD_NO_PARAMS(allEdges, G);

    private:
        vector<long long> distance;
        vector<vertex> ancestors;
        G *graph;
        bool cycleExist;
        vector<vertex> cycleVertexes;

    public:
        NegativeCycleSearch(const G &);
        void search();
        void setGraph(const G &);
        bool isCycleExist();
        vector<vertex> getCycleVertexes();
    };

    template<class G>
    NegativeCycleSearch<G>::NegativeCycleSearch(const G &g) {
        graph = (G *) &g;
        ancestors.resize(graph->numberOfVertexes());
        for (int i = 0; i < graph->numberOfVertexes(); i++) {
            distance.push_back(MAX_DISTANCE);
        }
    }

    template<class G>
    void NegativeCycleSearch<G>::search() {
        CREATE_METHOD_CALLER(vector<Edge>::iterator, begin, graph);
        CREATE_METHOD_CALLER(vector<Edge>::iterator, end, graph);
        CREATE_METHOD_CALLER(vector<Edge>, allEdges, graph);

        distance[0] = 0;
        vertex anyChanges = -1;
        for (int i = 0; i < graph->numberOfVertexes(); i++) {
            anyChanges = -1;
            vector<Edge>::iterator itBegin;
            vector<Edge>::iterator itEnd;
            vector<Edge> currentEdges;
            if (graph->iteratorBased()) {
                itBegin = callMethod_begin();
                itEnd = callMethod_end();
            } else {
                currentEdges = callMethod_allEdges();
                itBegin = currentEdges.begin();
                itEnd = currentEdges.end();
            }
            for (vector<Edge>::iterator it = itBegin; it != itEnd; it++) {
                Edge edge = *it;
                if (distance[edge.finish] > distance[edge.start] + edge.weight) {
                    distance[edge.finish] = distance[edge.start] + edge.weight;
                    ancestors[edge.finish] = edge.start;
                    anyChanges = edge.finish;
                }
            }
        }
        if (anyChanges == -1) {
            cycleExist = false;
            return;
        }
        cycleExist = true;
        vertex y = anyChanges;
        for (int i = 0; i < ancestors.size(); ++i)
            y = ancestors[y];

        for (vertex cur = y; ; cur = ancestors[cur]) {
            cycleVertexes.push_back(cur);
            if (cur == y && cycleVertexes.size() > 1) break;
        }
        reverse(cycleVertexes.begin(), cycleVertexes.end());
    }

    template<class G>
    bool NegativeCycleSearch<G>::isCycleExist() {
        return cycleExist;
    }

    template<class G>
    vector<vertex> NegativeCycleSearch<G>::getCycleVertexes() {
        return cycleVertexes;
    }

    template<class G>
    void NegativeCycleSearch<G>::setGraph(const G &g) {
        graph = (G *) &g;
        distance.clear();
        ancestors.clear();
        for (int i = 0; i < graph->numberOfVertexes(); i++) {
            distance.push_back(MAX_DISTANCE);
            ancestors.push_back(-1);
        }

    }
}




#endif //GRAPHALGORITHMS_NEGATIVECYCLESEARCH_H
