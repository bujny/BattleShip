#include "MultiFunnel.h"

bool MultiFunnel::isVertical(){
if(vertical) return true;
return false;
}

bool MultiFunnel::isPause(){
if(pause) return true;
return false;
}

void MultiFunnel::switchPause(){
if(pause) pause=false;
else pause=true;
}

bool MultiFunnel::isSunk(){
if(vertical){
for(int i=y;i<y+size;i++)
if(!myGrid->wasHit(x,i)) return false;
return true;
}
else{
for(int i=x;i<x+size;i++)
if(!myGrid->wasHit(i,y)) return false;
return true;
}
}

bool MultiFunnel::canTakeShot(){
if(isSunk()) return false;
else{
if(vertical){
for(int i=x-size-1;i<=x+size+1;i++)
for(int j=y-size-1;j<=y+(2*size);j++)
if(!oppGrid->wasHit(i,j)) return true;
return false;
}
else{
for(int i=x-size-1;i<=x+(2*size);i++)
for(int j=y-size-1;j<=y+size+1;j++)
if(!oppGrid->wasHit(i,j)) return true;
return false;
}
}
}

bool MultiFunnel::canTakeShot(int x1, int y1){
if(x<0 || x>9 || y<0 || y>9) return false;
if(vertical){
if(x1>=x-size-1 && x1<=x+size+1 && y1>=y-size-1 && y1<=y+(2*size) && (!oppGrid->wasHit(x1,y1))) return true;
return false;
}
else{
if(x1>=x-size-1 && x1<=x+(2*size) && y1>=y-size-1 && y1<=y+size+1 && (!oppGrid->wasHit(x1,y1))) return true;
return false;
}
}

void MultiFunnel::setDirection(bool isVertical){
vertical=isVertical;
}

void MultiFunnel::shoot(int x1,int y1){
if(oppGrid->willItSunk(x1,y1)) interface.sunkAlert();
oppGrid->beShot(x1,y1);
}
