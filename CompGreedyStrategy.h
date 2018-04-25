#ifndef COMPGREEDYSTRATEGY_H
#define COMPGREEDYSTRATEGY_H

#include "Strategy.h"

class CompGreedyStrategy:public Strategy{
public:
CompGreedyStrategy(UserInterface anInterface):Strategy(anInterface){}
int random(int i);
void placeShips(shared_ptr<Ship> myShips[3]);
void makeMove(shared_ptr<Ship> myShips[3]);
};

#endif
