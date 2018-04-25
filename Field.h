#ifndef FIELD_H
#define FIELD_H

class Field{
int state; //0 - empty, 1 - hit, 2 - ship, 3 - hit ship
public:
Field();
void getHit();
void placeShipPart();
bool wasHit();
bool isShip();
bool isShipHit();
bool isWater();
};

#endif
