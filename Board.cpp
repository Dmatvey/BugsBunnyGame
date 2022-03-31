//File: Board.cpp

//This file creates the board and positions the players, carrots and mountain on it. This
//class also moves the players and the mountain


#include "Board.h"
#include "Player.h"
#include "Carrot.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

#define BugsBunnyPid 11
#define TazDevilPid 12
#define TweetyPid 13
#define MarvinPid 14

//Default Constructor
Board::Board() {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            gameBoard[i][j] = 0;
    }
    mountain = ' ';
    mountainPositionX = -1;
    mountainPositionY = -1;
    c = NULL;
    C1 = NULL;   
    C2 = NULL;
    gameOver = false;

}


//Constructor called when an object Board is created
Board::Board(char mt, int mpX, int mpY, Player* A, Player* B, Player* C, CheaterPlayer* D, Carrot* C_1, Carrot* C_2 , bool gO)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            gameBoard[i][j] = 0;
    }
    mountain = mt;
    mountainPositionX = mpX;
    mountainPositionY = mpY;
    players.push_back(A);
    players.push_back(B);
    players.push_back(C);
    c = D;
    gameOver = gO;
    C1 = C_1;
    C2 = C_2;

}

//This function simply prints the board and all the symbols on it
void Board::printBoard()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char a = ((gameBoard[i][j] == 0) ? '-' : gameBoard[i][j] );
            std::cout << a; 
            if (gameBoard[i][j] == 'B' && players[BugsBunnyPid - 11]->getCarrotFlag())
            {
                std::cout << "(C)" << "   ";
            }
            else if (gameBoard[i][j] == 'D' && players[TazDevilPid - 11]->getCarrotFlag())
            {
                std::cout << "(C)" << "   ";
            }
            else if (gameBoard[i][j] == 'T' && players[TweetyPid - 11]->getCarrotFlag())
            {
                std::cout << "(C)" << "   ";
            }
            else if (gameBoard[i][j] == 'M' && c->getCarrotFlag())
            {
                std::cout << "(C)" << "   ";
            }
            else
                std::cout << "      ";
           
        }
        std::cout << std::endl << std::endl << std::endl;
    }
    std::cout << "-----------------------------";
    std::cout << std::endl << std::endl << std::endl;
}


//This function returns the binary of a position, if its 0 it returns true, the position is not occupied
bool Board::getBoardBinary(int y, int x)
{
    if (gameBoard[y][x] == 0)
        return true;
    else
        return false;
}

//This sets the symbol of a position
void Board::setBoard(char letter, int y, int x)
{
    gameBoard[y][x] = letter;
}

//This function moves the mountain when called
void Board::moveMountain()
{
    int random_integerX = 0, random_integerY = 0, min = 1, max = 5;
    int x = 0, y = 0;
    
    //Do-while loop generates 2 random numbers from 1-5 that correspond to 25 different positions on board.
    do
    {
        int range = max - min + 1;
        random_integerX = rand() % range + min;
        random_integerY = rand() % range + min;
        x = random_integerX - 1;
        y = random_integerY - 1;
      //If any of the conditions are true in the while statement, the loop repeats again until all are false  
    } while ((getBoardBinary(y, x) != true) || ((getBoard(y, x) == 'C')) || x < 0 || x > 4 || y < 0 || y > 4);
    //Previous position of mountain set to 0, available
    setBoard(0, mountainPositionY, mountainPositionX);
    //New positoin of mountain is et
    setBoard('F', y, x);
    mountainPositionX = x;
    mountainPositionY = y;
}

//Set and get functions for gameOver
void Board::setGameOver(bool g)
{
    gameOver = g;
}

bool Board::getGameOver()
{
    return gameOver;
}


//This function returns symbol on the board
char Board::getBoard(int y, int x)
{
    return gameBoard[y][x];
}

//this function set the position of mountain at start of game
void Board::mountainPositionset()
{
    mountainPositionX = 2;
    mountainPositionY = 2;
    setBoard('F', 2, 2);
}

//This function sets the position of the carrots at start of game
void Board::setFirstCarrotPositions()
{
    C1->setCarrotPosition(2, 0);
    C2->setCarrotPosition(2, 4);
    setBoard('C', 2, 0);
    setBoard('C', 2, 4);

}

//This function sets the initial position of the players on the board
void Board::setAllPlayerFirstPostion()
{
    setBoard('B', 0, 0);
    players[BugsBunnyPid - 11]->setCurrentPositionX(0);
    players[BugsBunnyPid - 11]->setCurrentPositionY(0);

    setBoard('D', 0, 4);
    players[TazDevilPid - 11]->setCurrentPositionX(4);
    players[TazDevilPid - 11]->setCurrentPositionY(0);

    setBoard('T', 4, 4);
    players[TweetyPid - 11]->setCurrentPositionX(4);
    players[TweetyPid - 11]->setCurrentPositionY(4);

    setBoard('M', 4, 0);
    c->setCurrentPositionX(0);
    c->setCurrentPositionY(4);
}

//This function checks if the player is surrounded and sets the bool flag
void Board::setPlayerSurrounded(Player* s)
{
    bool moveIsValid = false;
    int x = -1, y = -1, tempX = -1, tempY = -1;
    x = s->getCurrentPositionX();
    y = s->getCurrentPositionY();
    for (int i = 1; i < 9; i++)
    {
        switch (i)  
        {
        case 1:
        {
            tempY = y - 1;
            tempX = x;
            break;
        }
        case 2:
        {
            tempY = y - 1;
            tempX = x + 1;
            break;
        }
        case 3:
        {
            tempY = y;
            tempX = x + 1;
            break;
        }
        case 4:
        {
            tempY = y + 1;
            tempX = x + 1;
            break;
        }
        case 5:
        {
            tempY = y + 1;
            tempX = x;
            break;
        }
        case 6:
        {
            tempY = y + 1;
            tempX = x - 1;
            break;
        }
        case 7:
        {
            tempY = y;
            tempX = x - 1;
            break;
        }
        case 8:
        {
            tempY = y - 1;
            tempX = x - 1;
            break;
        }
        default:
            break;
        }
        if (tempY >= 0 && tempX >= 0)
        {
            if (getBoardBinary(tempY, tempX) == true)
                moveIsValid = true;
            if (s->getCarrotFlag() == true && getBoard(tempY, tempX) == 'F')
                moveIsValid = true;
            if (s->getCarrotFlag() == false && getBoard(tempY, tempX) == 'C')
                moveIsValid = true;
        }
        if (moveIsValid == true)
            break;
    }
    if (moveIsValid == false)
        playerSurrounded = true;
    else
        playerSurrounded = false;
}


bool Board::getPlayerSurrounded(Player* s)
{
    return playerSurrounded;
}

//This function moves players
void Board::movePlayer(Player * s) 
{
    bool moveIsValid = false;
    int x = -1, y = -1, tempX = 1, tempY = -1;
    x = s->getCurrentPositionX();
    y = s->getCurrentPositionY();
    do {
        switch (s->getNextMove())  //Switch case calls function getNextMove() and checks if the move is valid
        {
        case 1:
        {
            tempY = y - 1;
            tempX = x;
            break;
        }
        case 2:
        {
            tempY = y - 1;
            tempX = x + 1;
            break;
        }
        case 3:
        {
            tempY = y;
            tempX = x + 1;
            break;
        }
        case 4:
        {
            tempY = y + 1;
            tempX = x + 1;
            break;
        }
        case 5:
        {
            tempY = y + 1;
            tempX = x;
            break;
        }
        case 6:
        {
            tempY = y + 1;
            tempX = x - 1;
            break;
        }
        case 7:
        {
            tempY = y;
            tempX = x - 1;
            break;
        }
        case 8:
        {
            tempY = y - 1;
            tempX = x - 1;
            break;
        }
        default:
            break;
        }   //If the player does NOT have a carrot, then they are no allowed to go to mountain.
            if (!s->getCarrotFlag())
            {
                if (!(getBoard(tempY, tempX) == 'F'))
                    moveIsValid = true;
                else
                    moveIsValid = false;
            }
            //If player does have a carrot they are allowed to go to mountain but not allowed to step on 2nd carrot
            else if (s->getCarrotFlag())
            {
                if (getBoard(tempY, tempX) == 'F')
                    moveIsValid = true;
                else if (!(getBoard(tempY, tempX) == 'C'))
                    moveIsValid = true;
            }
            //If any of the positions have any of the other characters then they are not allowed to step on it
            if (getBoard(tempY, tempX) == 'B' ||
                getBoard(tempY, tempX) == 'T' ||
                getBoard(tempY, tempX) == 'D' ||
                getBoard(tempY, tempX) == 'M')
            {
                moveIsValid = false;
            }
            //This checks to make sure none of the positions chosen are off the board
            if (tempY < 0 || tempY > 4)
                moveIsValid = false;
            if (tempX < 0 || tempX > 4)
                moveIsValid = false;
    } while (!moveIsValid);   //this loop continues until the moveIsValid
    y = tempY;
    x = tempX;
    
    //At this point the new position is checked to see if they landed on a carrot, if yes thier carrotFlag is set to true
    if (getBoard(y, x) == 'C')
    {
        //If carrot is C1 or C2, setNewOwner is called
        if (y == C1->getCarrotPositionY() && x == C1->getCarrotPositionX())
        {
            s->setCarrotFlag(true);
            C1->setNewOwner(s->getPlayerId());
            C1->setCarrotPosition(-1, -1);  //Position of carrot is set to false in order for it to not print
        }
        else if (y == C2->getCarrotPositionY() && x == C2->getCarrotPositionX())
        {
            s->setCarrotFlag(true);
            C2->setNewOwner(s->getPlayerId());
            C2->setCarrotPosition(-1, -1);
        }
    }
   
    //If the position they landed on is the mountain, they  win and game over
    if (getBoard(y, x) == 'F')
    {
        s->setWinner(true);
        setGameOver(true);
    }
    //Previous positoin of player set to 0, available and new position is set with thier respective symbol
    setBoard(0, s->getCurrentPositionY(), s->getCurrentPositionX());
    s->setCurrentPositionX(x);
    s->setCurrentPositionY(y);
    setBoard(s->getSymbol(), s->getCurrentPositionY(), s->getCurrentPositionX());
}


//This function is used to move the cheater player Marvin
void Board::movePlayer(CheaterPlayer* c)
{
    bool moveIsValid = false;
    int x, y, tempx = 0, tempy = 0;
    x = c->getCurrentPositionX();
    y = c->getCurrentPositionY();
    do {
        switch (c->getNextMove()) //Switch case calls function getNextMove() and checks if the move is valid
        {
        case 1:
        {
            tempy = y - 1;
            tempx = x;
            break;
        }
        case 2:
        {
            tempy = y - 1;
            tempx = x + 1;
            break;
        }
        case 3:
        {
            tempy = y;
            tempx = x + 1;
            break;
        }
        case 4:
        {
            tempy = y + 1;
            tempx = x + 1;
            break;
        }
        case 5:
        {
            tempy = y + 1;
            tempx = x;
            break;
        }
        case 6:
        {
            tempy = y + 1;
            tempx = x - 1;
            break;
        }
        case 7:
        {
            tempy = y;
            tempx = x - 1;
            break;
        }
        case 8:
        {
            tempy = y - 1;
            tempx = x - 1;
            break;
        }
        default:
        {
            std::cout << "Invalid Choice!!" << std::endl;
            break;
        }
        }
        //If Marvin doesnt have a carrot, the mountain is the only position he cannot land on
        if (!c->getCarrotFlag())
        {
            if (!(getBoard(tempy, tempx) == 'F'))
                moveIsValid = true;
        }
        //If Marvin has a carrot, he can land anywhere
        else if(c->getCarrotFlag())
        {
            moveIsValid = true;
        }
        
        //This checks to make sure new positon of character is on the board
        if (tempy < 0 || tempy > 4)
            moveIsValid = false;
        if (tempx < 0 || tempx > 4)
            moveIsValid = false;
    } while (!moveIsValid);   //Loop continues until this is false
    y = tempy;
    x = tempx;
    
    //Switch statement checks to see if he landed on any of the characters, if yes he shoots them and steal carrots
    switch (getBoard(y, x))
    {
    case 'B':
    {
        if (C1->getCurrentOwner() == BugsBunnyPid)
        {
            c->setCarrotFlag(true);
            C1->setNewOwner(MarvinPid);
        }
        if (C2->getCurrentOwner() == BugsBunnyPid)
        {
            c->setCarrotFlag(true);
            C2->setNewOwner(MarvinPid);
        }
        std::cout << "Marvin shot Bugs Bunny!!" << std::endl;
        players[BugsBunnyPid - 11]->setisAlive(false);
        players[BugsBunnyPid - 11]->setCurrentPositionX(-1);
        players[BugsBunnyPid - 11]->setCurrentPositionY(-1);
        break;
    }
    case 'D':
    {
        if (C1->getCurrentOwner() == TazDevilPid)
        {
            c->setCarrotFlag(true);
            C1->setNewOwner(MarvinPid);
        }
        if (C2->getCurrentOwner() == TazDevilPid)
        {
            c->setCarrotFlag(true);
            C2->setNewOwner(MarvinPid);
        }
        std::cout << "Marvin shot Taz the Devil!!" << std::endl;
        players[TazDevilPid - 11]->setisAlive(false);
        players[TazDevilPid - 11]->setCurrentPositionX(-1);
        players[TazDevilPid - 11]->setCurrentPositionY(-1);
        break;
    }
    case 'T':
    {
        if (C1->getCurrentOwner() == TweetyPid)
        {
            c->setCarrotFlag(true);
            C1->setNewOwner(MarvinPid);
        }
        if (C2->getCurrentOwner() == TweetyPid)
        {
            c->setCarrotFlag(true);
            C2->setNewOwner(MarvinPid);
        }
        std::cout << "Marvin shot Tweety!!" << std::endl;
        players[TweetyPid - 11]->setisAlive(false);
        players[TweetyPid - 11]->setCurrentPositionX(-1);
        players[TweetyPid - 11]->setCurrentPositionY(-1);
        break;
    }
Default:
        break;
    }
    
    //If he lands on a position that has a carrot, new owner is set
    if (y == C1->getCarrotPositionY() && x == C1->getCarrotPositionX())
    {
        c->setCarrotFlag(true);
        C1->setNewOwner(MarvinPid);
        C1->setCarrotPosition(-1, -1);
    }
    if (y == C2->getCarrotPositionY() && x == C2->getCarrotPositionX())
    {
        c->setCarrotFlag(true);
        C2->setNewOwner(MarvinPid);
        C2->setCarrotPosition(-1, -1);
    }
    
    //If lands on mountain, Marvin winds and game is over
    if (getBoard(y, x) == 'F')
    {
        c->setWinner(true);
        setGameOver(true);
    }
    //Previous position is set to 0, available
    setBoard(0, c->getCurrentPositionY(), c->getCurrentPositionX());
    c->setCurrentPositionX(x);
    c->setCurrentPositionY(y);
    setBoard(c->getSymbol(), c->getCurrentPositionY(), c->getCurrentPositionX());
}


//This position calls the moveMountain function
void Board::activateTimeMachine(Board* gboard)
{
    gboard->moveMountain();
}