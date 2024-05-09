#include <iostream>
#include "Grid.h"

bool Grid::changeValueAtIdx(const int idx, const int val) {
    if (gridValues[idx] == 0) { 
        gridValues[idx] = val;
        return true;
    }

    return false;

}

void Grid::checkWinCondition(const int val) {
    if ( 
    (gridValues[0] == val && gridValues[1] == val && gridValues[2] == val) || 
    (gridValues[0] == val && gridValues[3] == val && gridValues[6] == val) ||
    (gridValues[0] == val && gridValues[4] == val && gridValues[8] == val) ||
    (gridValues[3] == val && gridValues[4] == val && gridValues[5] == val) ||
    (gridValues[6] == val && gridValues[7] == val && gridValues[8] == val) ||
    (gridValues[6] == val && gridValues[4] == val && gridValues[2] == val) ||
    (gridValues[1] == val && gridValues[4] == val && gridValues[7] == val) ||
    (gridValues[2] == val && gridValues[5] == val && gridValues[8] == val) 
    ) {
        if (val == 1) {
            gridValues[0] = val;
            gridValues[1] = 0;
            gridValues[2] = val;
            gridValues[3] = 0;
            gridValues[4] = val;
            gridValues[5] = 0;
            gridValues[6] = val;
            gridValues[7] = 0;
            gridValues[8] = val;
        } else {
            gridValues[0] = 0;
            gridValues[1] = val;
            gridValues[2] = 0;
            gridValues[3] = val;
            gridValues[4] = 0;
            gridValues[5] = val;
            gridValues[6] = 0;
            gridValues[7] = val;
            gridValues[8] = 0;
        }

        winState = val;
    }
}

void Grid::printState() {
    std::cout << "" << std::endl;
    for (int i = 0; i < 9; i+=3) {
        for (int j = 0; j < 3; ++j) {
            std::cout << gridValues[i + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "" << std::endl;
}

void Grid::printLine(const int idxLine) {
    int line = idxLine * 3;
    std::cout << gridValues[line] << " " << gridValues[line + 1] << " " << gridValues[line + 2];
}