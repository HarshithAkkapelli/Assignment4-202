#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "GameStrategy.h"
#include "GameData.h"

class GameEngine
{
public:
    Round roundplay(int roundNum, Player& player1, Player& player2);
    std::string roundlog(Player& player1, Player& player2, Round round);


    void gameplay(int numRounds, Player& player1, Player& player2);

};


#endif
