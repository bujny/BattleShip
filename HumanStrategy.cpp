#include "HumanStrategy.h"

void HumanStrategy::placeShips(shared_ptr<Ship> myShips[3]){
interface.printHuman();
//onefunnel:
int *xy;
do{
xy=interface.placeOneFunnel(xy);
if(!myShips[0]->canPlaceShip(xy[0],xy[1])) interface.canNotPlaceHere();
}while(!myShips[0]->canPlaceShip(xy[0],xy[1]));
myShips[0]->placeShip(xy[0],xy[1]);
interface.printHuman();
//twofunnel:
myShips[1]->setDirection(interface.verticalTwoFunnel());
do{
xy=interface.placeTwoFunnel(xy);
if(!myShips[1]->canPlaceShip(xy[0],xy[1])) interface.canNotPlaceHere();
}while(!myShips[1]->canPlaceShip(xy[0],xy[1]));
myShips[1]->placeShip(xy[0],xy[1]);
interface.printHuman();
//threefunnel:
myShips[2]->setDirection(interface.verticalThreeFunnel());
do{
xy=interface.placeThreeFunnel(xy);
if(!myShips[2]->canPlaceShip(xy[0],xy[1])) interface.canNotPlaceHere();
}while(!myShips[2]->canPlaceShip(xy[0],xy[1]));
myShips[2]->placeShip(xy[0],xy[1]);
interface.printHuman();
}

void HumanStrategy::makeMove(shared_ptr<Ship> myShips[3]){
int n;
int *xy;
bool emptyMove=true;

for(int i=0;i<3;i++)
    if(myShips[i]->canTakeShot()&&!myShips[i]->isPause()) emptyMove=false;
if(emptyMove){
    if(myShips[1]->isPause()) myShips[1]->switchPause();
    if(myShips[2]->isPause()) myShips[2]->switchPause();
    return;
}

do{
n=interface.chooseShip();
if(!myShips[n]->canTakeShot()||myShips[n]->isPause()) interface.thisCanNotTakeShot();
}while(!myShips[n]->canTakeShot()||myShips[n]->isPause());

if(n==0){
do{
xy=interface.takeShot(xy);
if(!myShips[n]->canTakeShot(xy[0],xy[1])) interface.hereCanNotTakeShot();
}while(!myShips[n]->canTakeShot(xy[0],xy[1]));
myShips[n]->shoot(xy[0],xy[1]);
interface.printHuman();
if(myShips[1]->isPause()) myShips[1]->switchPause();
if(myShips[2]->isPause()) myShips[2]->switchPause();
}
else{
do{
xy=interface.takeShot(xy);
if(!myShips[n]->canTakeShot(xy[0],xy[1])) interface.hereCanNotTakeShot();
}while(!myShips[n]->canTakeShot(xy[0],xy[1]));
myShips[n]->shoot(xy[0],xy[1]);
interface.printHuman();
if(myShips[n]->canTakeShot()){
if(interface.wantShootTwice()){
    do{
    xy=interface.takeShot(xy);
    if(!myShips[n]->canTakeShot(xy[0],xy[1])) interface.hereCanNotTakeShot();
    }while(!myShips[n]->canTakeShot(xy[0],xy[1]));
    myShips[n]->shoot(xy[0],xy[1]);
    interface.printHuman();
myShips[n]->switchPause();
if(n==1){if(myShips[2]->isPause()) myShips[2]->switchPause();}
else    {if(myShips[1]->isPause()) myShips[1]->switchPause();}
}else
{if(myShips[1]->isPause()) myShips[1]->switchPause();
if(myShips[2]->isPause()) myShips[2]->switchPause();}
}else
{if(myShips[1]->isPause()) myShips[1]->switchPause();
if(myShips[2]->isPause()) myShips[2]->switchPause();}
}
}
