#ifndef COMPRANDOMSTRATEGY_H
#define COMPRANDOMSTRATEGY_H

#include "Strategy.h"

class CompRandomStrategy:public Strategy{
public:
CompRandomStrategy(UserInterface anInterface):Strategy(anInterface){}
int random(int i);
void placeShips(shared_ptr<Ship> myShips[3]);
void makeMove(shared_ptr<Ship> myShips[3]);
};

#endif
