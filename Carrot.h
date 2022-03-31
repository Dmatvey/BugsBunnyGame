//File Carrot.h

//This class creates 2 objects that are carrots on the board. A player has to
//land on the same spot as the carrot in order to claim it.

#ifndef CARROT_H
#define CARROT_H
#include <vector>
#include "Board.h"
class Player;    //Forward declaration of class player
class Board;     //Forward declaration of class Board
class Carrot
{
private:
    std::vector<int>  previousOwner;    //Vector to store previous owner of Carrot object
    int currentOwner;       //Players pid is assigned to carrot
    int carrotPositionX;    //X coordinate position on board
    int carrotPositionY;    //Y coordinate position on board
    Board *board;           //Board object is member of class to be used later.
public:
    Carrot();               //Default Constructor
    int getCurrentOwner();  //returns pid of player that is the current owneer
    std::vector<int>  getPreviousOwner();
    bool setNewOwner(int pid);     //when a new onwer is set old one is registered
    void setCarrotPosition(int, int);  //Overloaded function used to set position of carrot ot (-1,-1) during game
    int getCarrotPositionY();          //returns carrot positions
    int getCarrotPositionX();
};

#endif
