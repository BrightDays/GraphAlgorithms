//
// Created by Eugene Marchukevich on 5/18/16.
//

#ifndef GRAPHALGORITHMS_RELATIONTABLEREADER_H
#define GRAPHALGORITHMS_RELATIONTABLEREADER_H

#include "../GraphsImplementations/RelationTableGraph.h"
#include "../Definitions.h"
#include <vector>
#include <string.h>
#include <string>
#include <fstream>


namespace GraphLibrary {
    class RelationTableReader {
    private:
        int n;
        int m;
        int counter;
        vertex current;
        vertex ancestor;
        VertexData data;
        std :: ifstream fin;
        ~RelationTableReader();

    public:
        RelationTableReader(std :: string);
        int numberOfVertexes();
        int countOfLines();
        bool readNextLine();
        vertex currentVertex();
        vertex ancestorVertex();
        VertexData currentVertexData();
    };
}


#endif //GRAPHALGORITHMS_RELATIONTABLEREADER_H
