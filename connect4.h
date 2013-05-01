//Simon O'Shea 09006479
//Thomas Newe - CE4704 - Computer Software 4

#ifndef CONNECT_4
#define CONNECT_4
#include<iostream>
#include<iomanip>

using namespace std;

//class grid
class Grid{

char board[6][8]; //board size
public:
//construct grid
Grid(){
int row,col;

for(row=0; row<6; row++)
for(col=0; col<8; col++)
board[row][col]=' ';
}


~Grid(){} //deconstruct grid


void draw_board();
void play_game();
void blank_board(); //create blank board
bool check_row(int, int, char); //row check
bool check_col(int, int, char); //column check
bool check_dup(int, int, char); //diagonal up check
bool check_ddown(int, int, char); //diagonal down check
};

//print board method
void Grid::draw_board(){
int row, col;

cout<<" 0   1   2   3   4   5   6   7  \n"; //print column number above columns
for(row = 0; row< 6; row++)
{
for(col =0; col <= 7; col++) cout<<char(218)<<char(196)<<char(191)<<" ";			//for loops create box's
cout<<'\n';																			
for(col =0; col <= 7; col++) cout<<char(179)<<board[row][col]<<char(179)<<" ";			
cout<<'\n';
for(col =0; col <= 7; col++) cout<<char(192)<<char(196)<<char(217)<<" ";
cout<<'\n';
}
cout<<" 0   1   2   3   4   5   6   7  \n\n"; //print column number below columns

}

void Grid::blank_board(){ //clear board
int row, col;

for(row=0; row<6; row++)
for(col=0; col<8; col++)

board[row][col]=' ';
cout<<'\n';
}

//game
void Grid::play_game(){
int row, col;
int player=1;
char player_chip=(char)254;	//chip is players counter/checker/token

Grid::draw_board();
do
{
(player==1)?player_chip=(char)254:player_chip=(char)5;

if ( player == 1) //if statement to change the color of grid
{
	system("color 4"); //red
}
else
	system("color 6"); //yellow
cout<<"Player "<<player<<" select a column to place your move -> "<<player_chip<<"\n\n";

cout<<" (Press 0 to forfeit!!)\n";
cin>>col;
cout<<'\n';
if(col==0)
{
cout<<"Better luck next time!!\n\n";
return;
}

for(row=5; row>=0;row--)

if(board[row][col]==' ')
{
board[row][col]=player_chip;
break;
}

draw_board();

if(check_col(row,col,player_chip)||
check_row(row,col,player_chip)||
check_dup(row,col,player_chip)||
check_ddown(row,col,player_chip))

{

cout<<"Player "<<player<<" wins!\n";

return;
}
(player==1)?player=2:player=1; //alternate players turn
}
while(1);
}


//check win condition
bool Grid::check_row(int row, int col, char player_chip){
int i;
int vertical = 1;

for(i = row +1;board[i][col] == player_chip && i <= 5;i++,vertical++); //Check down
for(i = row -1;board[i][col] == player_chip && i >= 0;i--,vertical++); //Check up

if(vertical >= 4)return true; // 4 chips were found vertically (|)
return false;
}

bool Grid::check_col(int row, int col, char player_chip){
int ii;
int horizontal = 1;

for(ii = col +1;board[row][ii] == player_chip && ii <= 7;ii++,horizontal++); //Check down
for(ii = col -1;board[row][ii] == player_chip && ii >= 0;ii--,horizontal++); //Check up

if(horizontal >= 4)return true; // 4 chips were found horizontally(-)
return false;
}

bool Grid::check_dup(int row, int col, char player_chip){ //check diagonal up
int diagonalright = 1;
int i, ii;
//check for left diag (\)
for(i = row -1, ii= col-1;board[i][ii] == player_chip && i>=0 && ii >=0; diagonalright ++, i --, ii --); //Up and left
for(i = row +1, ii = col+1;board[i][ii] == player_chip && i<=5 && ii <=6;diagonalright ++, i ++, ii ++); //Down and right
if(diagonalright >= 4) return true; //4 chips found
}

bool Grid::check_ddown(int row, int col, char player_chip){ //check diagonal down
int diagonalleft = 1;
int i, ii;
//check for right diag(/)
for(i = row -1, ii= col+1;board[i][ii] == player_chip && i>=0 && ii <= 6; diagonalleft ++, i --, ii ++); //Up and right
for(i = row +1, ii= col-1;board[i][ii] == player_chip && i<=5 && ii >=0; diagonalleft ++, i ++, ii --); //Up and left
if(diagonalleft >= 4) return true; //4 chips were found
return false;
}

#endif