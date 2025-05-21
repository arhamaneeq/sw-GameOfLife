#include<iostream>
#include<vector>

class Renderer {
    private:
        unsigned int vw, vh;
        unsigned int frame;

    public:
        Renderer(unsigned int w, unsigned int h) : vw(w), vh(h), frame(0) {};
        ~Renderer() = default;

        void Clear() {
            std::cout << "\033[H\033[J";
        }

        void renderGame(const GameBoard& game) {
            for (int y = 0; y < vh; ++y) {
                for (int x = 0; x < vw; ++x) {
                    std::cout << game.peek(x, y) ? "#" : " ";
                }
                std::cout << "\n";
            }
        }
};