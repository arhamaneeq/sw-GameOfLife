#include "../include/renderer.hpp"


Renderer::Renderer(unsigned int w, unsigned int h) : vw(w), vh(h), filled('#'), empty(' ') {};
Renderer::~Renderer() = default;

void Renderer::clear() const {
    std::cout << "\033[H\033[J";
}

void Renderer::renderGame(const GameBoard& game) const {
    for (int y = 0; y < vh; ++y) {
        for (int x = 0; x < vw; ++x) {
            std::cout << (game.peek(x, y) ? filled : empty);
        }
        std::cout << "\n";
    }
}

void Renderer::renderHLine() const {
    for (int x = 0; x < vw; ++x) {
        std::cout << "-";
    }
    std::cout << "\n";
}

void Renderer::renderMetric(std::string label, int metric) const {
    std::cout << "  " << label << ": " << metric;
    std::cout << "\n";
}

void Renderer::renderText(std::string text) const {
    std::cout << "  " << text;
    std::cout << "\n";
}