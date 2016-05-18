//
// Created by Eugene Marchukevich on 5/19/16.
//

#include "MatrixReader.h"

namespace GraphLibrary {

    MatrixReader :: MatrixReader(std::string name)
    {
        fin.open(name);
        fin >> n >> m;
        int x = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                fin >> x;
                if (x != 0) {
                    blockedCells.insert(std :: make_pair(i, j));
                }
            }
        }
        it = blockedCells.begin();
    }
    int MatrixReader ::  getN()
    {
        return n;
    }
    int MatrixReader :: getM()
    {
        return m;
    }

    bool MatrixReader :: isNextCellExists()
    {
        return it != blockedCells.end();
    }

    std :: pair<int, int> MatrixReader :: getNextBlockedCell()
    {
        std :: pair<int, int> cell = *it;
        it++;
        return cell;
    }
    MatrixReader :: ~MatrixReader()
    {
        fin.close();
    }
};