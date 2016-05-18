//
// Created by Eugene Marchukevich on 5/19/16.
//

#include "GraphReader.h"
#include <fstream>

namespace GraphLibrary {

    GraphReader :: GraphReader(std::string name)
    {
        fin.open(name);
        fin >> n >> m;
    }
    int GraphReader :: numberOfVertexes()
    {
        return n;
    }
    int GraphReader :: numberOfEdges()
    {
        return m;
    }
    Edge GraphReader :: getNextEdge()
    {
        int x,y,z;
        fin >> x >> y >> z;
        Edge edge(x, y, z);
        return edge;
    }
    GraphReader :: ~GraphReader() {
        fin.close();
    }
};