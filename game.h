#ifndef GAME_H
#define GAME_H

#include "tile.h"

class Game
{
    private:
        const std::string Player1;
        const std::string Player2;
        bool gameOver;
        std::string currentPlayer;
        Tile* board[3][3];

        int getInput(std::string coord, std::string player);
        bool validCoordinate(int x, int y);
        bool checkForWin(int x, int y, std::string player);
        std::string printBoard();

    public:
        Game();
        int main();
};

#endif
