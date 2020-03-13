#include <iostream>
#include <thread>
#include <chrono>
#include "Board.h"
#include "Modes.h"

using namespace std;

int main(int argc, char** argv) {

  int input;
  int mode;
  int choice;
  Board* myBoard;
  Modes* modes;


  cout <<"Would you like to generate the grid using a \n1.File\n2.Input" << endl;
  cin >> input;
  //make sure number was inputed
  while(cin.fail()) {
    cout << "Please enter 1 or 2: " << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> input;
  }

  cout << "SELECT MODE: \n1.Classic\n2.Donut\n3.Mirror" << endl;
  cin >> mode;
  //check for correct input
  while(cin.fail()) {
    cout << "Please enter 1, 2, or 3: " << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> mode;
  }

  cout << "Would you like \n1.Press 'Enter' between generations\n2.A brief pause\n3.File output" << endl;
  cin >> choice;
  while(cin.fail()) {
    cout << "Please enter 1, 2, or 3: " << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> choice;
  }

  myBoard = new Board(input);
  //ENTER
  if(choice == 1) {
    int generation = 1;
    while(generation < 100000) {
      modes = new Modes(myBoard, mode);
      cout << "Press 'Enter' to continue...(press 'e' to exit)" << endl;
      cin.get();
    //  if(e == "e")
      //  exit(1);
      cout << "\nGeneration: " << generation << endl;
      myBoard->printBoard(); //this is returning the next generation
      generation++;
    }
    myBoard->~Board();
    cout << "Press 'Enter' to exit" << endl;
    cin.get();
  }

//PAUSE
  else if(choice == 2) {
    int generation = 1;
    while(generation < 100000) {
      modes = new Modes(myBoard, mode);
      cout << "\nGeneration: " << generation << endl;
      myBoard->printBoard(); //this is returning the next generation
      generation++;
      std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    myBoard->~Board();
    cout << "Press 'Enter' to exit" << endl;
    cin.get();
  }
  //FILE
  if(choice == 3) {
    //ofstream outFile;
    string fileName;
    cout << "Enter the name of the file you want to output to: " << endl;
    cin >> fileName;

    cout << "Does not actually write to file :(" << endl;
  //  outFile.open(fileName);

    int generation = 1;
    while(generation < 100000) {
      modes = new Modes(myBoard, mode);
      //outFile << "\nGeneration: " << generation << endl;
      //outFile << myBoard->printBoard() << endl; //this is returning the next generation
      generation++;
    }
  //  outFile.close();
  myBoard->~Board();
  cout << "Press 'Enter' to exit" << endl;
  cin.get();
  }
}
