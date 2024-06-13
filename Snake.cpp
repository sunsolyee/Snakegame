#include "Snake.h"

SnakePiece::SnakePiece() : Drawing(0, 0, '#') {}

SnakePiece::SnakePiece(int y, int x) : Drawing(y, x, '#') {}

Snake::Snake() : cur_direction(Direction::down) {}

void Snake::addPiece(SnakePiece piece)
{
    prev_pieces.push_back(piece);
}

void Snake::removePiece()
{
    prev_pieces.pop_front();
}

SnakePiece Snake::tail()
{
    return prev_pieces.front();
}

SnakePiece Snake::head()
{
    return prev_pieces.back();
}

Direction Snake::getDirection()
{
    return cur_direction;
}

int Snake::setDirection(Direction d)
{
    if (cur_direction == Direction::up && d == Direction::down)
        return 1;
    if (cur_direction == Direction::down && d == Direction::up)
        return 1;
    if (cur_direction == Direction::left && d == Direction::right)
        return 1;
    if (cur_direction == Direction::right && d == Direction::left)
        return 1;

    cur_direction = d;
    return 0;
}

SnakePiece Snake::nextHead()
{
    int row = head().getY();
    int col = head().getX();

    switch (cur_direction)
    {
    case Direction::down:
        row++;
        break;
    case Direction::up:
        row--;
        break;
    case Direction::left:
        col--;
        break;
    case Direction::right:
        col++;
        break;
    }

    return SnakePiece(row, col);
}

int Snake::getSize()
{
    return prev_pieces.size();
}