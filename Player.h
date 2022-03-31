//File: Player.h

//The class file creates 3 objects that are the characters, Bugs Bunny, Tweety, and Taz the Devil.
//The class CheaterPlayer inherits the protected members to create the character Marvin.

#ifndef PLAYER_H
#define PLAYER_H
#include <string>



class Player
{
protected:
    char symbol;  //Symbol of each player; 'B','T', 'D' and 'M'
    std::string name;    //Name of character
    int currentPositionX;    //These to variable represent the position on a 5 by 5 board
    int currentPositionY;
    int playerID;          //Id of player from 11 to 14
    bool carrotFlag;       //Boolean flag if player possesses a carrot or not
    bool isAlive;          //Boolean flag if character is alive
    bool winner;           //Boolean flag if character is a winner
public:
    Player();              //Default constructor
    Player(int pid, char c, std::string n);    //Constructor
    void setCarrotFlag(bool c);                //Sets carrotFlag
    bool getCarrotFlag();                      //returns boolean
    int getNextMove(void);                     //called from gameBoard to move the player
    void setCurrentPositionX(int);             //Functions for setting and getting position of character
    int getCurrentPositionX();
    void setCurrentPositionY(int);//called from gameBoard  mover the player
    int getCurrentPositionY();
    int getPlayerId();                     //Returns id of player
    void setisAlive(bool);                 //set boolean for alive status of player
    bool getisAlive();                     //returns boolean for alive status of player
    void setWinner(bool);                  //set boolean for if character is alive or not
    bool getWinner();                      //returns boolean if character is winner or not
    char getSymbol();                      //returns symbol of character
};

#endif
