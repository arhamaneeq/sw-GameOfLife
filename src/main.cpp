#include<iostream>
#include<thread>
#include<chrono>
#include<sstream>



#include "../include/gameboard.hpp"
#include "../include/renderer.hpp"
#include "../include/gameconfig.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int width = 150, height = 50;
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
            
            if (shape == "glider") {
                GameBoardConfigurator::generateGlider(x, y, game);
            } else if (shape == "lwss") {
                GameBoardConfigurator::generateLWSS(x, y, game); 
            } else if (shape == "mwss") {
                GameBoardConfigurator::generateMWSS(x, y, game);
            } else if (shape == "hwss") {
                GameBoardConfigurator::generateHWSS(x, y, game);
            } else if (shape == "blinker") {
                GameBoardConfigurator::generateBlinker(x, y, game);
            } else if (shape == "toad") {
                GameBoardConfigurator::generateToad(x, y, game);
            } else if (shape == "beacon") {
                GameBoardConfigurator::generateBeacon(x, y, game);
            } else if (shape == "pulsar") {
                GameBoardConfigurator::generatePulsar(x, y, game);
            } else if (shape == "pentad") {
                GameBoardConfigurator::generatePentaD(x, y, game);
            } else if (shape == "gosper") {
                GameBoardConfigurator::generateGosper(x, y, game);
            } else if (shape == "diehard") {
                GameBoardConfigurator::generateDiehard(x, y, game);
            } else if (shape == "acorn") {
                GameBoardConfigurator::generateAcorn(x, y, game);
            }

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