#include <iostream>
#include "TicTacToe.h"

bool TicTacToe::changeValue(const int gridIdx, const int idx, const int val) {
    Grid* gridPtr = grid[gridIdx];
    if (gridPtr->getWinState() != 0) return false; 
    if (gridPtr->changeValueAtIdx(idx, val)) {
        gridPtr->checkWinCondition(val);
        return true;
    }

    return false;
}

void TicTacToe::printState() {
    for (int i = 0; i < 3; ++i) {
        grid[0]->printLine(i);
        std::cout << " | ";
        grid[1]->printLine(i);
        std::cout << " | ";
        grid[2]->printLine(i);
        std::cout << "" << std::endl;
    }

    std::cout << "---------------------" << std::endl;
    
    for (int i = 0; i < 3; ++i) {
        grid[3]->printLine(i);
        std::cout << " | ";
        grid[4]->printLine(i);
        std::cout << " | ";
        grid[5]->printLine(i);
        std::cout << "" << std::endl;
    }

    std::cout << "---------------------" << std::endl;
    
    for (int i = 0; i < 3; ++i) {
        grid[6]->printLine(i);
        std::cout << " | ";
        grid[7]->printLine(i);
        std::cout << " | ";
        grid[8]->printLine(i);
        std::cout << "" << std::endl;
    }
}

bool TicTacToe::checkWinCondition(const int val) {
    if ( 
    (grid[0]->getWinState() == val && grid[1]->getWinState() == val && grid[2]->getWinState() == val) || 
    (grid[0]->getWinState() == val && grid[3]->getWinState() == val && grid[6]->getWinState() == val) ||
    (grid[0]->getWinState() == val && grid[4]->getWinState() == val && grid[8]->getWinState() == val) ||
    (grid[3]->getWinState() == val && grid[4]->getWinState() == val && grid[5]->getWinState() == val) ||
    (grid[6]->getWinState() == val && grid[7]->getWinState() == val && grid[8]->getWinState() == val) ||
    (grid[6]->getWinState() == val && grid[4]->getWinState() == val && grid[2]->getWinState() == val) ||
    (grid[1]->getWinState() == val && grid[4]->getWinState() == val && grid[7]->getWinState() == val) ||
    (grid[2]->getWinState() == val && grid[5]->getWinState() == val && grid[8]->getWinState() == val) 
    ) {
        return true;
    }

    return false;
}

bool TicTacToe::checkGridLegal(const int gridIdx) {
    if (grid[gridIdx]->getWinState() == 0) {
        return true;
    }
    return false;
}