#include<iostream>
#include<thread>
#include<chrono>

#include "../include/gameboard.hpp"
#include "../include/renderer.hpp"

int main() {
    const int width = 40, height = 10;
    GameBoard game(width, height);
    Renderer renderer(width, height);

    while (true) {
        renderer.clear();
        renderer.renderGame(game);
        renderer.renderHLine();
        renderer.renderMetric("Population", game.getPopulation());
        renderer.renderMetric("Generation", game.getGeneration());


        game.nextStep();


        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}