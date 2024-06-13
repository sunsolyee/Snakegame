#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <ncurses.h>

class Scoreboard {
public:
    Scoreboard(); // 기본 생성자
    Scoreboard(int width, int y, int x); // 생성자

    void initialize(int initial_length, int initial_cookie, int initial_poison, int initial_gate, int time_e, int speed_n); // 초기화 함수
    void updateMission(char type, int value); // 미션 업데이트 함수
    void clear(); // 화면 지우기 함수
    void refresh(); // 화면 새로고침 함수

private:
    WINDOW* score_win; // ncurses 윈도우 포인터

    void printMission(char type, int value, int row); // 미션 출력 함수
};

#endif // SCOREBOARD_H
