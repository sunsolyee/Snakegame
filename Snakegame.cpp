// Snakegame.cpp
#include "Snakegame.h"

Snakegame::Snakegame(int height, int width, int speed)
    : board(Board(height, width, speed)),
    scoreboard(Scoreboard(width, board.getStartRow() + height, board.getStartCol())),
    missionboard(MissionBoard(width, board.getStartRow() + height, board.getStartCol() + width / 2)),
    snake(Snake()),
    cookie(nullptr),
    poison(nullptr),
    speed(nullptr),
    gate_c(70),
    score(0),
    length(3),
    cookie_item(0),
    poison_item(0),
    gate_item(0),
    maxLength(6),
    speed_n(200),
    view_speed(200),
    new_wall(30),
    time_s(time(NULL)),
    stage(0),
    game_over(false)
{
    srand(time(NULL)); // Random �ʱ�ȭ

    board.initialize(); // ���� �ʱ�ȭ

    int timeElapsed = time(NULL) - time_s;
    scoreboard.initialize(score, length, poison_item, cookie_item, gate_item, timeElapsed);

    char initial_length = 'X', initial_cookie = 'X', initial_poison = 'X', initial_gate = 'X', initial_speed = 'X';
    missionboard.initialize(initial_length, initial_cookie, initial_poison, initial_gate, initial_speed);

    createMap();

    // Snake �ʱ�ȭ �� ���� ����
    snake.setDirection(Direction::down);
}

Snakegame::~Snakegame()
{
    delete cookie;
    delete poison;
    delete speed;
    delete gate[0];
    delete gate[1];
}

void Snakegame::initializeGame()
{
    // �� �ʱ�ȭ
    initializeSnake();

    // ������ ����
    createItems();
}

void Snakegame::processInput()
{
    chtype input = board.getInput();
    int old_timeout = board.getTimeout();

    switch (input)
    {
    case KEY_UP:
    case 'w':
        handleDirectionChange(Direction::up);
        break;
    case KEY_DOWN:
    case 's':
        handleDirectionChange(Direction::down);
        break;
    case KEY_RIGHT:
    case 'd':
        handleDirectionChange(Direction::right);
        break;
    case KEY_LEFT:
    case 'a':
        handleDirectionChange(Direction::left);
        break;
    case 'p':
        handlePause(old_timeout);
        break;
    default:
        break;
    }
}

void Snakegame::updateState()
{
    handleNextPiece(snake.nextHead());

    // Update Cookie
    if (cookie != nullptr)
    {
        updateObject(cookie);
    }
    else
    {
        createCookie();
    }


    // Update Poison
    if (poison != nullptr)
    {
        updateObject(poison);
    }
    else
    {
        createPoison();
    }

    // Update Gate
    if (gate[0] == nullptr && gate_c == 0)
    {
        gate_c = 70;
        createGate();
    }
    else if (gate[0] != nullptr)
    {
        updateObject(gate[0]);

        if (gate[0]->toggle == gate[0]->r)
        {
            gate[0]->toggle = 0;
            updateGatePosition(gate[0]);
            board.add(*gate[0]);

            updateObject(gate[1]);
            updateGatePosition(gate[1]);
            board.add(*gate[1]);
        }

    }


    // Generate New Wall
    if (--new_wall == 0)
    {
        new_wall = 30;
        int m, n;
        board.getSpaceCoordinates(m, n);
        board.add(Wall(m, n));
    }

    // Mission Board Updates
    updateMissionBoard();

    // Game Over Check
    if (snake.getSize() <= 2)
    {
        game_over = true;
    }

    // ������ �����͸� ���ڿ��� ����� ���Ϳ� �߰�
    std::string gameState = std::to_string(snake.getHead().getY()) + "," +
        std::to_string(snake.getHead().getX()) + "," +
        std::to_string(score) + "," +
        std::to_string(length) + "," +
        std::to_string(cookie_item) + "," +
        std::to_string(poison_item) + "," +
        std::to_string(gate_item) + "," +
        std::to_string(view_speed);

    replayData.push_back(gameState);
}

void Snakegame::redraw()
{
    board.refresh();
    scoreboard.refresh();
    missionboard.refresh();
}

bool Snakegame::isOver()
{
    return game_over;
}

int Snakegame::getScore()
{
    return score;
}

void Snakegame::replayGame()
{
    // ���� ������ �ʱ�ȭ
    stage = 0;
    score = 0;
    length = 3;
    cookie_item = 0;
    poison_item = 0;
    gate_item = 0;
    maxLength = 6;
    speed_n = 200;
    view_speed = 200;
    time_s = time(NULL);
    game_over = false;
    snake = Snake();
    board.initialize();
    scoreboard.initialize(score, length, poison_item, cookie_item, gate_item, 0, speed_n);
    missionboard.initialize('X', 'X', 'X', 'X', 'X');
    createMap();

    // ���÷��� �����͸� ����Ͽ� ���� ���¸� ���
    for (const std::string& gameState : replayData)
    {
        // ���ڿ��� �Ľ��Ͽ� �ʿ��� ������ ����
        std::istringstream iss(gameState);
        std::string token;
        int tokenIndex = 0;
        int y, x;
        while (std::getline(iss, token, ','))
        {
            switch (tokenIndex)
            {
            case 0: // y ��ǥ
                y = std::stoi(token);
                break;
            case 1: // x ��ǥ
                x = std::stoi(token);
                break;
            case 2: // ����
                score = std::stoi(token);
                break;
            case 3: // �� ����
                length = std::stoi(token);
                break;
            case 4: // ��Ű ������ ��
                cookie_item = std::stoi(token);
                break;
            case 5: // �� ������ ��
                poison_item = std::stoi(token);
                break;
            case 6: // ����Ʈ ������ ��
                gate_item = std::stoi(token);
                break;
            default:
                break;
            }
            tokenIndex++;
        }

        // ���� ��ġ�� �����ϰ� ���忡 �߰�
        snake.setPosition(y, x);
        board.add(snake.getHead());

        // ���� ���� ����� ���� ��� ���
        usleep(view_speed * 1000);

        // ���� ȭ�� ����
        redraw();
    }
}

void Snakegame::initializeSnake()
{
    snake.initialize(board.getHeight(), board.getWidth());
}

void Snakegame::createItems()
{
    createCookie();
    createPoison();
    createSpeed();
    createGate();
}

void Snakegame::createCookie()
{
    int m, n;
    board.getSpaceCoordinates(m, n);
    cookie = new Cookie(m, n);
    board.add(*cookie);
}

void Snakegame::createPoison()
{
    int m, n;
    board.getSpaceCoordinates(m, n);
    poison = new Poison(m, n);
    board.add(*poison);
}

void Snakegame::createGate()
{
    int m, n;
    board.getSpaceCoordinates(m, n);
    gate[0] = new Gate(m, n, true);
    board.add(*gate[0]);

    board.getSpaceCoordinates(m, n);
    gate[1] = new Gate(m, n, false);
    board.add(*gate[1]);
}

void Snakegame::createMap()
{
    int wall_count = board.getHeight() * board.getWidth() / 50; // ���� ũ�⿡ ���� ���� ���� ������ �� �ֽ��ϴ�.
    for (int i = 0; i < wall_count; ++i)
    {
        int m, n;
        board.getSpaceCoordinates(m, n);
        board.add(Wall(m, n));
    }
}

void Snakegame::handleDirectionChange(Direction dir)
{
    snake.setDirection(dir);
}

void Snakegame::handlePause(int old_timeout)
{
    board.setTimeout(old_timeout == 0 ? 100 : 0); // 0�̸� �Ͻ� ���� ����, �ƴϸ� 100ms�� ����
}

void Snakegame::handleNextPiece(Piece next)
{
    // ���� ���� �Ӹ��� ������ ������ �Ѿ�� �ʵ��� ó��
    if (board.isOutOfBounds(next))
    {
        snake.kill(); // ���� ���̰� ���� ����
        game_over = true;
        return;
    }

    snake.move(next);

    // ������ ó��
    switch (board.get(next.getY(), next.getX())->getObj())
    {
    case '+':
        cookie_item++;
        score += 10;
        snake.grow(2);
        delete cookie;
        cookie = nullptr;
        break;
    case '-':
        poison_item++;
        score -= 10;
        snake.shrink();
        delete poison;
        poison = nullptr;
        break;
    case 'G':
        gate_item++;
        score += 20;
        delete gate[0];
        delete gate[1];
        gate[0] = nullptr;
        gate[1] = nullptr;
        break;
    default:
        break;
    }
}

void Snakegame::updateObject(Object* obj)
{
    // ������Ʈ�� ���忡�� �����ϰ� ���ο� ��ġ�� �߰�
    int m, n;
    board.getSpaceCoordinates(m, n);
    board.remove(*obj);
    obj->setXY(m, n);
    board.add(*obj);
}

void Snakegame::updateGatePosition(Gate* g)
{
    int m, n;
    board.getSpaceCoordinates(m, n);
    g->setXY(m, n);
}

void Snakegame::updateMissionBoard()
{
    missionboard.updateMission('B', maxLength);
    missionboard.updateMission('+', cookie_item);
    missionboard.updateMission('-', poison_item);
    missionboard.updateMission('G', gate_item);
}