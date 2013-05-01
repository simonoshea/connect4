//Simon O'Shea
//CE4704 - Computer Software 4

#include<iostream>

#include "connect4.h"
using namespace std;
int main()
{
int menu; //menu control
bool flag = true;
Grid game;


while(flag==true)
{
game.blank_board();
//print welcome screen
cout << setw(40) << "|**************************************| \n";
cout << setw(40) << "|***|------------------------------|***| \n";
cout << setw(40) << "|***|    Welcome to the Connect 4  |***| \n";
cout << setw(40) << "|***|_                            _|***| \n";
cout << setw(40) << "|*****| Simon O'Shea - 09006479  |*****| \n";
cout << setw(40) << "|*****|__________________________|*****| \n";
cout << setw(40) << "|**************************************| \n";
cout << setw(40) << "|**************************************| \n\n";
cout << setw(40) << "|**************************************| \n";
cout << setw(40) << "|     What do you want to do?          | \n";	//print options for menu
cout << setw(40) << "|       1 - Play Now!                  | \n";
cout << setw(40) << "|       2 - Exit                       | \n";
cout << setw(40) << "|**************************************| \n\n\n";
cin>>menu;
cout << "\n\n";


//menu options
switch(menu)
{

case 1: game.play_game(); //case 1 - play
flag=true;
break;

case 2: cout<<"See Ya"; //case 2 - exit
flag=false;
break;

default: cout<<"Select 1 or 2!!!"; //case 3 - error
flag=true;
break;

}
}
return 0;
}
