#ifndef GRID_H
#define GRID_H

#include "Field.h"

class Grid{
Field fields[10][10];
public:
void beShot(int x, int y);
bool wasHit(int x, int y);
bool isShip(int x, int y);
bool willItSunk(int x, int y);
void placeShipPart(int x,int y);
char printHuman(int x, int y);
char printComp(int x, int y);
char printOpp(int x, int y);
int getShips();
};

#endif
