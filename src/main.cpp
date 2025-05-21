#include<iostream>
#include<thread>
#include<chrono>
#include<sstream>

#include "../include/gameboard.hpp"
#include "../include/renderer.hpp"
#include "../include/gameconfig.hpp"

int main() {
    const int width = 50, height = 10;
    GameBoard game(width, height);
    Renderer renderer(width, height);

    while (true) {
        renderer.clear();
        renderer.renderGame(game);
        renderer.renderHLine();
        renderer.renderText("Conway's Game of Life!");
        renderer.renderHLine();
        renderer.renderText("Commands: ");
        renderer.renderText("  p x y      | flips (x,y)");
        renderer.renderText("  g name x y | generate [name] at (x,y)");
        renderer.renderText("  r          | run the game");
        renderer.renderELine();

        std::string input;
        
        std::cout << "> ";
        std::getline(std::cin, input);
        std::istringstream iss(input);

        std::string cmd;
        iss >> cmd;

        if (cmd == "p") {
            int x, y;
            if (iss >> x >> y) {
                game.set(x, y, !game.peek(x, y));
            }
        } else if (cmd == "g") {
            std::string shape;
            int x, y;
            iss >> shape >> x >> y;
            // TODO:

        } else if (cmd == "r") {
            break;
        }


        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

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