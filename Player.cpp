#include "Ship.h"
#include "Strategy.h"
#include "Player.h"
#include "HumanStrategy.h"


Player::Player(shared_ptr<Strategy> aStrategy,shared_ptr<OneFunnel> ship1,shared_ptr<Ship> ship2,shared_ptr<Ship> ship3){
strategy=aStrategy;
myShips[0]=ship1;
myShips[1]=ship2;
myShips[2]=ship3;
}

void Player::placeShips(){
strategy->placeShips(myShips);
}

void Player::makeMove(){
strategy->makeMove(myShips);
}

bool Player::canTakeShot(){
for(int i=0;i<3;i++) if(myShips[i]->canTakeShot()) return true;
return false;
}

bool Player::areMyShipsSunk(){
for(int i=0;i<3;i++) if(!myShips[i]->isSunk()) return false;
return true;
}
