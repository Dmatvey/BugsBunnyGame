#pragma once
#include "Player.h"
//#include "Carrot.h"

#ifndef CHEATERPLAYER_H
#define CHEATERPLAYER_H

class Player;
class CheaterPlayer:
    public Player
{
public:
    CheaterPlayer();
    CheaterPlayer(int pid, char c, std::string n);
    int getNextMove(void);
    bool shootPlayer();
    bool stealFlag();
};

#endif
