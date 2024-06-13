#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <ncurses.h>

class Scoreboard {
public:
    Scoreboard(); // �⺻ ������
    Scoreboard(int width, int y, int x); // ������

    void initialize(int initial_length, int initial_cookie, int initial_poison, int initial_gate, int time_e, int speed_n); // �ʱ�ȭ �Լ�
    void updateMission(char type, int value); // �̼� ������Ʈ �Լ�
    void clear(); // ȭ�� ����� �Լ�
    void refresh(); // ȭ�� ���ΰ�ħ �Լ�

private:
    WINDOW* score_win; // ncurses ������ ������

    void printMission(char type, int value, int row); // �̼� ��� �Լ�
};

#endif // SCOREBOARD_H
