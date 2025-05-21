#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "gameboard.hpp"
#include<vector>
#include<iostream>
#include<string>

class Renderer {
    private:
        unsigned int vw, vh;
        char filled, empty;

    public:
        Renderer(unsigned int w, unsigned int h);
        ~Renderer();

        void clear() const;

        // Render Functions
        void renderGame(const GameBoard& game) const;
        void renderHLine() const;

        // Text
        void renderMetric(std::string label, int metric) const;
        void renderText(std::string text) const;

};

#endif