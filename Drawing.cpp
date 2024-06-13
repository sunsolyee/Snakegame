#include "Drawing.h"

Drawing::Drawing() : y(0), x(0), icon(' '), toggle(0), r(50)
{
    // 기본 생성자에서 멤버 변수를 직접 초기화합니다.
}

Drawing::Drawing(int y, int x, chtype ch) : y(y), x(x), icon(ch), toggle(0), r(50)
{
    // 매개변수를 받는 생성자에서 멤버 변수를 초기화합니다.
}

int Drawing::getX() const
{
    return x;
}

int Drawing::getY() const
{
    return y;
}

chtype Drawing::getIcon() const
{
    return icon;
}

void Drawing::setYX(int y, int x)
{
    this->y = y;
    this->x = x;
}