//
// Created by Eugene Marchukevich on 5/19/16.
//

#ifndef GRAPHALGORITHMS_GRAPHREADER_H
#define GRAPHALGORITHMS_GRAPHREADER_H

#include "../Definitions.h"
#include <vector>
#include <string.h>
#include <string>
#include <fstream>


namespace GraphLibrary {
    class GraphReader {
    private:
        int n;
        int m;
        std :: ifstream fin;
        ~GraphReader();

    public:
        GraphReader(std::string);
        int numberOfVertexes();
        int numberOfEdges();
        Edge getNextEdge();
    };
}


#endif //GRAPHALGORITHMS_GRAPHREADER_H
