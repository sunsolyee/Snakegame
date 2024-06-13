#ifndef DRAWING_H
#define DRAWING_H

#include <ncurses.h>

class Drawing {
public:
    Drawing(); // 기본 생성자 선언
    Drawing(int y, int x, chtype ch); // 매개변수를 받는 생성자 선언

    int getX() const; // x 좌표 반환 메서드
    int getY() const; // y 좌표 반환 메서드
    chtype getIcon() const; // 아이콘 반환 메서드
    void setYX(int y, int x); // y, x 좌표 설정 메서드
    int getToggle() const { return toggle; }

private:
    int y; // y 좌표 멤버 변수
    int x; // x 좌표 멤버 변수
    chtype icon; // 아이콘 멤버 변수
    int r; // 반경 멤버 변수
};

#endif // DRAWING_H