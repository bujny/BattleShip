#include "UserInterface.h"
#include <iostream>
#include <string>

using namespace std;

UserInterface::UserInterface(shared_ptr<Grid> myGrid1, shared_ptr<Grid> oppGrid1, bool isCompOnly1):isCompOnly(isCompOnly1){
myGrid=myGrid1;
oppGrid=oppGrid1;
}

void UserInterface::startScreen(){
cout<<"Welcome to the Battleship game!"<<endl;
cout<<"Legend: o is water, = is a ship's part, # is a destroyed ship's part, x is a place that was shot"<<endl;
cout<<"Are You ready? (type 'y' for yes)"<<endl;
char y;
do{
    cin>>y;
}while(y!='y');
}

void clearScreen(){
cout<<string(7,'\n');
}

void UserInterface::printHuman(){
clearScreen();

cout<<"Player 1:"<<endl;
cout<<". 0 1 2 3 4 5 6 7 8 9 (x)"<<endl;
for(int y=0;y<10;y++){
cout<<y;
for (int x=0;x<10;x++){
cout<<" "<<myGrid->printHuman(x,y);
}
cout<<endl;
}
cout<<"(y)"<<endl;

cout<<"Player 2:"<<endl;
cout<<". 0 1 2 3 4 5 6 7 8 9 (x)"<<endl;
for(int y=0;y<10;y++){
cout<<y;
for (int x=0;x<10;x++){
cout<<" "<<oppGrid->printOpp(x,y);
}
cout<<endl;
}
cout<<"(y)"<<endl;
}

void UserInterface::printComputer(){
if(!isCompOnly) return;
else{
clearScreen();

cout<<"Player 1:"<<endl;
cout<<". 0 1 2 3 4 5 6 7 8 9 (x)"<<endl;
for(int y=0;y<10;y++){
cout<<y;
for (int x=0;x<10;x++){
cout<<" "<<myGrid->printComp(x,y);
}
cout<<endl;
}
cout<<"(y)"<<endl;

cout<<"Player 2:"<<endl;
cout<<". 0 1 2 3 4 5 6 7 8 9 (x)"<<endl;
for(int y=0;y<10;y++){
cout<<y;
for (int x=0;x<10;x++){
cout<<" "<<oppGrid->printComp(x,y);
}
cout<<endl;
}
cout<<"(y)"<<endl;

}}

void UserInterface::canNotPlaceHere(){

cout<<"You cannot place ship here, try again!"<<endl;
}

void UserInterface::thisCanNotTakeShot(){
cout<<"This ship cannot take shot, try again!"<<endl;
}

void UserInterface::hereCanNotTakeShot(){
cout<<"You cannot shoot here, try again!"<<endl;
}

void UserInterface::sunkAlert(){
cout<<"S U N K !!!"<<endl;
}

int UserInterface::chooseShip(){
int n;
cout<<"Choose ship (write 1, 2 or 3)"<<endl;
while(1){
cin>>n;
if(n==1) return 0;
if(n==2) return 1;
if(n==3) return 2;
cout<<"Wrong input, try again!"<<endl;
}
}

int *chooseXY(int *xy){
cout<<"Specify x and y:"<<endl;
xy= new int[2];
do{
cin>>xy[0]>>xy[1];
if(xy[0]<0 || xy[1]<0 || xy[0]>9 || xy[1]>9)cout<<"Range of x and y is 0-9, try again!"<<endl;
}while(xy[0]<0 || xy[1]<0 || xy[0]>9 || xy[1]>9);
return xy;
}

int *UserInterface::placeOneFunnel(int *xy)
{
cout<<"Place your One-Funnel ship."<<endl;
xy=chooseXY(xy);
return xy;
}

int *UserInterface::placeTwoFunnel(int *xy)
{
cout<<"Place your Two-Funnel ship."<<endl;
xy=chooseXY(xy);
return xy;
}

int *UserInterface::placeThreeFunnel(int *xy)
{
cout<<"Place your Three-Funnel ship."<<endl;
xy=chooseXY(xy);
return xy;
}

int *UserInterface::takeShot(int *xy)
{
cout<<"IT'S TIME TO SHOOT SOMETHING!"<<endl;
xy=chooseXY(xy);
return xy;
}

bool UserInterface::verticalTwoFunnel(){
cout<<"Choose orientation of your Two-Funnel ship (write 'v' for vertical or 'h' for horizontal)"<<endl;
do{
char c;
cin>>c;
if(c=='v') return true;
if(c=='h') return false;
cout<<"Wrong input, try again!"<<endl;
}while(1);
}

bool UserInterface::verticalThreeFunnel(){
cout<<"Choose orientation of your Three-Funnel ship (write 'v' for vertical or 'h' for horizontal)"<<endl;
do{
char c;
cin>>c;
if(c=='v') return true;
if(c=='h') return false;
cout<<"Wrong input, try again!"<<endl;
}while(1);
}

bool UserInterface::wantShootTwice(){
cout<<"Do you want to take additional shoot? (write 'y' for yes or 'n' for no)"<<endl;
do{
char c;
cin>>c;
if(c=='y') return true;
if(c=='n') return false;
cout<<"Wrong input, try again!"<<endl;
}while(1);
}

void UserInterface::playerWon(int n){
if(n==1) cout<<"PLAYER ONE HAS WON! CONGRATULATIONS!!!"<<endl;
else if(n==2) cout<<"PLAYER TWO HAS WON! CONGRATULATIONS!!!"<<endl;
else cout<<"IT'S A DRAW!!!"<<endl;
}
