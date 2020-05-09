# Minesweeper
Group number: 182

Student names:
Siu Ka Sing (3035690373)
Wan Hing Yin (3035690775)

Title: Minesweeper game

Basic game rules: The game will be played on a 9x9 board. The board is divided into cells, which have three states: uncovered, covered and flagged. A covered cell is blank and clickable,which is represented as "X" in the game board, while an uncovered cell is exposed, either containing a number (the number of mines adjacent to it and a space " " will be displayed if the number of mines nearby is 0), or a mine. When a cell is uncovered by a player click, and if it bears a mine, the game ends. A flagged cell is similar to a covered one, in the way that mines are not triggered when a cell is flagged, and it is impossible to lose through the action of flagging a cell. However, flagging a cell implies that a player thinks there is a mine underneath, which causes the game to deduct an available mine from the display.

In the game play the player will be asked which action (either click or flag) to be execute, then the player will be asked to input the x- and y- coordinates of the board that they are going to click or flag. This process will be repeated and continue until the end of the game. 

NOTE:
1. To end the game, please make sure all the blocks are clicked, which means no "X" in the board. No matter whether all mines are flagged or not, you should have opened all the blocks without mines in order to win the game

Fulfilments on code requirements:

1.Generation of random game sets or events:
In the generation of game boards, we applied srand() to randomly generate the position of mines in initial condition.

2.Data structures for storing game status:
The board is stored in two seperate 2D array. The first array is int array and it is used to store the information of blocks including whether it is clicked, unclicked or flagged. The second array is char array and it is used for displaying the board. The game data generated during gameplay like the number of mines nearby will be stored in the second array. Both two array is updating in phrase with the process of game play. 

3.Dynamic memory management:
Dynamic memory arrangement is used in the algorithm of gameplay. When we click on a block, if there is any empty block (no mines nearby and represented as an empty state) nearby, all the empty block will be automatically clicked together with the block clicked by the player. This result in a situation that when a player clicks on a block, many blocks nearby are together being clicked and result in a big blank space in the board. When we are computing the empty blocks nearby, all these empty blocks will be stored in a dynamic array and computed one by one. Finally we can generate the area of blank space and the corresponding numbers they have in the board.

4.File input/output (e.g., for loading/saving game status):
Game status including score and game history will be stored in an external .txt file, namely mkdata.txt. This has implemented the file input/output feature.

5.Program codes in multiple files:
Specific function in the program is stored in separate cpp file and recalled in the main program using .h header.
For instance, the display of explosion is stored in the file explode.h and explode.cpp .
