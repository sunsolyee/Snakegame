
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
    initscr();  // ncurses 초기화
    refresh();  // 화면 초기화

    noecho();   // 입력값이 화면에 표시되지 않게 함

    Snakegame game(BOARD_ROWS, BOARD_COLS, 200);  // Snake 게임 객체 생성

    while (!game.isOver())  // 게임이 끝나지 않은 동안 반복
    {
        game.processInput();  // 사용자 입력 처리
        game.updateState();   // 게임 상태 업데이트
        game.redraw();        // 화면 다시 그리기
    }

    endwin();  // ncurses 종료

    cout << "Your final score: " << game.getScore() << " points" << endl;  // 최종 점수 출력

    return 0;
}