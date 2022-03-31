//File: Player.cpp

//This file implements the functions and constructors for Player.h


#include "Player.h"
#include<time.h>
#include <assert.h>


//Default Constructor
Player::Player()
{
    symbol = ' ';
    name = " ";
    currentPositionX = -1;
    currentPositionY = -1;
    playerID = NULL;
    carrotFlag = false;
    isAlive = false;
    winner = false;
}

//Constructor called in main.cpp
Player::Player(int pid, char c, std::string n)
{
    symbol=c;
    name=n;
    currentPositionX=-1;
    currentPositionY= -1;
    playerID=pid;
    carrotFlag=0;
    isAlive=true;
}


//Function set carrotFlag of player
void Player::setCarrotFlag(bool c)
{
    carrotFlag = true;

}

//Function returns carrotFlag of character
bool Player::getCarrotFlag()
{
    return carrotFlag;
}

//This function simply generates a random number from 1-8 based on location of character on board using rand()
//and returns the random number when called in other functions.
int Player::getNextMove()
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
    else if(x >=1 && x <= 3 && y >= 1 && y <= 3)
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

//Set and get functions for player position
void Player::setCurrentPositionX(int x)
{
    currentPositionX = x;
}
int Player::getCurrentPositionX()
{
    return currentPositionX;
}
void Player::setCurrentPositionY(int y)
{
    currentPositionY = y;
}
int Player::getCurrentPositionY()
{
    return currentPositionY;
}

//Returns player ID
int Player::getPlayerId()
{
    return playerID;
}

//Set and get functions for boolean isAlive
void Player::setisAlive(bool flag)
{
    isAlive = flag;
}

bool Player::getisAlive()
{
    return isAlive;
}

//Set and get functions for boolean winner
void Player::setWinner(bool win)
{
    winner = win;
}

bool Player::getWinner()
{
    return winner;
}

//Get function for player symbol
char Player::getSymbol()
{
    return symbol;
}
