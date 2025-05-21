#include "../include/gameconfig.hpp"


// Statics
void GameBoardConfigurator::generateGlider(int x, int y, GameBoard& game) {
    game.set(x + 1, y + 0, true);
    game.set(x + 2, y + 1, true);
    game.set(x + 0, y + 2, true);
    game.set(x + 1, y + 2, true);
    game.set(x + 2, y + 2, true);
}

void GameBoardConfigurator::generateLWSS(int x, int y, GameBoard& game) {
    game.set(x + 1, y + 0, true);
    game.set(x + 4, y + 0, true);
    game.set(x + 0, y + 1, true);
    game.set(x + 0, y + 2, true);
    game.set(x + 4, y + 2, true);
    game.set(x + 0, y + 3, true);
    game.set(x + 1, y + 3, true);
    game.set(x + 2, y + 3, true);
    game.set(x + 3, y + 3, true);
}

void GameBoardConfigurator::generateMWSS(int x, int y, GameBoard& game) {
    game.set(x + 1, y + 0, true);
    game.set(x + 2, y + 0, true);
    game.set(x + 3, y + 0, true);
    game.set(x + 4, y + 0, true);
    game.set(x + 0, y + 1, true);
    game.set(x + 0, y + 2, true);
    game.set(x + 4, y + 2, true);
    game.set(x + 0, y + 3, true);
    game.set(x + 1, y + 3, true);
    game.set(x + 2, y + 3, true);
    game.set(x + 3, y + 3, true);
}

void GameBoardConfigurator::generateHWSS(int x, int y, GameBoard& game) {
    game.set(x + 1, y + 0, true);
    game.set(x + 2, y + 0, true);
    game.set(x + 3, y + 0, true);
    game.set(x + 4, y + 0, true);
    game.set(x + 5, y + 0, true);
    game.set(x + 0, y + 1, true);
    game.set(x + 0, y + 2, true);
    game.set(x + 5, y + 2, true);
    game.set(x + 0, y + 3, true);
    game.set(x + 1, y + 3, true);
    game.set(x + 2, y + 3, true);
    game.set(x + 3, y + 3, true);
    game.set(x + 4, y + 3, true);
}

// Oscillator
void GameBoardConfigurator::generateBlinker(int x, int y, GameBoard& game) {
    game.set(x + 0, y + 1, true);
    game.set(x + 1, y + 1, true);
    game.set(x + 2, y + 1, true);
}

void GameBoardConfigurator::generateToad(int x, int y, GameBoard& game) {
    game.set(x + 1, y + 0, true);
    game.set(x + 2, y + 0, true);
    game.set(x + 3, y + 0, true);
    game.set(x + 0, y + 1, true);
    game.set(x + 1, y + 1, true);
    game.set(x + 2, y + 1, true);
}

void GameBoardConfigurator::generateBeacon(int x, int y, GameBoard& game) {
    game.set(x + 0, y + 0, true);
    game.set(x + 1, y + 0, true);
    game.set(x + 0, y + 1, true);
    game.set(x + 1, y + 1, true);

    game.set(x + 2, y + 2, true);
    game.set(x + 3, y + 2, true);
    game.set(x + 2, y + 3, true);
    game.set(x + 3, y + 3, true);
}

void GameBoardConfigurator::generatePulsar(int x, int y, GameBoard& game) {
    int dx[] = {2, 3, 4, 8, 9, 10};
    int dy[] = {0, 5, 7, 12};

    for (int i : dx) {
        for (int j : dy) {
            game.set(x + i, y + j, true);
            game.set(x + j, y + i, true);
        }
    }
}

void GameBoardConfigurator::generatePentaD(int x, int y, GameBoard& game) {
    game.set(x + 0, y + 1, true);
    game.set(x + 1, y + 1, true);
    game.set(x + 2, y + 1, true);
    game.set(x + 3, y + 0, true);
    game.set(x + 3, y + 1, true);
    game.set(x + 3, y + 2, true);
    game.set(x + 4, y + 1, true);
    game.set(x + 5, y + 1, true);
    game.set(x + 6, y + 0, true);
    game.set(x + 6, y + 1, true);
    game.set(x + 6, y + 2, true);
    game.set(x + 7, y + 1, true);
    game.set(x + 8, y + 1, true);
}

// Guns
void GameBoardConfigurator::generateGosper(int x, int y, GameBoard& game) {
    int pattern[][2] = {
        {0,4},{0,5},{1,4},{1,5},

        {10,4},{10,5},{10,6},
        {11,3},{11,7},
        {12,2},{12,8},
        {13,2},{13,8},
        {14,5},
        {15,3},{15,7},
        {16,4},{16,5},{16,6},
        {17,5},

        {20,2},{20,3},{20,4},
        {21,2},{21,3},{21,4},
        {22,1},{22,5},
        {24,0},{24,1},{24,5},{24,6},

        {34,2},{34,3},
        {35,2},{35,3}
    };

    for (auto& cell : pattern)
        game.set(x + cell[0], y + cell[1], true);
}

// Methusaleh
void GameBoardConfigurator::generateDiehard(int x, int y, GameBoard& game) {
    game.set(x + 0, y + 1, true);
    game.set(x + 1, y + 1, true);
    game.set(x + 1, y + 2, true);
    game.set(x + 6, y + 2, true);
    game.set(x + 7, y + 0, true);
    game.set(x + 7, y + 2, true);
    game.set(x + 8, y + 2, true);
}

void GameBoardConfigurator::generateAcorn(int x, int y, GameBoard& game) {
    game.set(x + 1, y + 0, true);
    game.set(x + 3, y + 1, true);
    game.set(x + 0, y + 2, true);
    game.set(x + 1, y + 2, true);
    game.set(x + 4, y + 2, true);
    game.set(x + 5, y + 2, true);
    game.set(x + 6, y + 2, true);
}