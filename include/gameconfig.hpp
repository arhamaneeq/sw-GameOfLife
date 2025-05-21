#include "gameboard.hpp"

class GameBoardConfigurator {
    private:

    public:
        static void genFromText(std::string feed, GameBoard& game);

        static void generateGlider(int x, int y, GameBoard& game);
        static void generateLWSS(int x, int y, GameBoard& game);
        static void generateMWSS(int x, int y, GameBoard& game);
        static void generateHWSS(int x, int y, GameBoard& game);

        static void generateBlinker(int x, int y, GameBoard& game);
        static void    generateToad(int x, int y, GameBoard& game);
        static void  generateBeacon(int x, int y, GameBoard& game);
        static void  generatePulsar(int x, int y, GameBoard& game);
        static void  generatePentaD(int x, int y, GameBoard& game);

        static void generateGosper(int x, int y, GameBoard& game);

        static void generateDiehard(int x, int y, GameBoard& game);
        static void generateAcorn(int x, int y, GameBoard& game);



};