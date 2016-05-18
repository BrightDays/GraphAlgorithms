//
// Created by Eugene Marchukevich on 5/19/16.
//

#include "SimpleMatrixReader.h"

#include "MatrixReader.h"

namespace GraphLibrary {

    SimpleMatrixReader :: SimpleMatrixReader(std::string name)
    {
        int x, y, k;
        fin.open(name);
        fin >> n >> m;
        fin >> k;
        for(int i = 0; i < k; i++) {
            fin >> x, y;
            blockedCells.insert(std :: make_pair(x, y));
        }
        it = blockedCells.begin();
    }
    int SimpleMatrixReader ::  getN()
    {
        return n;
    }
    int SimpleMatrixReader :: getM()
    {
        return m;
    }

    bool SimpleMatrixReader :: isNextCellExists()
    {
        return it != blockedCells.end();
    }

    std :: pair<int, int> SimpleMatrixReader :: getNextBlockedCell()
    {
        std :: pair<int, int> cell = *it;
        it++;
        return cell;
    }
    SimpleMatrixReader :: ~SimpleMatrixReader()
    {
        fin.close();
    }
};