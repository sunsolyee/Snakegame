#include "Wall.h"

Wall::Wall(int y, int x) : Drawing(y, x, '.') {}

ImmuneWall::ImmuneWall(int y, int x) : Drawing(y, x, 'o') {}