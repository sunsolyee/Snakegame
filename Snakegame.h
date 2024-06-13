// Snakegame.h
#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "Board.h"
#include "Scoreboard.h"
#include "MissionBoard.h"
#include "Snake.h"
#include "Cookie.h"
#include "Poison.h"
#include "Speed.h"
#include "Gate.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

class Snakegame {
public:
    Snakegame(int height, int width, int speed);
    ~Snakegame();

    void initializeGame();
    void processInput();
    void updateState();
    void redraw();
    bool isOver();
    int getScore();
    void replayGame();

private:
    Board board;
    Scoreboard scoreboard;
    MissionBoard missionboard;
    Snake snake;
    Cookie* cookie;
    Poison* poison;
    Gate* gate[2];
    int gate_c;
    int score;
    int length;
    int cookie_item;
    int poison_item;
    int gate_item;
    int maxLength;
    int new_wall;
    time_t time_s;
    int stage;
    bool game_over;
    std::vector<std::string> replayData;

    void initializeSnake();
    void createItems();
    void createCookie();
    void createPoison();
    void createGate();
    void createMap();
    void handleDirectionChange(Direction dir);
    void handlePause(int old_timeout);
    void handleNextPiece(Piece next);
    void updateObject(Object* obj);
    void updateGatePosition(Gate* g);
    void updateMissionBoard();
};

#endif // SNAKEGAME_H