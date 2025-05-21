#include<iostream>
#include<thread>
#include<chrono>

#include "../include/gameboard.hpp"
#include "../include/renderer.hpp"

int main() {
    const int width = 50, height = 10;
    GameBoard game(width, height);
    Renderer renderer(width, height);

    game.generateBeacon(0, 0);
    game.generateGlider(15, 15);

    while (true) {
        renderer.clear();
        renderer.renderGame(game);
        renderer.renderHLine();
        renderer.renderMetric("Population", game.getPopulation());
        renderer.renderMetric("Generation", game.getGeneration());


        game.nextStep();


        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}