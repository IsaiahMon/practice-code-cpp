/*
 * rec01.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: Isaiah Mon Desir
 */

#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;

using namespace std;

int main(){
	int rows = 0;
	int cols = 0;
	vector <int> base;//base vector
	//Open up the File Life.tt
	ifstream ifs("life.txt");

	//Test if file opened
	if (!ifs) {
	   cerr << "Could not open the file.\n";
	   exit(1);
	}

	//Get Dimensions of Table
	string line;
	while (getline(ifs, line)) {
		cols = 0 ;
		++rows;
		for (char aChar: line){
			base.push_back(aChar);
			++cols;
		}
	}
	ifs.close();

	vector <vector<int> >board; //Empty vector for the game of life board

	//Sets the dimensions of the empty board to rows*cols
	for(int r = 0; r <rows; ++r){
		vector<int> aRow;
		for (int c = 0; c <cols; ++c){
			aRow.push_back(0);
		}
		board.push_back(aRow);
	}
	int i = 0;
	for (int r = 0; r < rows; ++r){
		for (int c = 0; c < cols; ++c){
			if(base[i] == '*'){
				board[r][c] = 1;
			}
			else{
				board[r][c] = 0;
			}
			++i;
		}
	}
	cout << "How many Generations?"<<endl;
	int gen = 10;
	cin >> gen;
	vector <vector<int> >tempBoard = board; //mutable board for future generations
	//Print original
	cout << "Initial World" <<endl;
	for (int r = 0; r < rows; ++r){
		for (int c = 0; c < cols; ++c){
			if(board[r][c] == 0)
				cout << '-';
			else
				cout << '*';
		}
		cout << endl;
	}
	cout << "===========================" <<endl;


	for (int i = 0; i < gen; ++i){ //Repeat per generation
		board = tempBoard;
		for (int r = 0; r < rows; ++r){
				for (int c = 0; c < cols; ++c){
					vector<int> neighbors; //Test for neighbors in cases cell is on border
					if(r == 0 && c ==0){
						neighbors.push_back(board[r+1][c]);
						neighbors.push_back(board[r+1][c+1]);
						neighbors.push_back(board[r][c+1]);
					}
					else if(r ==0 && c>0 && c <cols){
						neighbors.push_back(board[r][c+1]);
						neighbors.push_back(board[r][c-1]);
						neighbors.push_back(board[r+1][c]);
						neighbors.push_back(board[r+1][c+1]);
						neighbors.push_back(board[r+1][c-1]);
					}
					else if(r == rows -1 && c >0){
						neighbors.push_back(board[r][c+1]);
						neighbors.push_back(board[r][c-1]);
						neighbors.push_back(board[r-1][c+1]);
						neighbors.push_back(board[r-1][c]);
						neighbors.push_back(board[r-1][c-1]);
					}
					else if(c ==0 && r >0 && r < rows-1){
						neighbors.push_back(board[r-1][c]);
						neighbors.push_back(board[r+1][c]);
						neighbors.push_back(board[r+1][c+1]);
						neighbors.push_back(board[r-1][c+1]);
						neighbors.push_back(board[r][c+1]);
					}
					else if(c == cols-1 && r>0){
						neighbors.push_back(board[r][c-1]);
						neighbors.push_back(board[r-1][c]);
						neighbors.push_back(board[r+1][c]);
						neighbors.push_back(board[r+1][c-1]);
						neighbors.push_back(board[r-1][c-1]);
					}
					else if(r > 0 && c>0 && r < rows && c < cols  ){
						neighbors.push_back(board[r][c+1]);
						neighbors.push_back(board[r][c-1]);
						neighbors.push_back(board[r+1][c]);
						neighbors.push_back(board[r-1][c]);
						neighbors.push_back(board[r+1][c+1]);
						neighbors.push_back(board[r+1][c-1]);
						neighbors.push_back(board[r-1][c+1]);
						neighbors.push_back(board[r-1][c-1]);
					}
					else{
						neighbors.push_back(board[r-1][c]);
						neighbors.push_back(board[r-1][c-1]);
						neighbors.push_back(board[r][c-1]);
					}

					int ones =0;
					int zeros =0;
					int status;

					for(int x: neighbors){
						if(x ==1){
							++ones;
						}
						else if(x ==0){
							++zeros;
						}
					}

					//If living
					if(board[r][c] == 1){
						if(ones == 2 || ones == 3){
							status = 1;
						}
						else{
							status = 0;
						}
					}
					//If dead
					if(board[r][c] == 0){
						if(ones == 3){
							status = 1;
						}
						else{
							status = 0;
						}
					}
					tempBoard[r][c] = status;
					neighbors.clear();
				}
		}

		//Print new
			cout << "Generation: " << i+1 <<endl;
			for (int r = 0; r < rows; ++r){
				for (int c = 0; c < cols; ++c){
					if(tempBoard[r][c] == 0)
						cout << '-';
					else
						cout << '*';
				}
				cout << endl;
			}
			cout << "===========================" <<endl;
			board = tempBoard;
	}

}
