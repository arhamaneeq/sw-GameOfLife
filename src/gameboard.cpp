#include<iostream>
#include<vector>

class GameBoard {
    private:
        int W, H;
        int population, generation;
        std::vector<bool> grid;

        static inline int wrap(int i, int max) {
            return ((i % max + max) % max);
        }

        int getIndex(int x, int y) const {
            return wrap(x,W) + W * wrap(y,H);
        }

        bool nextCellState(int x, int y) {
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
                return true; // reproduction
            } else if (currentCellIsAlive && (livingNeighbours < 2 || livingNeighbours > 3)) {
                return false; // overpop / underpop
            } else {
                return currentCellIsAlive; // persistence
            }
        }

    public:
        GameBoard(int w, int h) : W(w), H(h), population(0), generation(0), grid(w*h, false) {};
        
        const bool peek(int x, int y) const {
            return grid[getIndex(x, y)];
        }
};