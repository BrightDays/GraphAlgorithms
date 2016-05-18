//
// Created by Eugene Marchukevich on 5/19/16.
//

#ifndef GRAPHALGORITHMS_SIMPLEMATRIXREADER_H
#define GRAPHALGORITHMS_SIMPLEMATRIXREADER_H

#include "../Definitions.h"
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <fstream>


namespace GraphLibrary {
    class SimpleMatrixReader {
    private:
        int n;
        int m;
        std::set<std::pair<int, int>> blockedCells;
        std::set<std::pair<int, int>> :: iterator it;
        std :: ifstream fin;


    public:
        SimpleMatrixReader(std :: string);
        int getN();
        int getM();
        std :: pair<int, int> getNextBlockedCell();
        bool isNextCellExists();
        ~SimpleMatrixReader();
    };
}

#endif //GRAPHALGORITHMS_SIMPLEMATRIXREADER_H
