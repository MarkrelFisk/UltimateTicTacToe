#include <iostream>

#include "TicTacToe.h"

// forward declare
int playloop(int player, TicTacToe* board, int grid);

int main(int argc, char** argv) {
    TicTacToe* board = new TicTacToe;

    board->printState();
    
    int grid;
    std::cout << "player 1 choose start grid: ";
    std::cin >> grid;

    for (;;) {
        grid = playloop(1, board, grid);
        
        if (board->checkWinCondition(1)) {
            std::cout << "player 1 is the winner" << std::endl;
            break;
        }

        grid = playloop(2, board, grid);
        
        if (board->checkWinCondition(2)) {
            std::cout << "player 2 is the winner" << std::endl;
            break;
        }
    }

}

int playloop(const int player, TicTacToe* board, int grid) {
    bool legalMove = false;
    bool legalGrid = board->checkGridLegal(grid);
    int idx;

    while (!legalGrid) {
        std::cout << "Player " << player << " choose new grid:" << std::endl;
        std::cin >> grid;
        legalGrid = board->checkGridLegal(grid);
    }

    while (!legalMove) {
        std::cout << "player " << player << " move:" << std::endl;
        std::cin >> idx;

        legalMove = board->changeValue(grid, idx, player);

        if (!legalMove) {
            std::cout << "Illegal move" << std::endl;
        }
        board->printState();

    }
    return idx;
}