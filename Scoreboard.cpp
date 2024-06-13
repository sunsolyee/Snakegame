#include "Scoreboard.h"

Scoreboard::Scoreboard()
{
    score_win = nullptr;
}

Scoreboard::Scoreboard(int width, int y, int x)
{
    score_win = newwin(9, width / 2, y, x);
    box(score_win, 0, 0);
}

void Scoreboard::initialize(int initial_length, int initial_cookie, int initial_poison, int initial_gate, int time_e, int speed_n)
{
    clear();
    mvwprintw(score_win, 1, 2, "     Score");
    mvwprintw(score_win, 2, 2, "B:");
    mvwprintw(score_win, 3, 2, "+:");
    mvwprintw(score_win, 4, 2, "-:");
    mvwprintw(score_win, 5, 2, "G:");
    mvwprintw(score_win, 7, 2, "time:");
    mvwprintw(score_win, 6, 2, "speed:");
    refresh();
}

void Scoreboard::updateMission(char type, int value)
{
    if (type == 'B' || type == '+' || type == '-' || type == 'G') {
        printMission(type, value);
        refresh();
    }
}


void Scoreboard::clear()
{
    wclear(score_win);
}

void Scoreboard::refresh()
{
    wrefresh(score_win);
}

void Scoreboard::printMission(char type, int value, int row)
{
    switch (type) {
    case 'B':
        mvwprintw(score_win, 2, score_win->_maxx - 5, "%i", value);
        break;
    case '+':
        mvwprintw(score_win, 3, score_win->_maxx - 5, "%i", value);
        break;
    case '-':
        mvwprintw(score_win, 4, score_win->_maxx - 5, "%i", value);
        break;
    case 'G':
        mvwprintw(score_win, 5, score_win->_maxx - 5, "%i", value);
        break;
    default:
        return; // 抗寇 贸府: 肋给等 固记 鸥涝老 版快 公矫
    }
}