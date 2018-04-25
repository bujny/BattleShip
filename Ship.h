#ifndef SHIP_H
#define SHIP_H

#include "Grid.h"
#include "UserInterface.h"
#include <memory>

class Ship{
protected:
int size;
int x;
int y;
std::shared_ptr<Grid> myGrid;
std::shared_ptr<Grid> oppGrid;
UserInterface interface;

public:


Ship(std::shared_ptr<Grid> myGrid1, std::shared_ptr<Grid> oppGrid1,UserInterface anInterface);
int getSize();
bool canPlaceShip(int x1,int y1);
void placeShip(int x, int y);



virtual void switchPause()=0;
virtual void setDirection(bool isVertical)=0;
virtual bool isPause()=0;
virtual bool isVertical()=0;
virtual void shoot(int x1,int y1)=0;
virtual bool canTakeShot()=0;
virtual bool canTakeShot(int x1,int y1)=0;
virtual bool isSunk()=0;
};

#endif
