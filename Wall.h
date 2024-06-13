#ifndef WALL_H
#define WALL_H

#include "Drawing.h"

class Wall : public Drawing
{
public:
    Wall(int y, int x);
};

class ImmuneWall : public Drawing
{
public:
    ImmuneWall(int y, int x);
};

#endif