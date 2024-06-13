
#include <ncurses.h>
#include "Board.h"
#include "SnakeGame.h"
#include "Drawing.h"
#include <iostream>
#include <time.h>
#include <iostream>
using namespace std;


#define BOARD_DIM 30
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5
int main()
{
    initscr();  // ncurses �ʱ�ȭ
    refresh();  // ȭ�� �ʱ�ȭ

    noecho();   // �Է°��� ȭ�鿡 ǥ�õ��� �ʰ� ��

    Snakegame game(BOARD_ROWS, BOARD_COLS, 200);  // Snake ���� ��ü ����

    while (!game.isOver())  // ������ ������ ���� ���� �ݺ�
    {
        game.processInput();  // ����� �Է� ó��
        game.updateState();   // ���� ���� ������Ʈ
        game.redraw();        // ȭ�� �ٽ� �׸���
    }

    endwin();  // ncurses ����

    cout << "Your final score: " << game.getScore() << " points" << endl;  // ���� ���� ���

    return 0;
}