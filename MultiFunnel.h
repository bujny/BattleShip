#ifndef MULTIFUNNEL_H
#define MULTIFUNNEL_H

#include "Ship.h"
#include <memory>

class MultiFunnel: public Ship{
bool vertical;
bool pause;

public:
MultiFunnel(int size1,std::shared_ptr<Grid> myGrid1, std::shared_ptr<Grid> oppGrid1,UserInterface anInterface):Ship(myGrid1,oppGrid1,anInterface){
size=size1;
pause=false;
}

void setDirection(bool isVertical);
bool isVertical();
void switchPause();
bool isPause();
bool isSunk();

bool canTakeShot();
bool canTakeShot(int x1, int y1);
void shoot(int x1,int y1);
};

#endif
