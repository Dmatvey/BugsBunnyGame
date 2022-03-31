#include <assert.h>
#include "CheaterPlayer.h"
#include "Board.h"
#include "Player.h"
#include<time.h>

class Player;

CheaterPlayer::CheaterPlayer()
{
    symbol = ' ';
    name = " ";
    currentPositionX = -1;
    currentPositionY = -1;
    playerID = NULL;
    carrotFlag = false;
    isAlive = false;
}

CheaterPlayer::CheaterPlayer(int pid, char c, std::string n)
{
    symbol = c;
    name = n;
    currentPositionX = -1;
    currentPositionY = -1;
    playerID = pid;
    carrotFlag = 0;
    isAlive = true;
}

int CheaterPlayer::getNextMove(void)
{
    int random_integer, min, max;
    min = 1;
    max = 1;
    bool moveIsValid = false;
    int x, y;
    srand(time(0));
    x = getCurrentPositionX();
    y = getCurrentPositionY();
    if (x == 0 && y == 0)
    {
        min = 3;
        max = 5;
    }
    else if (x >= 1 && x <= 3 && y == 0)
    {
        min = 3;
        max = 7;
    }
    else if (x == 4 && y == 0)
    {
        min = 5;
        max = 7;
    }
    else if (x == 4 && y >= 1 && y <= 3)
    {
        min = 5;
        max = 9;
    }
    else if (x == 4 && y == 4)
    {
        min = 7;
        max = 9;
    }
    else if (x >= 1 && x <= 3 && y == 4)
    {
        min = 7;
        max = 11;
    }
    else if (x == 0 && y == 4)
    {
        min = 1;
        max = 3;
    }
    else if (x == 0 && y >= 1 && y <= 3)
    {
        min = 1;
        max = 5;
    }
    else if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
    {
        min = 1;
        max = 8;
    }
    int range = max - min + 1;
    random_integer = rand() % range + min;
    if (random_integer > 8)
        random_integer = random_integer - 8;
    assert(random_integer > 0 && random_integer < 9);
    return random_integer;
}

bool CheaterPlayer::shootPlayer()
{
	return false;
}

bool CheaterPlayer::stealFlag()
{
	return false;
}
