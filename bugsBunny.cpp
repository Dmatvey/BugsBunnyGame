// bugsBunny.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program contains 4 classes: Board.h, Carrot.h, CheaterPlayer.h and Player.h

// This Looney Tunes game has 4 characters: BugsBunny, Tweety, Taz the Devil and Marvin. The game will be
// played on a 5 by 5 grid with a mountain on it 'F' and 2 carrots/flags 'C'. The goal of the game is for
// the player to pickup a carrot and race to the mountain, first one to get to the mountain with a carrot wins.
// Marvin isa cheating player and has the ability to land on other players spots and killing them and if they
// have a carrot he can steal them. Marvin also has the ability to activate the time machine and move the mountain
// every 3 rounds. The position of each characters is determined randomely.

#include <iostream>
#include "Player.h"
#include "CheaterPlayer.h"
#include "Board.h"
#include "Carrot.h"


#define BugsBunnyPid 11
#define TazDevilPid 12
#define TweetyPid 13
#define MarvinPid 14



int main()
{
    //Player objects created
    Player* BugsBunny = new Player(BugsBunnyPid, 'B', "BugsBunny");  //Objects player and cheaterplayer is created
    Player* TazDevil = new Player(TazDevilPid, 'D', "TazDevil");
    Player* Tweety = new Player(TweetyPid, 'T', "Tweety");

    //CheaterPlayer objected created
    CheaterPlayer* Marvin = new CheaterPlayer(MarvinPid, 'M', "Marvin");

    //Carrot objects created
    Carrot* C1 = new Carrot();   //Objects carrot C1 and C2 is created, no position on board is set yet.
    Carrot* C2 = new Carrot();

    //Board object created
    Board* board = new Board('F', -1, -1, BugsBunny, TazDevil, Tweety, Marvin, C1, C2, false);  //Object board is created with mountain set to coordinated (-1, -1)

    //Initial position of mountain is set
    board->mountainPositionset();

    //Initial position of players is set
    board->setAllPlayerFirstPostion();

    //Initial position of carrots is set
    board->setFirstCarrotPositions();

    //Welcome menu displayed with instructions
    std::cout << "****************************" << std::endl;
    std::cout << "   WELCOME TO BUGS' BUNNY" << std::endl;
    std::cout << "      LOST IN TIME!!     " << std::endl;
    std::cout << "     B = Bugs Bunny" << std::endl;
    std::cout << "     D = Taz the Devil" << std::endl;
    std::cout << "     T = Tweety" << std::endl;
    std::cout << "     M = Marvin" << std::endl;
    std::cout << "     F = Mountain" << std::endl;
    std::cout << "     C = Carrot" << std::endl;
    std::cout << "To win this game, a character" << std::endl;
    std::cout << "has to find a carrot and race" << std::endl;
    std::cout << "to the Mountain to Win!!" << std::endl;
    std::cout << "(Press Enter to continue)" << std::endl;
    std::cout << "*****************************" << std::endl;

    getchar();
    bool menuOption = false;
    char option;

    //Player is given option to cycle through game or automatically or move by move
    std::cout << "To Play automatically press 'A'" << std::endl;
    std::cout << "To Play move by move press 'B'" << std::endl;
    std::cout << " A = Automatically       " << std::endl;
    std::cout << " B(or any other key) = Manually" << std::endl;
    std::cout << "->";
    std::cin >> option;
    if (option == 'A' || option == 'a')
        menuOption = false;
    else
        menuOption = true;
    if (menuOption)
        std::cout << "Press Enter to cycle through game." << std::endl;
    if (menuOption)
        getchar();
    board->printBoard();
    int count = 0;

    //Do while loop continues to move players until boolean gameOver is triggered
    do
    {
        //If statement checks if player is still alive before moving
        if (BugsBunny->getisAlive() == true)
        {
            board->setPlayerSurrounded(BugsBunny);
            if (board->getPlayerSurrounded(BugsBunny) == false)
            {
                if (menuOption)
                    getchar();
                board->movePlayer(BugsBunny);
                board->printBoard();
            }
            else
                std::cout << "Bugs Bunny is surrounded, turn is skipped!" << std::endl;
        }
        if (!board->getGameOver())
        {
            if (TazDevil->getisAlive() == true)
            {
                board->setPlayerSurrounded(TazDevil);
                if (board->getPlayerSurrounded(TazDevil) == false)
                {
                    if (menuOption)
                        getchar();
                    board->movePlayer(TazDevil);
                    board->printBoard();
                }
                else
                    std::cout << "Taz the Devil is surrounded, turn is skipped!" << std::endl;
            }
        }
        if (!board->getGameOver())
        {
            if (Tweety->getisAlive() == true)
            {
                board->setPlayerSurrounded(Tweety);
                if (board->getPlayerSurrounded(Tweety) == false)
                {
                    if (menuOption)
                        getchar();
                    board->movePlayer(Tweety);
                    board->printBoard();
                }
                else
                    std::cout << "Tweety is surrounded, turn is skipped!" << std::endl;
            }
        }
        if (!board->getGameOver())
        {
            if (menuOption)
                getchar();
            board->movePlayer(Marvin);
            board->printBoard();
        }
        count++;

        //Every 3 cycles mountain is moved
        if (!board->getGameOver())
        {
            if (count == 3)
            {
                if (menuOption)
                    getchar();
                board->activateTimeMachine(board);
                std::cout << "Time Machine Activated!!" << std::endl << std::endl;
                board->printBoard();
                count = 0;
            }
        }
    } while (!(board->getGameOver()));

    //Once game is over the winner is checked for each player and displayed
    if (BugsBunny->getWinner() == true)
    {
        std::cout << "Winner!: Bugs Bunny" << std::endl;
    }
    else if (TazDevil->getWinner() == true)
    {
        std::cout << "Winner!: Taz The Devil" << std::endl;
    }
    else if (Tweety->getWinner() == true)
    {
        std::cout << "Winner!: Tweety" << std::endl;
    }
    else if (Marvin->getWinner() == true)
    {
        std::cout << "Winner!: Marvin" << std::endl;
    }
    std::cout << std::endl;
    return 0;
}


