#ifndef DRAWING_H
#define DRAWING_H

#include <ncurses.h>

class Drawing {
public:
    Drawing(); // �⺻ ������ ����
    Drawing(int y, int x, chtype ch); // �Ű������� �޴� ������ ����

    int getX() const; // x ��ǥ ��ȯ �޼���
    int getY() const; // y ��ǥ ��ȯ �޼���
    chtype getIcon() const; // ������ ��ȯ �޼���
    void setYX(int y, int x); // y, x ��ǥ ���� �޼���
    int getToggle() const { return toggle; }

private:
    int y; // y ��ǥ ��� ����
    int x; // x ��ǥ ��� ����
    chtype icon; // ������ ��� ����
    int r; // �ݰ� ��� ����
};

#endif // DRAWING_H