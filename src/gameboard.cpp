#include "../include/gameboard.hpp"

int GameBoard::getIndex(int x, int y) const {
    auto wrap = [](int i, int max) {return ((i % max + max) % max);};
    return wrap(x,W) + W * wrap(y,H); // toroidal wrapping
};

cellChange GameBoard::nextCellStateIsLive(int x, int y) const {
    int livingNeighbours = 0;
    bool currentCellIsAlive = peek(x, y);

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (peek(x + i, y + j)) {
                livingNeighbours++;
            }
        }
    }

    if (!currentCellIsAlive && livingNeighbours == 3) {
        return cellChange::Reproduce; // reproduction
    } else if (currentCellIsAlive && (livingNeighbours < 2 || livingNeighbours > 3)) {
        return cellChange::Perish; // overpop / underpop
    } else {
        return cellChange::Persist; // persistence
    }
}

void GameBoard::set(int x, int y, bool val) {
    grid[getIndex(x, y)] = val;
    if (val) {population++;};
}

GameBoard::GameBoard(int w, int h) : W(w), H(h), population(0), generation(0), grid(w*h, false) {};

bool GameBoard::peek(int x, int y) const {
    return grid[getIndex(x, y)];
}

int GameBoard::getPopulation() const {
    return population;
}

int GameBoard::getGeneration() const {
    return generation;
}

int GameBoard::getWidth() const {
    return W;
}

int GameBoard::getHeight() const {
    return H;
}

void GameBoard::nextStep() {
    std::vector<bool> newGrid(W*H, false);

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            switch (nextCellStateIsLive(x, y)) {
                case cellChange::Persist:
                    newGrid[getIndex(x, y)] = grid[getIndex(x, y)];
                    break;
                case cellChange::Reproduce:
                    newGrid[getIndex(x, y)] = true;
                    population++;
                    break;
                case cellChange::Perish:
                    newGrid[getIndex(x, y)] = false;
                    population--;
                    break;
            };
        }
    }

    grid = std::move(newGrid);
    ++generation;
}

void GameBoard::generateGlider(int x, int y){
    set(x + 1, y + 0, true);
    set(x + 2, y + 1, true);
    set(x + 0, y + 2, true);
    set(x + 1, y + 2, true);
    set(x + 2, y + 2, true);
}

void GameBoard::generateToad(int x, int y) {
    set(x + 1, y + 0, true);
    set(x + 2, y + 0, true);
    set(x + 3, y + 0, true);
    set(x + 0, y + 1, true);
    set(x + 1, y + 1, true);
    set(x + 2, y + 1, true);
}

void GameBoard::generateBeacon(int x, int y) {
    set(x + 0, y + 0, true);
    set(x + 1, y + 0, true);
    set(x + 0, y + 1, true);
    set(x + 1, y + 1, true);

    set(x + 2, y + 2, true);
    set(x + 3, y + 2, true);
    set(x + 2, y + 3, true);
    set(x + 3, y + 3, true);
}