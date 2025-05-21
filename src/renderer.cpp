#include "../include/renderer.hpp"


Renderer::Renderer(unsigned int w, unsigned int h) : vw(w), vh(h), frame(0) {};
Renderer::~Renderer() = default;

void Renderer::clear() const {
    std::cout << "\033[H\033[J";
}

void Renderer::renderGame(const GameBoard& game) {
    for (int y = 0; y < vh; ++y) {
        for (int x = 0; x < vw; ++x) {
            std::cout << game.peek(x, y) ? filled : empty;
        }
        std::cout << "\n";
    }
}
