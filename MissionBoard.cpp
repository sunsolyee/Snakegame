#include "MissionBoard.h"

MissionBoard::MissionBoard()
{
    mission_win = nullptr;
}

MissionBoard::MissionBoard(int width, int y, int x)
{
    mission_win = newwin(8, width / 2, y, x);
    box(mission_win, 0, 0);
}

void MissionBoard::initialize(char initial_length, char initial_cookie, char initial_poison, char initial_gate, char initial_speed)
{
    clear();
    mvwprintw(mission_win, 1, 2, "     Mission");
    printMission('B', initial_length);
    printMission('+', initial_cookie);
    printMission('-', initial_poison);
    printMission('G', initial_gate);
    printMission('S', initial_speed);
    refresh();
}

void MissionBoard::updateMission(char type, char value)
{
    if (type == 'B' || type == '+' || type == '-' || type == 'G' || type == 'S') {
        printMission(type, value);
        refresh();
    }
}

void MissionBoard::clear()
{
    wclear(mission_win);
}

void MissionBoard::refresh()
{
    wrefresh(mission_win);
}

void MissionBoard::printMission(char type, char value)
{
    int row;
    switch (type) {
    case 'B':
        row = 2;
        break;
    case '+':
        row = 3;
        break;
    case '-':
        row = 4;
        break;
    case 'G':
        row = 5;
        break;
    case 'S':
        row = 6;
        break;
    default:
        return; // 抗寇 贸府: 肋给等 固记 鸥涝老 版快 公矫
    }
    mvwprintw(mission_win, row, 2, "%c: (%c)", type, value);
}