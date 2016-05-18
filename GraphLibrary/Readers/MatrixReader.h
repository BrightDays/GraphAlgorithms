//
// Created by Eugene Marchukevich on 5/19/16.
//

#ifndef GRAPHALGORITHMS_MATRIXREADER_H
#define GRAPHALGORITHMS_MATRIXREADER_H

#include "../Definitions.h"
#include <vector>
#include <string.h>
#include <string>
#include <utility>
#include <set>
#include <fstream>

namespace GraphLibrary {
    class MatrixReader {
    private:
        int n;
        int m;
        std::set<std::pair<int, int>> blockedCells;
        std::set<std::pair<int, int>> :: iterator it;
        std :: ifstream fin;


    public:
        MatrixReader(std :: string);
        int getN();
        int getM();
        std :: pair<int, int> getNextBlockedCell();
        bool isNextCellExists();
        ~MatrixReader();
    };
}

#endif //GRAPHALGORITHMS_MATRIXREADER_H
