#include "Field.h"
Field::Field(){
state=0;
}

void Field::placeShipPart(){
state=2;
}

void Field::getHit(){
if(state==2) state=3;
else state=1;
}

bool Field::wasHit(){

if(state==1 || state==3) return true;
return false;
}

bool Field::isShip(){
if(state==2) return true;
return false;
}

bool Field::isShipHit(){
if(state==3) return true;
return false;
}

bool Field::isWater(){
if (state==0) return true;
return false;
}
