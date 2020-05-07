#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int endgame = 0;
const int SIZE = 9;        //size of map
const int mines = 10; //10 mines
int board[SIZE][SIZE];

void genboard(){
  int minepos = 0, minecnt = 0;
  cout << "Welcome to Minesweeper game." << endl;
  cout << "9x9 board." << endl;
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      board[i][j] = -1;         // value of -1 = unclicked
  srand(time(NULL));
  while (minecnt < mines){
    minepos = rand() % 81;          //gen 10 coordinates
    if (board[minepos/9][minepos%9] != 1){      //checking for repeat
      board[minepos/9][minepos%9] = 1;        //value of 1 = mine inside
      minecnt += 1;           //count of placed mines
    }
  }
}

void pntboard(){            //print the board
  char fill = ' ';
    cout << "* |";
    for (int i = 0; i < SIZE; i++)
      cout << setw(2) << i << '|';
    cout << endl;
    for (int i = 0; i < SIZE; i++){
      cout << i << " ";
      for (int j = 0; j < SIZE; j++){
        if (board[i][j] == -1)        //value -1, unclicked empty blocks (displayed as a space ' ')
          fill = ' ';
        else if (board[i][j] == 0)        // value 0 = clikced empty blocks (displayed as 'O')
          fill = 'O';
            else if (board[i][j] == 2)
              fill = 'F';                 // Flagged blocks, value 2, (displated as 'F')
        cout << "| " << setw(1) << fill;
      }
      cout << "|" << endl;
      cout << "______________________________" << endl;
    }
}

void mvboard(){
  char act = ' ';
  cout << "Choose an action, F for flag/unflag a block with mine." << endl;
  cout << "C for clicking an unclicked block" << endl;
//to be implmented

}

int main(){
  genboard();
  //while (endgame == 0){
//    pntboard();
//    mvboard();
//  }
  return 0;
}
