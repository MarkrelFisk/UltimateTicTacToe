#include <iostream>

#include "Board.h"

// forward declare
void playloop(int player, Board* board);

int main(int argc, char** argv) {
    Board* board = new Board;

    board->printState();
    
    int gridIdx;
    std::cout << "player 1 choose start grid: ";
    std::cin >> gridIdx;

    board->setActiveGrid(gridIdx);

    for (;;) {

        playloop(1, board);
        
        if (board->checkWinCondition(1)) {
            std::cout << "player 1 is the winner" << std::endl;
            break;
        }

        std::cout << "active grid: " << board->getActiveGrid() << std::endl;

        playloop(2, board);
        
        if (board->checkWinCondition(2)) {
            std::cout << "player 2 is the winner" << std::endl;
            break;
        }

        std::cout << "active grid: " << board->getActiveGrid() << std::endl;
    }

}

void playloop(const int player, Board* board) {
    bool legalMove = false;
    int gridIdx = board->getActiveGrid();
    bool legalGrid = board->checkGridLegal(gridIdx);
    int idx;

    while (!legalGrid) {
        std::cout << "Player " << player << " choose new grid:" << std::endl;
        std::cin >> gridIdx;
        legalGrid = board->checkGridLegal(gridIdx);
    }

    while (!legalMove) {
        std::cout << "player " << player << " move:" << std::endl;
        std::cin >> idx;

        legalMove = board->changeValue(gridIdx, idx, player);

        if (!legalMove) {
            std::cout << "Illegal move" << std::endl;
        }
        board->printState();

    }
    board->setActiveGrid(idx);
}