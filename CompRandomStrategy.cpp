#include "CompRandomStrategy.h"
#include <cstdlib>

int CompRandomStrategy::random(int i){

int r=rand()%i;
return r;
}

void CompRandomStrategy::placeShips(shared_ptr<Ship> myShips[3]){
int xy[2];
interface.printComputer();
//onefunnel:
do{
xy[0]=random(10);xy[1]=random(10);

}while(!myShips[0]->canPlaceShip(xy[0],xy[1]));
myShips[0]->placeShip(xy[0],xy[1]);
interface.printComputer();
//twofunnel:
myShips[1]->setDirection(random(2));
do{
xy[0]=random(10);xy[1]=random(10);

}while(!myShips[1]->canPlaceShip(xy[0],xy[1]));
myShips[1]->placeShip(xy[0],xy[1]);
interface.printComputer();
//threefunnel:
myShips[2]->setDirection(random(2));
do{
xy[0]=random(10);xy[1]=random(10);

}while(!myShips[2]->canPlaceShip(xy[0],xy[1]));
myShips[2]->placeShip(xy[0],xy[1]);
interface.printComputer();
}

void CompRandomStrategy::makeMove(shared_ptr<Ship> myShips[3]){
int n;
int xy[2];
bool emptyMove=true;

for(int i=0;i<3;i++)
    if(myShips[i]->canTakeShot()&&!myShips[i]->isPause()) emptyMove=false;
if(emptyMove){
    if(myShips[1]->isPause()) myShips[1]->switchPause();
    if(myShips[2]->isPause()) myShips[2]->switchPause();
    return;
}

do{
n=random(3);

}while(!myShips[n]->canTakeShot()||myShips[n]->isPause());

if(n==0){
do{
xy[0]=random(10);xy[1]=random(10);

}while(!myShips[n]->canTakeShot(xy[0],xy[1]));
myShips[n]->shoot(xy[0],xy[1]);
interface.printComputer();
if(myShips[1]->isPause()) myShips[1]->switchPause();
if(myShips[2]->isPause()) myShips[2]->switchPause();
}
else{
do{
xy[0]=random(10);xy[1]=random(10);

}while(!myShips[n]->canTakeShot(xy[0],xy[1]));
myShips[n]->shoot(xy[0],xy[1]);
interface.printComputer();
if(myShips[n]->canTakeShot()){
if(random(2)){
    do{
    xy[0]=random(10);xy[1]=random(10);

    }while(!myShips[n]->canTakeShot(xy[0],xy[1]));
    myShips[n]->shoot(xy[0],xy[1]);
    interface.printComputer();
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
