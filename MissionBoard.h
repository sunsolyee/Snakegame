#ifndef MISSIONBOARD_H
#define MISSIONBOARD_H

#include <ncurses.h>

class MissionBoard {
public:
    MissionBoard();
    MissionBoard(int width, int y, int x);
    void initialize(char initial_length, char initial_cookie, char initial_poison, char initial_gate, char initial_speed);
    void updateMission(char type, char value);
    void clear();
    void refresh();

private:
    WINDOW* mission_win;
    void printMission(char type, char value);
};

#endif // MISSIONBOARD_H