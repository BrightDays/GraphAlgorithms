//
//  BaseGraph.h
//  GraphsAlgorithms
//
//  Created by Eugene Marchukevich on 12/14/15.
//  Copyright © 2015 Eugene Marchukevich. All rights reserved.
//

#ifndef BaseGraph_h
#define BaseGraph_h

#include "Definitions.h"
#include <vector>

using namespace std;

namespace GraphLibrary
{
    class BaseGraph
    {
    public:
        virtual vector<Edge> :: iterator beginForVertex(vertex)
        {
            std::vector<Edge> :: iterator it;
            return it;
        }
        virtual vector<Edge> :: iterator endForVertex(vertex)
        {
            std::vector<Edge> :: iterator it;
            return it;
        }
        
        virtual vector<Edge> :: iterator begin()
        {
            std::vector<Edge> :: iterator it;
            return it;
        }
        
        virtual vector<Edge> :: iterator end()
        {
            std::vector<Edge> :: iterator it;
            return it;
        }
        
        
        virtual vector<Edge> edgesForVertex(vertex)
        {
            vector<Edge> v;
            return v;
        }
        virtual vector<Edge> allEdges()
        {
            vector<Edge> v;
            return v;
        }
        
        virtual bool iteratorBased() = 0;
        
        virtual int numberOfVertexes() = 0;
        virtual int numberOfEdges() = 0;
    };

}
#endif /* BaseGraph_h */
