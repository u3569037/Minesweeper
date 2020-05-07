#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int endgame = 0;
const int SIZE = 9;     //size of map
const int mines = 10;   //10 mines
int board[SIZE][SIZE];
char display_board[SIZE][SIZE];

void genboard(){                   //initiation of the board
  int minepos = 0, minecnt = 0;
  cout << "Welcome to Minesweeper game ^_^" << endl;
  cout << "9x9 board." << endl;
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      board[i][j] = -1;         // value of -1 = unclicked and value of 0 = clicked
  srand(time(NULL));
  while (minecnt < mines){
    minepos = rand() % 81;          //gen 10 coordinates
    if (board[minepos/9][minepos%9] != 1){      //checking for repeat
      board[minepos/9][minepos%9] = 1;        //value of 1 = mine inside
      minecnt += 1;           //count of placed mines
    }
  }
  for (int i=0;i<9;i++){
    for (int j=0;j<9;j++){
      display_board[i][j]='X';
    }
  }
}

void pntboard(){            //print the changed board
    char fill = ' ';
    cout << "* |";
    for (int i = 0; i < SIZE; i++)
      cout << setw(2) << i << '|';
    cout << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < SIZE; i++){
      cout << i << " ";
      for (int j = 0; j < SIZE; j++){
        fill = display_board[i][j];
        cout << "| " << setw(1) << fill;
      }
      cout << "|" << endl;
      cout << "------------------------------" << endl;
    }
}

int num_of_mines(int pos){  //determine the number of mines surrouding the block
  int mines=0;
  if (pos/9+1<9 && pos/9+1>=0 && pos%9+1<9 && pos%9+1>=0){
    if (board[pos/9+1][pos%9+1]==1) mines++;
  } 
  if (pos/9+1<9 && pos/9+1>=0 && pos%9<9 && pos%9>=0){
    if (board[pos/9+1][pos%9]==1) mines++;
  }
  if (pos/9+1<9 && pos/9+1>=0 && pos%9-1<9 && pos%9-1>=0){
    if (board[pos/9+1][pos%9-1]==1) mines++;
  } 
  if (pos/9<9 && pos/9>=0 && pos%9+1<9 && pos%9+1>=0){
    if (board[pos/9][pos%9+1]==1) mines++;
  } 
  if (pos/9<9 && pos/9>=0 && pos%9-1<9 && pos%9-1>=0){
    if (board[pos/9][pos%9-1]==1) mines++;
  } 
  if (pos/9-1<9 && pos/9-1>=0 && pos%9+1<9 && pos%9+1>=0){
    if (board[pos/9-1][pos%9+1]==1) mines++;
  } 
  if (pos/9-1<9 && pos/9-1>=0 && pos%9<9 && pos%9+1>=0){
    if (board[pos/9-1][pos%9]==1) mines++;
  } 
  if (pos/9-1<9 && pos/9-1>=0 && pos%9+1<9 && pos%9+1>=0){
    if (board[pos/9-1][pos%9-1]==1) mines++;
  } 
  return mines;
}

void mvboard(){
  char act = ' ';  // store the user action
  int block[2];  // store the selected block
  cout << "Choose an action: " << endl;
  cout << "F for flag/unflag a block with mine" << endl;
  cout << "C for clicking an unclicked block" << endl;
  cout << "Action: ";
  cin >> act;
  while (act!='C' && act!='F'){
    cout << "Error: Invalid input" << endl;
    cout << "Please input again >w<"<<endl;
    cout << "Action: ";
    cin >> act;
  }
  cout << "Please input the coordinates of the block" << endl;
  cout << "x-coordinate (horizontal axis): ";
  cin >> block[0];
  cout << "y-coordinate (vertical axis): ";
  cin >> block[1];
  while (board[block[1]][block[0]]==0){   //if clicked or flagged a clicked block
      cout << "Error: The selected block is already clicked" << endl;
      cout << "Please input again >w< " << endl;
      cout << "Please input the coordinates of the block" << endl;
      cout << "x-coordinate (horizontal axis): ";
      cin >> block[0];
      cout << "y-coordinate (vertical axis): ";
      cin >> block[1];
  }
  int *sempty= new int [81];   //declare a dynamic array to store the surrouding empty blocks
  for(int i = 0; i < 81; ++i){
    sempty[i] = -1;
  }
  int array_pos=0, runs=0;
  int pos=block[1]*9+block[0];
  if (act == 'F'){
    if (board[pos/9][pos%9]==2){ //unflag
      board[pos/9][pos%9]=-1;
      display_board[pos/9][pos%9] = 'X';
    }
    else{  //flag
      display_board[pos/9][pos%9] = 'F';
    }
  }
  if (act == 'C'){
    if (board[pos/9][pos%9]==1){ // if the user click on a block with mine
       cout << "Bomb!!! You lose >w<" << endl; 
       cout << "Add oil next time ^_^" << endl;
       endgame=1; 
    }
    else{
      display_board[pos/9][pos%9]='0'+num_of_mines(pos);
      if (display_board[pos/9][pos%9] == '0'){
        display_board[pos/9][pos%9] = ' ';
        board[pos/9][pos%9] = 0;
      }
      while (display_board[pos/9][pos%9] == ' ' && pos!=-1){ // find empty blocks nearby and calculate the numbers displayed
        if (pos/9+1<9 && pos/9+1>=0 && pos%9+1<9 && pos%9+1>=0){
          if (num_of_mines(pos+9+1)==0 && board[pos/9+1][pos%9+1]!=1){
            display_board[pos/9+1][pos%9+1] = ' ';
            //determine if the space is repeated with the previous expansion
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos+9+1) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos+9+1;
              array_pos++;
            }
          }
          else if (board[pos/9+1][pos%9+1]!=1){
            display_board[pos/9+1][pos%9+1]='0'+num_of_mines(pos+9+1);
            board[pos/9+1][pos%9+1] = 0;
          }
        } 
        if (pos/9+1<9 && pos/9+1>=0 && pos%9<9 && pos%9>=0){
          if (num_of_mines(pos+9)==0 && board[pos/9+1][pos%9]!=1){
            display_board[pos/9+1][pos%9] = ' ';
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos+9) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos+9;
              array_pos++;
            }
          }
          else if (board[pos/9+1][pos%9]!=1){
            display_board[pos/9+1][pos%9]='0'+num_of_mines(pos+9);
            board[pos/9+1][pos%9] = 0;
          }
        }
        if (pos/9+1<9 && pos/9+1>=0 && pos%9-1<9 && pos%9-1>=0){
          if (num_of_mines(pos+9-1)==0 && board[pos/9+1][pos%9-1]!=1){
            display_board[pos/9+1][pos%9-1] = ' ';
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos+9-1) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos+9-1;
              array_pos++;
            }
          }
          else if (board[pos/9+1][pos%9-1]!=1){
            display_board[pos/9+1][pos%9-1]='0'+num_of_mines(pos+9-1);
            board[pos/9+1][pos%9-1] = 0;
          }
        } 
        if (pos/9<9 && pos/9>=0 && pos%9+1<9 && pos%9+1>=0){
          if (num_of_mines(pos+1)==0 && board[pos/9][pos%9+1]!=1){
            display_board[pos/9][pos%9+1] = ' ';
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos+1) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos+1;
              array_pos++;
            }
          }
          else if (board[pos/9][pos%9+1]!=1){
            display_board[pos/9][pos%9+1]='0'+num_of_mines(pos+1);
            board[pos/9][pos%9+1] = 0;
          }
        } 
        if (pos/9<9 && pos/9>=0 && pos%9-1<9 && pos%9-1>=0){
          if (num_of_mines(pos-1)==0 && board[pos/9][pos%9-1]!=1){
            display_board[pos/9][pos%9-1] = ' ';
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos-1) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos-1;
              array_pos++;
            }
          }
          else if (board[pos/9][pos%9-1]!=1){
            display_board[pos/9][pos%9-1]='0'+num_of_mines(pos-1);
            board[pos/9][pos%9-1] = 0;
          }
        } 
        if (pos/9-1<9 && pos/9-1>=0 && pos%9+1<9 && pos%9+1>=0){
          if (num_of_mines(pos-9+1)==0 && board[pos/9-1][pos%9+1]!=1){
            display_board[pos/9-1][pos%9+1] = ' ';
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos-9+1) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos-9+1;
              array_pos++;
            }
          }
          else if (board[pos/9-1][pos%9+1]!=1){
            display_board[pos/9-1][pos%9+1]='0'+num_of_mines(pos-9+1);
            board[pos/9-1][pos%9+1] = 0;
          }
        } 
        if (pos/9-1<9 && pos/9-1>=0 && pos%9<9 && pos%9>=0){
          if (num_of_mines(pos-9)==0 && board[pos/9-1][pos%9]!=1){
            display_board[pos/9-1][pos%9] = ' ';
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos-9) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos-9;
              array_pos++;
            }
          }
          else if (board[pos/9-1][pos%9]!=1){
            display_board[pos/9-1][pos%9]='0'+num_of_mines(pos-9);
            board[pos/9-1][pos%9] = 0;
          }
        } 
        if (pos/9-1<9 && pos/9-1>=0 && pos%9-1<9 && pos%9-1>=0){
          if (num_of_mines(pos-9-1)==0 && board[pos/9-1][pos%9-1]!=1){
            display_board[pos/9-1][pos%9-1] = ' ';
            int repeat=0;
            for (int i=0;i<array_pos+1;i++){
              if (sempty[i]==pos-9-1) repeat=1;
            }
            if (repeat==0){
              sempty[array_pos]=pos-9-1;
              array_pos++;
            }
          }
          else if (board[pos/9-1][pos%9-1]!=1){
            display_board[pos/9-1][pos%9-1]='0'+num_of_mines(pos-9-1);
            board[pos/9-1][pos%9-1] = 0;
          }
        }
        if (sempty[runs]!=-1){
          pos=sempty[runs];
          runs++;
        }
        else pos=-1;
      }
    }
  }
  delete [] sempty; 
}

int main(){
  genboard();
  while (endgame == 0){
    pntboard();
    mvboard();
  }
  return 0;
}
