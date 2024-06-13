#ifndef SNAKE_H
#define SNAKE_H

#include "Drawing.h"
#include <deque>

enum class Direction {
    up,
    down,
    left,
    right
};

class SnakePiece : public Drawing {
public:
    SnakePiece();
    SnakePiece(int y, int x);
};

class Snake {
public:
    Snake();

    void addPiece(SnakePiece piece);
    void removePiece();
    SnakePiece tail();
    SnakePiece head();
    Direction getDirection();
    int setDirection(Direction d);
    SnakePiece nextHead();
    int getSize();

private:
    std::deque<SnakePiece> prev_pieces;
    Direction cur_direction;
};

#endif // SNAKE_H