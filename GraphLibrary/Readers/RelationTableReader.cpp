//
// Created by Eugene Marchukevich on 5/18/16.
//

#include "RelationTableReader.h"

namespace GraphLibrary
{

    RelationTableReader :: RelationTableReader(string name) {
        fin.open(name);
        fin >> n;
        fin >> m;
        counter = 0;
    }

    int RelationTableReader :: numberOfVertexes() {
        return n;
    }

    int RelationTableReader :: countOfLines() {
        return m;
    }

    bool RelationTableReader ::readNextLine() {
        if (counter < m) {
            int value;
            fin >> current >> ancestor >> value;
            data.value = value;
            return true;
        }
        return false;
    }

    vertex RelationTableReader ::  currentVertex() {
        return current;
    }

    vertex RelationTableReader ::  ancestorVertex() {
        return ancestor;
    }

    VertexData RelationTableReader ::  currentVertexData() {
        return data;
    }

    RelationTableReader :: ~RelationTableReader()
    {
        fin.close();
    }
};
