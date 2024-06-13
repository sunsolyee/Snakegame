#ifndef POISON_H
#define POISON_H
#include <ncurses.h>
#include "Drawing.h"

class Poison : public Drawing
{
public:
    Poison(int y, int x);
};

#endif 