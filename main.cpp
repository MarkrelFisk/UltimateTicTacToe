#include <iostream>

#include "Board.h"

// forward declare
void playerTurn(int player, Board* board);
void botTurn(int player, Board* board);
int validateInput();

int main(int argc, char** argv) {

    std::srand(std::time(nullptr));

    Board* board = new Board;

    int playerCount; 

    board->printState();

    std::cout << "1 or 2 players?" << std::endl;
    std::cin >> playerCount;
    if (playerCount != 1 && playerCount != 2) {
        playerCount = 1;
    }

    int gridIdx;
    std::cout << "player 1 choose start grid: ";
    gridIdx = validateInput();

    board->setActiveGrid(gridIdx);

    if (playerCount == 1) {
        for (;;) {
            botTurn(1, board);
            
            if (board->checkWinCondition(1)) {
                std::cout << "player 1 is the winner" << std::endl;
                break;
            }

            if (board->checkIfTied()) {
                std::cout << "its a tie" << std::endl;
                break;
            }

            std::cout << "active grid: " << board->getActiveGrid() << std::endl;

            botTurn(2, board);
            
            if (board->checkWinCondition(2)) {
                std::cout << "player 2 is the winner" << std::endl;
                break;
            }
            
            if (board->checkIfTied()) {
                std::cout << "its a tie" << std::endl;
                break;
            }

            std::cout << "active grid: " << board->getActiveGrid() << std::endl;
        }
    } else {

        for (;;) {

            playerTurn(1, board);
            
            if (board->checkWinCondition(1)) {
                std::cout << "player 1 is the winner" << std::endl;
                break;
            }

            if (board->checkIfTied()) {
                std::cout << "its a tie" << std::endl;
                break;
            }

            std::cout << "active grid: " << board->getActiveGrid() << std::endl;

            playerTurn(2, board);
            
            if (board->checkWinCondition(2)) {
                std::cout << "player 2 is the winner" << std::endl;
                break;
            }
        
            if (board->checkIfTied()) {
                std::cout << "its a tie" << std::endl;
                break;
            }

            std::cout << "active grid: " << board->getActiveGrid() << std::endl;
        }
    }

}

void playerTurn(const int player, Board* board) {
    bool legalMove = false;
    int gridIdx = board->getActiveGrid();
    bool legalGrid = board->checkGridLegal(gridIdx);
    int idx;

    while (!legalGrid) {
        std::cout << "Player " << player << " choose new grid:" << std::endl;
        gridIdx = validateInput();
        legalGrid = board->checkGridLegal(gridIdx);
    }

    while (!legalMove) {
        std::cout << "player " << player << " move:" << std::endl;
        idx = validateInput();

        legalMove = board->changeValue(gridIdx, idx, player);

        if (!legalMove) {
            std::cout << "Illegal move" << std::endl;
        }
        board->printState();

    }
    board->setActiveGrid(idx);
}

void botTurn(const int player, Board* board) {
    bool legalMove = false;
    int gridIdx = board->getActiveGrid();
    bool legalGrid = board->checkGridLegal(gridIdx);
    int idx;

    while (!legalGrid) {
        std::cout << "Player " << player << " choose new grid:" << std::endl;
        gridIdx = std::rand() % 9;
        legalGrid = board->checkGridLegal(gridIdx);
    }

    while (!legalMove) {
        std::cout << "player " << player << " move:" << std::endl;
        idx = rand() % 9;

        legalMove = board->changeValue(gridIdx, idx, player);

        if (!legalMove) {
            std::cout << "Illegal move" << std::endl;
        }
        board->printState();

    }

    board->setActiveGrid(idx);
}

int validateInput() {
    int val;
    std::cin >> val;

    while (val < 0 || val > 8) {
        std::cout << "Input not valid, try again: " << std::endl;
        std::cin >> val;
    }

    return val;
}