#include <iostream>
#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board {
  public:
    int boardType;
    int row;
    int column;
    float popDen;
    float numX;
    string fileName;
    string line;
    string allFile;
    string strRow;
    string strColumn;


    Board();
    Board(int boardMode);
    Board(int row, int column);
    ~Board();
    char** returnBoard();
    int getState(int row, int column, int mode);
    int getRow();
    int getColumn();
    void printBoard();

  //  static void printBoard();

    //some kind of print board method
    char** origBoard;
  //  Board* copyBoard;

};
#endif
