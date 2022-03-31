//File: Board.h

//This class creates an object Board, that contains the characters carrots and the mountain on it, this
//also has a printBoard function, that prints the board every time a player or mountain moves.

#ifndef BOARD_H
#define BOARD_H
#include "Player.h"
#include "CheaterPlayer.h"
#include "Carrot.h"
#include <vector>
class CheaterPlayer;  //forward declaration of CheaterPlayer Class
class Carrot;         //Forward declaration of Carrot
class Player;         //Forward declaration of Player
class Board
{
private:
    char gameBoard[5][5];  //2-D array used for the 5 by 5 board
    char mountain;         //Symbol for mountain 'F'
    int mountainPositionX;  //Position of mountain on board
    int mountainPositionY;
    std::vector<Player*> players;  //Vector of players used in this class
    CheaterPlayer* c;              //CheaterPlayer object Marvin used in this class too
    Carrot* C1;                    //Both object carrots used
    Carrot* C2;
    bool gameOver = false;    //Boolean that is set to true for gameOver
    bool playerSurrounded = false;

public:
    Board();       //Default Constructor
    Board(char mt, int mpX, int mpY, Player*, Player*, Player*,CheaterPlayer*, Carrot* , Carrot* , bool );
    void printBoard();       //Function for printing board
    char getBoard(int y, int x);     //returns symbol on Board
    void setBoard(char, int, int);     //sets the symbol on board
    bool getBoardBinary(int y, int x);   //returns a true or false if the position is true or false
    void mountainPositionset();         //This function sets the initial position of mountain on board at beginning of game
    void setFirstCarrotPositions();   //This function sets the initial position of carrots at beginning of game
    void setAllPlayerFirstPostion();   //This sets the initial position of players on board at beginning of gmae
    void movePlayer(Player* s);    //moves the player selected in the gameBoard, calculates next move
    void movePlayer(CheaterPlayer* c);    //Moves CheaterPlayer
    void activateTimeMachine(Board* gboard);    //This function when activated every 3 cycles, moves the mountain
    void moveMountain();                    //this function is activated by the previous function
    void setGameOver(bool);              //This function sets the game to over if ture
    bool getGameOver();                    //checks if game is over
    void setPlayerSurrounded(Player* s);   //This function checks if any of the players are surrounded, if yes turn is skipped
    bool getPlayerSurrounded(Player* s);    //This function returns a boolean if the player is surrounded or not
};

#endif
