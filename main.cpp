#include "Game.h"
#include <memory>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void help(){
cout<<"How to run game:\nProgram [number of rounds] [computer strategy (Player2)] [*OPTIONAL computer strategy in computer vs computer game (Player1)]"<<endl;
cout<<"Computer strategy options: 'random' or 'greedy'"<<endl;
}

int main(int argc, char* argv[]) {
    srand(time(0));
    shared_ptr<Grid> myGrid = make_shared<Grid>();
    shared_ptr<Grid> oppGrid = make_shared<Grid>();
    Game newGame;
    if(argc<3) {help();return 0;}
    else{
        if(atoi(argv[1])>20 || atoi(argv[1])<1) {help();return 0;}
        if(string(argv[2])=="random" && argc==3)  newGame=Game(2,atoi(argv[1]),myGrid,oppGrid);
        else if(string(argv[2])=="greedy" && argc==3) newGame=Game(1,atoi(argv[1]),myGrid,oppGrid);
        else if(argc==3) {help();return 0;}
        else if(string(argv[2])=="random" && string(argv[3])=="random") newGame=Game(3,atoi(argv[1]),myGrid,oppGrid);
        else if(string(argv[2])=="greedy" && string(argv[3])=="greedy") newGame=Game(5,atoi(argv[1]),myGrid,oppGrid);
        else if(string(argv[2])=="random" && string(argv[3])=="greedy") newGame=Game(4,atoi(argv[1]),myGrid,oppGrid);
        else if(string(argv[2])=="greedy" && string(argv[3])=="random") newGame=Game(6,atoi(argv[1]),myGrid,oppGrid);
        else {help();return 0;}
        newGame.initialize();
        newGame.startGame();
    }




    return 0;
}
