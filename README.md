# Minesweeper
Group number: 182

Student names:
Siu Ka Sing (3035690373)
Wan Hing Yin (3035690775)

Title: Minesweeper game
Basic game rules: The game will be played on a 9x9 board. The board is divided into cells, which have three states: uncovered, covered and flagged. A covered cell is blank and clickable, while an uncovered cell is exposed, either containing a number (the number of mines adjacent to it), or a mine. When a cell is uncovered by a player click, and if it bears a mine, the game ends. A flagged cell is similar to a covered one, in the way that mines are not triggered when a cell is flagged, and it is impossible to lose through the action of flagging a cell. However, flagging a cell implies that a player thinks there is a mine underneath, which causes the game to deduct an available mine from the display.

Proposed fulfilments on code requirements:
1. The random locations of mines in the board will apply the generation of random game sets
2. The board will be stored in the form of array in the codes 
3. The board will be updated as the match continues and a dynamic memory storage arrangement will be applied to the board to ensure the stability of the flow of data
4. A file that stored the result of the match will be outputed and this will facilitate further comparison and analysis on performance of players
5. The codes will be divided into various section and stored seperately in different files, for instance, part determining the mark calculation and part generating the random positions of mines
