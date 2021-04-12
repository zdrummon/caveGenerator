// includes
#include "modRun.h"

//filler

// main program module
void modRun() {
  
  splashScreen("0.0.03");
  
  //TODO validate seed input to functions
  modifySeed();

  //pad next screen until screen clear
  cout << endl << endl;

  //TODO build pointer array
  int *movementArray = nullptr;
  movementArray = new int;
  
  //basic array output test, will modularize later

  //TODO move to 3 functions
  /*simple cellular automata smoothing
  for (int passes = 0; passes < 2; passes++) {

    cout << "smoothing pass " << passes << endl;

    for (int i = 1; i < maxX - 1; i++) {
      for (int j = 1; j < maxY - 1; j++) {
        int neighborTotal = 
          gameBoard[j - 1][i - 1] + 
          gameBoard[j - 1][i] +
          gameBoard[j - 1][i + 1] +
          gameBoard[j][i - 1] +
          gameBoard[j][i] +
          gameBoard[j][i + 1] +
          gameBoard[j + 1][i - 1] +
          gameBoard[j + 1][i] +
          gameBoard[j + 1][i + 1];

          

        if (neighborTotal > 20 && gameBoard[j][i] < 4) {
          gameBoard[j][i]++;

        } else if (neighborTotal < 20 && gameBoard[j][i] > 0) {
          gameBoard[j][i]--;
        }

        cout << grayScale[gameBoard[j][i]];
        cout << grayScale[gameBoard[j][i]];
        //cout << neighborTotal;
      }
      cout << endl;
    }

    cout << endl << endl;
  }
  */


  cout << endl;

}

void splashScreen(string vers) {
  std::cout << "Welcome to the Cave Generator v." << vers << endl;
}

void modifySeed() {
  int seed;
  cout << "enter in a number for the seed" << endl << endl;
  cin >> seed;
  srand(seed);
}


void printScreen() {
  
}
void fillWithRandom(int *movementArr) {

}