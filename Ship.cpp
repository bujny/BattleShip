#include "Ship.h"
#include <memory>


Ship::Ship(std::shared_ptr<Grid> myGrid1, std::shared_ptr<Grid> oppGrid1,UserInterface anInterface){
myGrid=myGrid1;
oppGrid=oppGrid1;
anInterface=interface;
}

int Ship::getSize(){
return size;
}

bool Ship::canPlaceShip(int x1,int y1){
if(x<0 || x>9 || y<0 || y>9) return false;
if(isVertical()){
if(size==2) if(y1>8) return false;
if(size==3) if(y1>7) return false;
for(int i=x1-1;i<=x1+1;i++)
for(int j=y1-1;j<=y1+size;j++)
if(myGrid->isShip(i,j)) return false;
return true;
}
else{
if(size==2) if(x1>8) return false;
if(size==3) if(x1>7) return false;
for(int i=x1-1;i<=x1+size;i++)
for(int j=y1-1;j<=y1+1;j++)
if(myGrid->isShip(i,j)) return false;
return true;
}
}

void Ship::placeShip(int x1, int y1){
x=x1;
y=y1;
if(isVertical()){
for(int k=y;k<y+size;k++)
myGrid->placeShipPart(x,k);
}
else{
for(int k=x;k<x+size;k++)
myGrid->placeShipPart(k,y);
}
}
