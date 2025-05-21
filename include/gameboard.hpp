#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include<vector>

enum class cellChange {
    Persist,
    Reproduce,
    Perish
};

class GameBoard {
    private:
        int W, H;
        int population, generation;
        std::vector<bool> grid;

        int getIndex(int x, int y) const;
        void set(int x, int y, bool val);

        cellChange nextCellStateIsLive(int x, int y) const;

    public:
        GameBoard(int w, int h);

        bool peek(int x, int y) const;
        int getPopulation() const;
        int getGeneration() const;
        int getWidth() const;
        int getHeight() const;

        void nextStep();
};

#endif