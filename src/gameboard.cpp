#include<vector>

class GameBoard {
    private:
        int W, H;
        mutable int population, generation;
        std::vector<bool> grid;

        int getIndex(int x, int y) const {

            auto wrap = [](int i, int max) {return ((i % max + max) % max);};
            return wrap(x,W) + W * wrap(y,H); // toroidal wrapping
        }

        bool nextCellStateIsLive(int x, int y) const {
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
                population++;
                return true; // reproduction
            } else if (currentCellIsAlive && (livingNeighbours < 2 || livingNeighbours > 3)) {
                population--;
                return false; // overpop / underpop
            } else {
                return currentCellIsAlive; // persistence
            }
        }

        void set(int x, int y, bool val) {
            grid[getIndex(x, y)] = val;
        }

    public:
        GameBoard(int w, int h) : W(w), H(h), population(0), generation(0), grid(w*h, false) {};
        
        bool peek(int x, int y) const {
            return grid[getIndex(x, y)];
        }
        
        int getPopulation() const {
            return population;
        }

        int getGeneration() const {
            return generation;
        }

        int getWidth() const {
            return W;
        }

        int getHeight() const {
            return H;
        }

        void nextStep() {
            std::vector<bool> newGrid(W*H, false);

            for (int y = 0; y < H; y++) {
                for (int x = 0; x < W; x++) {
                    newGrid[getIndex(x, y)] = nextCellStateIsLive(x, y);
                }
            }

            grid = std::move(newGrid);
            ++generation;
        }
};