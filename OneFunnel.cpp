#include "OneFunnel.h"

bool OneFunnel::isSunk(){
if(myGrid->wasHit(x,y)) return true;
else return false;
}

bool OneFunnel::canTakeShot(){
if(isSunk()) return false;
else{
for(int i=x-2;i<x+3;i++)
for(int j=y-2;j<y+3;j++)
if(!oppGrid->wasHit(i,j)) return true;
return false;
}
}

bool OneFunnel::canTakeShot(int x1,int y1){
if(x<0 || x>9 || y<0 || y>9) return false;
if(x1>=x-2 && x1<=x+2 && y1>=y-2 && y1<=y+2 && (!oppGrid->wasHit(x1,y1))) return true;
return false;
}

void OneFunnel::shoot(int x1,int y1){
if(oppGrid->willItSunk(x1,y1)) interface.sunkAlert();
oppGrid->beShot(x1,y1);
}

bool OneFunnel::isVertical(){
return true;
}

void OneFunnel::setDirection(bool isVertical){}
