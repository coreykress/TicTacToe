//Tile.cpp
#include <string>
#include "tile.h"

Tile::Tile(int x, int y, std::string player) : tx(x), ty(y), tPlayer(player) {}

int Tile::getXCoord()
{
    return tx;
}

int Tile::getYCoord()
{
    return ty;
}

std::string Tile::getPlayer()
{
    return tPlayer;
}
