#include "Grid.h"

class Board {
    
    public:
    bool changeValue(int grid, int idx, int val);
    bool checkWinCondition(int val);
    bool checkGridLegal(int grid);
    bool checkIfTied();
    void printState();
    int getActiveGrid() {return activeGrid;};
    void setActiveGrid(int gridIdx) {activeGrid = gridIdx;};

    private:
        Grid* grid[9] = {new Grid, new Grid, new Grid,
                         new Grid, new Grid, new Grid,
                         new Grid, new Grid, new Grid};

        int activeGrid = 0;
};