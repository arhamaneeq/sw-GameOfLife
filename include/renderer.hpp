#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "gameboard.hpp"
#include<vector>
#include<iostream>

class Renderer {
    private:
        unsigned int vw, vh;
        unsigned int frame;
        char filled, empty;

    public:
        Renderer(unsigned int w, unsigned int h);
        ~Renderer();

        void clear() const;
        void renderGame(const GameBoard& game);

};

#endif