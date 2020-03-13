#include <iostream>
#ifndef MODES_H
#define MODES_H
//#include "Board.h"
//#include <string>

using namespace std;

class Modes {
  public:
    int countNeighbors;
    string curNeighbor;
    int mode;
    int row;
    int column;
    int similarity = 0;

    Modes(Board* myBoard, int mode);

    Board* classicBoard;
    char** copyBoard;
    char** classicBoard2;
};
#endif
