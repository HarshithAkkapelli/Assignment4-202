#ifndef INPUTSTRATEGY_H
#define INPUTSTRATEGY_H

#include "GameStrategy.h"
class InputStrategy : public GameStrategy {
public:
    std::string ch;
    InputStrategy(std::string inn){
        ch = inn;
    }
    virtual ~InputStrategy  () = default;
    virtual GameChoice makeChoice();
};

#endif
