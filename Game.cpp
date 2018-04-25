#include "Game.h"
#include "UserInterface.h"
#include "OneFunnel.h"
#include "MultiFunnel.h"
#include "CompGreedyStrategy.h"
#include "CompRandomStrategy.h"
#include "HumanStrategy.h"
#include "Grid.h"

using namespace std;

void Game::initialize(){

if(mode>2) anInterface=UserInterface(myGrid,oppGrid,true);
else anInterface=UserInterface(myGrid,oppGrid,false);

switch (mode){
case 1:{
myPlayer=Player(make_shared<HumanStrategy>(anInterface),make_shared<OneFunnel>(myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(2,myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(3,myGrid,oppGrid,anInterface));
oppPlayer=Player(make_shared<CompGreedyStrategy>(anInterface),make_shared<OneFunnel>(oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(2,oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(3,oppGrid,myGrid,anInterface));
break;}
case 2:{
myPlayer=Player(make_shared<HumanStrategy>(anInterface),make_shared<OneFunnel>(myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(2,myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(3,myGrid,oppGrid,anInterface));
oppPlayer=Player(make_shared<CompRandomStrategy>(anInterface),make_shared<OneFunnel>(oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(2,oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(3,oppGrid,myGrid,anInterface));
break;}
case 3:{
myPlayer=Player(make_shared<CompRandomStrategy>(anInterface),make_shared<OneFunnel>(myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(2,myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(3,myGrid,oppGrid,anInterface));
oppPlayer=Player(make_shared<CompRandomStrategy>(anInterface),make_shared<OneFunnel>(oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(2,oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(3,oppGrid,myGrid,anInterface));
break;}
case 4:{
myPlayer=Player(make_shared<CompRandomStrategy>(anInterface),make_shared<OneFunnel>(myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(2,myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(3,myGrid,oppGrid,anInterface));
oppPlayer=Player(make_shared<CompGreedyStrategy>(anInterface),make_shared<OneFunnel>(oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(2,oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(3,oppGrid,myGrid,anInterface));
break;}
case 5:{
myPlayer=Player(make_shared<CompGreedyStrategy>(anInterface),make_shared<OneFunnel>(myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(2,myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(3,myGrid,oppGrid,anInterface));
oppPlayer=Player(make_shared<CompGreedyStrategy>(anInterface),make_shared<OneFunnel>(oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(2,oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(3,oppGrid,myGrid,anInterface));
break;}
case 6:{
myPlayer=Player(make_shared<CompGreedyStrategy>(anInterface),make_shared<OneFunnel>(myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(2,myGrid,oppGrid,anInterface),make_shared<MultiFunnel>(3,myGrid,oppGrid,anInterface));
oppPlayer=Player(make_shared<CompRandomStrategy>(anInterface),make_shared<OneFunnel>(oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(2,oppGrid,myGrid,anInterface),make_shared<MultiFunnel>(3,oppGrid,myGrid,anInterface));
break;}
}
}

void Game::startGame(){
anInterface.startScreen();
int rnd=0;
myPlayer.placeShips();
oppPlayer.placeShips();
while(rnd<rounds && !myPlayer.areMyShipsSunk() && !oppPlayer.areMyShipsSunk() && myPlayer.canTakeShot() && oppPlayer.canTakeShot() ){
rnd++;
myPlayer.makeMove();
oppPlayer.makeMove();
}
//ROZKMIN CZY DOBRZE POKAZUJE WYGRANEGO
if(myPlayer.areMyShipsSunk()) anInterface.playerWon(2);
else if(oppPlayer.areMyShipsSunk()) anInterface.playerWon(1);
else if(!myPlayer.canTakeShot()) anInterface.playerWon(2);
else if(!oppPlayer.canTakeShot()) anInterface.playerWon(1);
else if(myGrid->getShips()==oppGrid->getShips()) anInterface.playerWon(0);
else if(myGrid->getShips()<oppGrid->getShips()) anInterface.playerWon(2);
else anInterface.playerWon(1);
}
