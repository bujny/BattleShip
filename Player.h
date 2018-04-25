#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Strategy.h"
#include "OneFunnel.h"

using namespace std;

class Player {
int index; //1 or 2 -> player 1 or 2
shared_ptr<Strategy> strategy; //strategia nie posiada gracza tylko jego statki, ktore bd przesylane przy wywolywaniu danej metody
shared_ptr<Ship> myShips[3];
public:
Player(){}
Player(shared_ptr<Strategy> aStrategy,shared_ptr<OneFunnel> ship1,shared_ptr<Ship> ship2,shared_ptr<Ship> ship3);
void placeShips();
void makeMove();
bool canTakeShot();
bool areMyShipsSunk();
};

#endif
