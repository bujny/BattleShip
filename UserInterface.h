#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Grid.h"
#include <memory>

using namespace std;

class UserInterface{
shared_ptr<Grid> myGrid;
shared_ptr<Grid> oppGrid;
bool isCompOnly; //if computers are only playing their print methods are turned on
public:
UserInterface(){}
UserInterface(shared_ptr<Grid> myGrid1, shared_ptr<Grid> oppGrid1, bool isCompOnly1);
void startScreen();
void printHuman();
void printComputer();
void canNotPlaceHere();
void thisCanNotTakeShot();
void hereCanNotTakeShot();
void sunkAlert();
void playerWon(int n);
int chooseShip();
int *placeOneFunnel(int *xy);
int *placeTwoFunnel(int *xy);
int *placeThreeFunnel(int *xy);
int *takeShot(int *xy);
bool verticalTwoFunnel();
bool verticalThreeFunnel();
bool wantShootTwice();
};

#endif
