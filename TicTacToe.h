#include "Grid.h"

class TicTacToe {
    
    public:
    bool changeValue(int grid, int idx, int val);
    bool checkWinCondition(int val);
    bool checkGridLegal(int grid);
    void printState();

    private:
        Grid* grid[9] = {new Grid, new Grid, new Grid,
                         new Grid, new Grid, new Grid,
                         new Grid, new Grid, new Grid};
};