#include "Carrot.h"


//Default Constructor
Carrot::Carrot()   
{
    currentOwner = 0;
    previousOwner;
	carrotPositionX = -1;
	carrotPositionY = -1;
}

//Function returns pid of current owner
int Carrot::getCurrentOwner()
{
    return currentOwner;
}

//Function set pid of current owner in a vector of previous owners
bool Carrot::setNewOwner(int pid)
{
	previousOwner.push_back(currentOwner);
	currentOwner = pid;
	return true;
}

//Function set position of carrot to -1, -1 in order to not appear on board once possesed by a character
void Carrot::setCarrotPosition(int y, int x)
{
    carrotPositionY = y;
    carrotPositionX = x;
}

//Following 2 functions return position of carrot
int Carrot::getCarrotPositionY()
{
    return carrotPositionY;
}

int Carrot::getCarrotPositionX()
{
    return carrotPositionX;
}

//Function returns previous owner of carrot
std::vector<int> Carrot::getPreviousOwner()
{
	return previousOwner;
}
