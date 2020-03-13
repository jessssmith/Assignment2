#include "Board.h"
#include "Modes.h"
#include <iostream>

//TAKE IN A BOARD AND CREATE COPIES, THEN CHECKS FOR NEIGHBORS USING getState()
Modes::Modes(Board* myBoard, int mode) {

  //copy of first board
  classicBoard2 = myBoard->returnBoard();

  classicBoard = new Board(myBoard->row,myBoard->column);

  for(int i = 0; i < myBoard->row; ++i) {
    for(int j = 0; j < myBoard->column; ++j) {

        countNeighbors += myBoard->getState(i-1, j-1, mode);
        countNeighbors += myBoard->getState(i-1, j, mode);
        countNeighbors += myBoard->getState(i-1, j+1, mode);
        countNeighbors += myBoard->getState(i, j-1, mode);
        countNeighbors += myBoard->getState(i, j+1, mode);
        countNeighbors += myBoard->getState(i+1, j-1, mode);
        countNeighbors += myBoard->getState(i+1, j, mode);
        countNeighbors += myBoard->getState(i+1, j+1, mode);

//updating and reading the same board
        if(countNeighbors <= 1)
          classicBoard->origBoard[i][j] = '-';
        else if(countNeighbors == 3)
          classicBoard->origBoard[i][j] = 'X';
        else if(countNeighbors >= 4)
          classicBoard->origBoard[i][j] = '-';
        else //leave cell alone
          if(classicBoard2[i][j] == 'X')
            classicBoard->origBoard[i][j] = 'X';
          else
            classicBoard->origBoard[i][j] = '-';

        countNeighbors = 0;
    }
  }

  //COMPARE THE BOARDS
  for(int i = 0; i < myBoard->row; ++i) {
    for(int j = 0; j < myBoard->column; ++j) {
      if(classicBoard2[i][j] == classicBoard->origBoard[i][j])
        similarity++;
      else
        continue;
    }
  }


  if(similarity == (myBoard->row*myBoard->column)) {
    cout << "Board is oscilating" << endl;
    exit(1);
  }
  else
    similarity = 0;

  for(int i = 0; i < myBoard->row; ++i) {
    for(int j = 0; j < myBoard->column; ++j) {
      classicBoard2[i][j] = classicBoard->origBoard[i][j];
    }
  }
}
