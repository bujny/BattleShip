#ifndef STRATEGY_H
#define STRATEGY_H

#include "UserInterface.h"
#include "Ship.h"
#include <memory>

using namespace std;

class Strategy{
protected:
UserInterface interface;
public:
Strategy(UserInterface anInterface);
virtual void placeShips(shared_ptr<Ship> myShips[3])=0;
virtual void makeMove(shared_ptr<Ship> myShips[3])=0;
};

#endif
