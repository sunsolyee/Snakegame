#include "Drawing.h"

Drawing::Drawing() : y(0), x(0), icon(' '), toggle(0), r(50)
{
    // �⺻ �����ڿ��� ��� ������ ���� �ʱ�ȭ�մϴ�.
}

Drawing::Drawing(int y, int x, chtype ch) : y(y), x(x), icon(ch), toggle(0), r(50)
{
    // �Ű������� �޴� �����ڿ��� ��� ������ �ʱ�ȭ�մϴ�.
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