#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tile{
  
private:
  const int BOMB_PROBABILITY = 10;
  bool visible = false;
  bool bomb = false;
  int value;
  
public:
  Tile(){
    if(rand() % 100 <  BOMB_PROBABILITY){
      bomb = true;
    }  
  }
  
  const bool getStatus() const{//Is it chosen or not
    return visible;
  }

  const int getValue() const{//Get Value
    return value;
  }

  const bool isBomb() const{//Test if it's a bomb
    return bomb;
  }

  const bool chosen() { //It's chosen, return if bomb or not
    visible  = true;
    return bomb;
  }

  void setValue(const int& adjacentBombs) {
    value = adjacentBombs;
  }
};


class Minesweeper{

private:
  const int ROWS = 10;
  const int COLS = 10;
  bool gameOver = false;
  
  vector <vector <Tile> > board; //Creates a board of chars for minesweeper

public:

  Minesweeper(){
    //Make the board
    srand (time(NULL));
    for (int r = 0; r < ROWS; r++){
      vector <Tile> temp;
      for (int c = 0; c < COLS; c++){
	Tile t;
	temp.push_back(t);
      }
      board.push_back(temp);
    }

    //Test bombs around it
    for (int r = 0; r < ROWS; r++){
      for (int c = 0; c < COLS; c++){
        if(!board[r][c].isBomb()){
	  board[r][c].setValue(bombCount(r, c));
	}
      }
    }
  }
  const int bombCount(const int r, const int c) {
    int count = 0;
    if(c-1 > 0){
      if(board[r][c-1].isBomb())
	count+=1;
    }
    if(c+1 < COLS){
      if(board[r][c+1].isBomb())
	count +=1;
    }
    if(r-1 > 0){
      if(board[r-1][c].isBomb())
	count+=1;
    }
    if(r+1 < ROWS){
      if(board[r+1][c].isBomb())
	count+=1;
    }
    if(r-1 > 0 && c-1 > 0){
      if(board[r-1][c-1].isBomb())
	count+=1;
    }
    if(r+1 < ROWS && c-1 > 0){
      if(board[r+1][c-1].isBomb())
	count+=1;
    }
    if(r-1 > 0 && c+1 < COLS){
      if(board[r-1][c+1].isBomb())
	count +=1;
    }
    if(r+1 < ROWS && c+1 < COLS){
      if(board[r+1][c+1].isBomb())
	count+=1;
    }
    return count;
  }
  
  void ripple(const int r, const int c){
    if(c-1 >= 0){
      board[r][c-1].chosen();
    }
    if(c+1 < COLS){
      board[r][c+1].chosen();
    }
    if(r-1 >= 0){
      board[r-1][c].chosen();
    }
    if(r+1 < ROWS){
      board[r+1][c].chosen();
    }
    if(r-1 > 0 && c-1 >0){
      board[r-1][c-1].chosen();
    }
    if(r+1 < ROWS && c-1 >= 0){
      board[r+1][c-1].chosen();
    }
    if(r-1 > 0 && c+1 < COLS){
      board[r-1][c+1].chosen();      
    }
    if(r+1 < ROWS && c+1 < COLS){
      board[r+1][c+1].chosen();
    }
  }
  
 void ripple2(vector <vector <Tile> >& v) { 
    for(int i =0; i < ROWS; i++){
      for(int r = 0; r < ROWS; r++){
	for(int c = 0; c < COLS; c++){
	  if(v[r][c].getStatus()){
	    if(v[r][c].getValue() == 0){
	      ripple(r,c);}
	  }
	}
      }
    }
  }

  //Show board
  void display(bool show) {
    ripple2(board);
    if(!show){
      //Show board without bombs
      for(int r =0; r < ROWS; r++){
	for(int c = 0; c < COLS; c++){
	  if(board[r][c].getStatus()){
	    cout << board[r][c].getValue();}
	  else{
	    cout << "-";
	  }
	}
	cout<<endl;	  
      }
    }
    else{
      //Show board with bombs
      for(int r =0; r < ROWS; r++){
	for(int c = 0; c < COLS; c++){
	  if(board[r][c].isBomb()){
	    cout<<"*";
	  }
	  else{
	    cout<<board[r][c].getValue();
	  }
	}
	cout<<endl;	  
      }
    }
  }

  const bool done() {
    return gameOver;
  }
  
  //Test if row is valid
  bool validRow(const int row) const {
    return ((row-1)>=0) && ((row-1)< ROWS);
  }

  //Test if column is valid
  bool validCol(const int col) const {
    return ((col-1)>=0) && ((col-1)< COLS);
  }

  //Test if tile was chosen already
  bool isVisible(const int row, const int col) const {
    return board[row-1][col-1].getStatus();
  }
  
  //Choose tile
  bool play(const int row, const int col){
    board[row-1][col-1].chosen();
    if(board[row-1][col-1].chosen()){
      gameOver = true;}
    else if(board[row-1][col-1].getValue() == 0){
      ripple(row-1, col-1);
    }
    return !board[row-1][col-1].chosen();
  }
};



int main() {
  Minesweeper sweeper;
  sweeper.display(true);
  // Continue until only invisible cells are bombs
  while (!sweeper.done()) {
    sweeper.display(false); // Display board without bombs

    int row_sel = -1, col_sel = -1;
    while (row_sel == -1) {
      // Get a valid move
      int r, c;
      cout << "row? ";
      cin >> r;
      if (!sweeper.validRow(r)) {
	cout << "Row out of bounds\n";
	continue;
      }
      cout << "col? ";
      cin >> c;
      if (!sweeper.validCol(c)) {
	cout << "Column out of bounds\n";
	continue;
      }
      if (sweeper.isVisible(r,c)) {
	cout << "Square already visible\n";
	continue;
      }
      row_sel = r;
      col_sel = c;
    }
    // Set selected square to be visible. May effect other cells.
    if (!sweeper.play(row_sel,col_sel)) {
      cout << "Sorry, you died..\n";
      sweeper.display(true); // Final board with bombs shown
      exit(0);
    }
  }
  // Ah! All invisible cells are bombs, so you won!
  cout << "You won!!!!\n";
  sweeper.display(true); // Final board with bombs shown
}
