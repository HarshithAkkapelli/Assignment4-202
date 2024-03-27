#include<iostream>
#include "InputStrategy.h"

GameChoice InputStrategy::makeChoice() {
    GameChoice gameChoice = INVALID;
    gameChoice = stringToGameChoice(ch);

    return gameChoice;
}
