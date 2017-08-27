#ifndef TILE_H
#define TILE_H

class Tile
{
    private:
        const int tx;
        const int ty;
        const std::string tPlayer;

    public:
        Tile(int x, int y, std::string player);
        int getXCoord();
        int getYCoord();
        std::string getPlayer();
};

#endif
