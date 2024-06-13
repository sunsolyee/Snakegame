#include <ncurses.h>
#include "Board.h"
#include <iostream>
#include "Time.h"

Board::Board()
{
    construct(0, 0, 250); // 초기 속도는 250
}

Board::Board(int height, int width, int speed)
{
    construct(height, width, speed);
}

void Board::initialize()
{
    clear();
    refresh();
}

void Board::addBorder()
{
    box(board_win, 0, 0);
}

void Board::add(Drawing drawing)
{
    addAt(drawing.getY(), drawing.getX(), drawing.getIcon());
}

void Board::addAt(int y, int x, chtype ch)
{
    mvwaddch(board_win, y, x, ch);
}

void Board::getSpaceCoordinates(int& y, int& x)
{
    // 빈 공간을 찾을 때까지 반복
    do {
        y = rand() % height;
        x = rand() % width;
    } while (mvwinch(board_win, y, x) != ' ');
}

void Board::getWallCoordinates(int& y, int& x)
{
    // 벽을 찾을 때까지 반복
    do {
        y = rand() % height;
        x = rand() % width;
    } while (mvwinch(board_win, y, x) != '.');
}

chtype Board::getCharat(int y, int x)
{
    return mvwinch(board_win, y, x);
}

chtype Board::getInput()
{
    chtype input = ERR;

    // 입력 대기 시간 설정
    wtimeout(board_win, timeout);

    // 입력 받기
    int ch = wgetch(board_win);

    // 입력이 있으면 반환
    if (ch != ERR) {
        input = ch;
    }

    return input;
}

void Board::clear()
{
    wclear(board_win);
    addBorder();
}

void Board::refresh()
{
    wrefresh(board_win);
}

void Board::construct(int height, int width, int speed)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    this->height = height;
    this->width = width;

    start_row = (yMax / 2) - (height / 2);
    start_col = (xMax / 2) - (width / 2);

    board_win = newwin(height, width, start_row, start_col);
    timeout = speed;

    keypad(board_win, true);
}

int Board::getTimeout()
{
    return timeout;
}

int Board::getStartRow()
{
    return start_row;
}

int Board::getStartCol()
{
    return start_col;
}

int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}