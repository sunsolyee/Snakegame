#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>
#include "Drawing.h" // Drawing 클래스 헤더 파일을 포함한다고 가정합니다.

class Board {
public:
    Board(); // 기본 생성자
    Board(int height, int width, int speed); // 매개변수를 받는 생성자

    void initialize(); // 게임판 초기화 메서드
    void addBorder(); // 테두리 추가 메서드
    void add(Drawing drawing); // 그림 추가 메서드
    void addAt(int y, int x, chtype ch); // 특정 위치에 문자 추가 메서드
    void getSpaceCoordinates(int& y, int& x); // 빈 공간 좌표 가져오는 메서드
    void getWallCoordinates(int& y, int& x); // 벽 좌표 가져오는 메서드
    chtype getCharat(int y, int x); // 특정 위치 문자 반환 메서드
    chtype getInput(); // 사용자 입력 받는 메서드
    void clear(); // 게임판 지우는 메서드
    void refresh(); // 게임판 갱신하는 메서드

    int getTimeout(); // 입력 대기 시간 반환 메서드
    int getStartRow(); // 시작 행 반환 메서드
    int getStartCol(); // 시작 열 반환 메서드
    int getWidth(); // 너비 반환 메서드
    int getHeight(); // 높이 반환 메서드

private:
    void construct(int height, int width, int speed); // 게임판 초기화 메서드
    void setTimeout(int timeout); // 입력 대기 시간 설정 메서드

    WINDOW* board_win; // ncurses 창 포인터
    int height; // 게임판 높이
    int width; // 게임판 너비
    int start_row; // 시작 행 위치
    int start_col; // 시작 열 위치
    int timeout; // 입력 대기 시간
};

#endif // BOARD_H