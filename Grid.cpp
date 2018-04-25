#include "Field.h"
#include "Ship.h"
#include "Grid.h"
void Grid::beShot(int x, int y){
fields[y][x].getHit();
}

bool Grid::wasHit(int x, int y){
if(x<0 || y<0 || x>9 || y>9) return true;
return fields[y][x].wasHit();
}

bool Grid::isShip(int x, int y){
if(x<0 || y<0 || x>9 || y>9) return false;
if(fields[y][x].isShip()) return true;
return false;
}

void Grid::placeShipPart(int x,int y){
fields[y][x].placeShipPart();
}

bool Grid::willItSunk(int x,int y){
if(!fields[y][x].isShip()) return false;

if(x>0){
if(fields[y][x-1].isShip()) return false;
else if(x>1 && fields[y][x-1].isShipHit()) if(fields[y][x-2].isShip()) return false;
}

if(y>0){
if(fields[y-1][x].isShip()) return false;
else if(y>1 && fields[y-1][x].isShipHit()) if(fields[y-2][x].isShip()) return false;
}

if(x<9){
if(fields[y][x+1].isShip()) return false;
else if(x<8 && fields[y][x+1].isShipHit()) if(fields[y][x+2].isShip()) return false;
}

if(y<9){
if(fields[y+1][x].isShip()) return false;
else if(y<8 && fields[y+1][x].isShipHit()) if(fields[y+2][x].isShip()) return false;
}

return true;
}

char Grid::printHuman(int x, int y){
if(fields[y][x].isWater()) return 'o';
if(fields[y][x].isShip()) return '=';
if(fields[y][x].isShipHit()) return '#';
return 'x';
}

char Grid::printOpp(int x, int y){
if(fields[y][x].isWater()) return 'o';
if(fields[y][x].isShipHit()) return '#';
if(fields[y][x].wasHit()) return 'x';
return 'o';
}

char Grid::printComp(int x, int y){
if(fields[y][x].isWater()) return 'o';
if(fields[y][x].isShip()) return '=';
if(fields[y][x].isShipHit()) return '#';
return 'x';
}

int Grid::getShips(){
int counter=0;
for(int i=0;i<10;i++)
for(int j=0;j<10;j++)
if(fields[i][j].isShip()) counter++;
return counter;
}
