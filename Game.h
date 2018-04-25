#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Player.h"


using namespace std;

class Game{
int mode; // 1 - human vs greedy 2 - human vs random 3 - random vs random  4 random vs greedy 5 - greedy vs greedy 6 - greedy vs random
int rounds;
shared_ptr<Grid> myGrid;
shared_ptr<Grid> oppGrid;
UserInterface anInterface;
Player myPlayer;
Player oppPlayer;

public:
Game(int mode1, int rounds1,shared_ptr<Grid> myGrid1,shared_ptr<Grid> oppGrid1): mode(mode1),rounds(rounds1){myGrid=myGrid1;oppGrid=oppGrid1;}
Game(){}
void initialize();
void startGame();
};

#endif
