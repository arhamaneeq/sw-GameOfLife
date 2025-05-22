#include "../include/renderer.hpp"


Renderer::Renderer(unsigned int w, unsigned int h) : vw(w), vh(h), filled('#'), empty(' ') {};
Renderer::~Renderer() = default;

void Renderer::clear() const {
    std::cout << "\033[H\033[J";
}

void Renderer::renderGame(const GameBoard& game) const {
    std::ostringstream oss;

    for (int y = 0; y < vh; ++y) {
        for (int x = 0; x < vw; ++x) {
            oss << (game.peek(x, y) ? filled : empty);
        }
        oss << "\n";
    }

    std::cout << oss.str() << std::flush;
}

void Renderer::renderHLine() const {
    std::ostringstream oss;

    for (int x = 0; x < vw; ++x) {
        oss << "-";
    }
    oss << "\n";
    std::cout << oss.str() << std::flush;
}

void Renderer::renderELine() const {
    std::cout << "\n";
}

void Renderer::renderMetric(std::string label, int metric) const {
    std::ostringstream oss;
    oss << "  " << label << ": " << metric << "\n";
    std::cout << oss.str() << std::flush;
}

void Renderer::renderText(std::string text) const {
    std::ostringstream oss;
    oss << "  " << text << "\n";
    std::cout << oss.str() << std::flush;
}