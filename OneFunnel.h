#ifndef ONEFUNNEL_H
#define ONEFUNNEL_H

#include "Ship.h"

class OneFunnel: public Ship{
public:
OneFunnel(std::shared_ptr<Grid> myGrid1, std::shared_ptr<Grid> oppGrid1,UserInterface anInterface) : Ship(myGrid1,oppGrid1,anInterface){size=1;}
bool isSunk();
bool canTakeShot();
bool canTakeShot(int x1,int y1);
void shoot(int x1,int y1);
bool isVertical();
void switchPause(){}
bool isPause(){return false;}
void setDirection(bool isVertical);
};

#endif
