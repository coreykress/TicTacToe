//main game
#include <iostream>
#include <limits>
#include <string>
#include "game.h"
#include "tile.h"

Game::Game(){}

bool Game::checkForWin(int x, int y, std::string currentPlayer)
{
    //check horizontal
    for (int i = 0; i < 3; i++) {
        if (board[x][i] == NULL || board[x][i]->getPlayer() != currentPlayer) {
            break;
        }
        if (i == 2) {
            return true;
        }
    }

    //check vertical
    for (int i = 0; i < 3; i++) {
        if (board[i][y] == NULL || board[i][y]->getPlayer() != currentPlayer) {
            break;
        }

        if (i == 2) {
            return true;
        }
    }

    //check diagonal //very sloppy
    if (board[1][1] == NULL || board[1][1]->getPlayer() != currentPlayer) {
        return false;
    }

    if ( (x + y) % 2  == 1) {
        return false;
    }
    std::cout << "here3";

    if ( (x + y) == 0 ) {
        return board[2][2] != NULL && board[2][2]->getPlayer() == currentPlayer;
    }

    if ( (x + y) == 4) {
        return board[0][0] != NULL && board[0][0]->getPlayer() == currentPlayer;
    }

    if (x == 0) {
        return board[2][0] != NULL && board[2][0]->getPlayer() == currentPlayer;
    }

    if (x == 2) {
        return board[0][2] != NULL && board[0][2]->getPlayer() == currentPlayer;
    }

    return false;
}

std::string Game::printBoard()
{
    //first iteration, just iterate; optimise with recursion
    std::string buffer = "      1   2   3 \n\n";
    for (int i = 0; i < 3 ; i++) {
        std::string row = std::to_string(i + 1) + " :  ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == NULL) {
                row +=  "   ";
            } else {
                row += " " + board[i][j]->getPlayer() + " ";
            }
            if (j < 2) {
                row += "|";
            }
        }
        row += "\n";
        buffer += row;

        if (i < 2) {
            std::string baseRow = "     ---|---|---\n";
            buffer += baseRow;
        }

        row = "";
    }
    return buffer;
}

int Game::getInput(std::string coord, std::string currentPlayer)
{
    int currentValue = 0;
    do {
        std::cout << "Player " << currentPlayer << " please enter " << coord << " coordinate: "<< std::endl;
        std::cin >> currentValue;

        if (std::cin.fail() || currentValue < 1 || currentValue > 3) {
            std::cout << "Please enter an integer from 1 to 3" << std::endl;
            currentValue = 0;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (currentValue == 0);

    return currentValue;
};

bool Game::validCoordinate(int x, int y)
{
    Tile *currentTile = board[x][y];
    if (currentTile == NULL) {
        return true;
    }

    return false;
}

int Game::main ()
{
    std::string Player1 = "X";
    std::string Player2 = "O";
    bool gameOver = false;
    std::string currentPlayer = Player1;

    std::cout << printBoard() << std::endl;

    //game loop
    while(!gameOver)
    {
        int currentX;
        int currentY;
        int xPrime;
        int yPrime;

        Tile* newTile;
        bool validCoordinates = false;

        do {
            currentX = getInput("Row", currentPlayer);
            currentY = getInput("Column", currentPlayer);
            xPrime = currentX - 1;
            yPrime = currentY - 1;

            validCoordinates = validCoordinate(xPrime, yPrime);
            if (!validCoordinates) {
                std::cout << "Coordinates are invalid, please try again" << std::endl;
            }
        } while (!validCoordinates);

        //create new tile
        board[xPrime][yPrime] = new Tile(xPrime, yPrime, currentPlayer);

        //checkforwin
        if (checkForWin(xPrime, yPrime, currentPlayer)) {
            std::cout << "player " << currentPlayer << " WINS!" << std::endl;
            gameOver = true;
            std::cout << printBoard() << std::endl;
            break;
        }

        //changeplayer
        currentPlayer = currentPlayer == Player1 ? Player2 : Player1;

        std::cout << "player is now " << currentPlayer << std::endl;

        //print out game board
        std::cout << printBoard() << std::endl;
    }

    return 0;
}
