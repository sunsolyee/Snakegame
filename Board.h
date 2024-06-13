#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>
#include "Drawing.h" // Drawing Ŭ���� ��� ������ �����Ѵٰ� �����մϴ�.

class Board {
public:
    Board(); // �⺻ ������
    Board(int height, int width, int speed); // �Ű������� �޴� ������

    void initialize(); // ������ �ʱ�ȭ �޼���
    void addBorder(); // �׵θ� �߰� �޼���
    void add(Drawing drawing); // �׸� �߰� �޼���
    void addAt(int y, int x, chtype ch); // Ư�� ��ġ�� ���� �߰� �޼���
    void getSpaceCoordinates(int& y, int& x); // �� ���� ��ǥ �������� �޼���
    void getWallCoordinates(int& y, int& x); // �� ��ǥ �������� �޼���
    chtype getCharat(int y, int x); // Ư�� ��ġ ���� ��ȯ �޼���
    chtype getInput(); // ����� �Է� �޴� �޼���
    void clear(); // ������ ����� �޼���
    void refresh(); // ������ �����ϴ� �޼���

    int getTimeout(); // �Է� ��� �ð� ��ȯ �޼���
    int getStartRow(); // ���� �� ��ȯ �޼���
    int getStartCol(); // ���� �� ��ȯ �޼���
    int getWidth(); // �ʺ� ��ȯ �޼���
    int getHeight(); // ���� ��ȯ �޼���

private:
    void construct(int height, int width, int speed); // ������ �ʱ�ȭ �޼���
    void setTimeout(int timeout); // �Է� ��� �ð� ���� �޼���

    WINDOW* board_win; // ncurses â ������
    int height; // ������ ����
    int width; // ������ �ʺ�
    int start_row; // ���� �� ��ġ
    int start_col; // ���� �� ��ġ
    int timeout; // �Է� ��� �ð�
};

#endif // BOARD_H