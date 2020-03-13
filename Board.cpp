#include "Board.h"
#include "Modes.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

//DEFAULT CONSTRUCTOR
Board::Board() {
  row = 10;
  column = 10;
  popDen = .5;
  origBoard = new char* [row];
  for(int i = 0; i < row; ++i) {
    origBoard[i] = new char[column];
    for(int j = 0; j < column; ++j) {
      origBoard[i][j] = '-';
    }
  }
}

//CONSTRUCTOR FOR COPY BOARD
Board::Board(int row, int column) {
  origBoard = new char* [row];
  for(int i = 0; i < row; ++i) {
    origBoard[i] = new char[column];
    for(int j = 0; j < column; ++j) {
      origBoard[i][j] = '-';
    }
  }
}

//CREATES BOARD BY FILE OR INPUT
Board::Board(int boardType) {

  //board created from file
  if(boardType == 1) {

    string fileName;
    cout << "Enter the name of the file: " << endl;
    cin >> fileName;

    //open the file
    ifstream inFile;

    inFile.open(fileName);

    if (inFile.fail()) {
      cerr << "File was not opened properly" << endl;
      exit(1);
    }
    string line;
    while(!inFile.eof()) {
      inFile >> line;
      allFile = allFile + line;
    }
    cout << allFile << endl;
    inFile.close();


    strRow = allFile.at(0);
    strColumn = allFile.at(1);
    try {
      row = stoi(strRow);
      column = stoi(strColumn);
    }
    catch(const std::invalid_argument e) {
      cout << "Error opening file" << endl;
      exit(1);
    }
    cout << column << endl;

    origBoard = new char* [row];
    for(int i = 0; i < row; ++i) {
      origBoard[i] = new char[column];
      for(int j = 0; j < column; ++j) {
        origBoard[i][j] = '-';
      }
    }


    for(int i = 0; i < row; ++i) {
      for(int j = 0; j < column; ++j) {
        origBoard[i][j] = allFile.at((i*column) + j + 2);
      }
    }

  }


  //random board
  if(boardType == 2) {
    cout << "Enter the amount of rows for your board: " << endl;
    cin >> row;
    //check for correct input
    while(cin.fail()) {
      cout << "Enter an integer: " << endl;
      cin.clear();
      cin.ignore(256,'\n');
      cin >> row;
    }

    cout << "Enter the amount of columns for your board: " << endl;
    cin >> column;
    //check for correct input
    while(cin.fail()) {
      cout << "Enter an integer: " << endl;
      cin.clear();
      cin.ignore(256,'\n');
      cin >> column;
    }

    cout << "Enter as a decimal the percent of grids you want alive(alive represented by 'X') " << endl;
    cin >> popDen;
    //check for correct input
    while(popDen > 1) {
      cout << "Enter a decimal: " << endl;
      cin.clear();
      cin >> popDen;
    }

    origBoard = new char* [row];
    for(int i = 0; i < row; ++i) {
      origBoard[i] = new char[column];
      for(int j = 0; j < column; ++j) {
        float randNum = (float)rand() / RAND_MAX;
        if(randNum <= popDen)
          origBoard[i][j] = 'X';
        else {
          origBoard[i][j] = '-';
        }
      }
    }
  }
  cout << "Generation: 0" << endl;
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < column; ++j) {
      cout << origBoard[i][j] << " ";
    }
    cout << endl;
  }
}


//DESTRUCTOR
Board::~Board() {
  //delete rows
  for(int i = 0; i < row; ++i) {
    delete origBoard[i];
  }

  //delete columns
  delete []origBoard;
  cout << "Board was deleted" << endl;
}

//ACCESSOR
char** Board::returnBoard() {
  return origBoard;
}

//RETURNS 1 IF CELL IS ALIVE, 0 IF DEAD
int Board::getState(int inRow, int inColumn, int mode) {
  if(mode == 1) {
    //classic mode
    if(inRow == -1 || inColumn == -1 || inRow >= row || inColumn >= column)
      return 0;
    if(origBoard[inRow][inColumn] == 'X')
      return 1;
    else if(origBoard[inRow][inColumn] == '-')
      return 0;
    else {
      cout << "Array contains values besides 'X' and '-'" << endl;
      exit(1);
    }
  }

  else if(mode == 2) {
    //donut mode
    if (inRow == -1)
      inRow = row-1;
    if (inRow == column)
      inRow = 0;
    if (inColumn == -1)
      inColumn = column-1;
    if (inColumn == row)
      inColumn = 0;
    if (origBoard[inRow][inColumn] == 'X')
      return 1;
    else if (origBoard[inRow][inColumn] == '-')
      return 0;
    else
      cout << "Array contains values besides 'X' and '-'" << endl;
  }

  else if(mode == 3) {
    //mirror mode

    if(inRow == -1 && inColumn == -1) {
      if(origBoard[inRow+1][inColumn+1] == 'X')
        return 3;
      else
        return 0;
    }
    if(inRow == row+1 && inColumn == column+1) {
      if(origBoard[inRow+1][inColumn-1] == 'X')
        return 3;
      else
        return 0;
    }
    if(inRow == row+1 && inColumn == -1) {
      if(origBoard[inRow-1][inColumn+1] == 'X')
        return 3;
      else
        return 0;
    }
    if(inRow == -1 && inColumn == column+1) {
      if(origBoard[inRow+1][inColumn-1] == 'X')
        return 3;
      else
        return 0;
    }
    if (inRow == -1)
      inRow++;
    if (inColumn == -1)
      inColumn++;
    if (inColumn == column+1)
      inColumn--;
    if (inRow == row+1)
      inRow--;
    if(origBoard[inRow][inColumn] == 'X')
      return 1;
    else if(origBoard[inRow][inColumn] == '-')
      return 0;
    else
      cout << "Array contains values besides 'X' and '-'";

  }
}

//PRINT BOARD
void Board::printBoard() {
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < column; ++j) {
      cout << origBoard[i][j] << " ";
    }
    cout << endl;
  }
}

//RETURNS ROW
int Board::getRow() {
  return row;
}

//RETURNS COLUMN
int Board::getColumn() {
  return column;
}
