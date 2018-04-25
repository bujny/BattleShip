#ifndef HUMANSTRATEGY_H
#define HUMANSTRATEGY_H
#include "Strategy.h"

class HumanStrategy: public Strategy{
public:
HumanStrategy(UserInterface anInterface):Strategy(anInterface){}
void placeShips(shared_ptr<Ship> myShips[3]);
void makeMove(shared_ptr<Ship> myShips[3]);
};

#endif
