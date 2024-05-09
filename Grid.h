class Grid{

    public:
        Grid grid() {};
        bool changeValueAtIdx(int idx, int val);
        void checkWinCondition(int val);
        void printState();
        void printLine(int idxLine);
        int getWinState() { return winState; };
    private:
        int gridValues[9] = {0,0,0,0,0,0,0,0,0};
        int winState = 0;
        
};