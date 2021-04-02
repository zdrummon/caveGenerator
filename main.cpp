#include <iostream>
#include <iomanip>
using namespace std;

//variable declarations----------------------------------------------
const string versionInfo = "0.0.01";
//the dimensions of the arrays in total
const int maxY = 100;
const int maxX = 100;

//structure that explains 2d locationality
struct coordinate{  int x, y;  };

//arrays
int biomeArray[maxY][maxX];
int bufferArray[maxY][maxX];

int regionArray[maxY][maxX];
coordinate regionCenterArray[20];

int movementArray[maxY][maxX];
int materialArray[maxY][maxX];
int visibilityArray[maxY][maxX];
int lightingArray[maxY][maxX];
int fogOfWarArray[maxY][maxX];

int entityArray[maxY][maxX];

char graphicsArray[maxY][maxX];



//function prototyping------------------

void splashScreen();

void fillArray(int [maxY][maxX], int);
void fillArray(char [maxY][maxX], char);
void fillArray(bool [maxY][maxX], bool);

void printArray(int [maxY][maxX]);


//main---------------------------------------------------------------
int main(){
  int result = 0;
  int tick = 0;
  int gameRunning = 1;

  //intro splash screen
  splashScreen();
  //initialization

  //loop so long as the game is running
  while(gameRunning == 1) {

    fillArray(biomeArray, 1);
    printArray(biomeArray);
    //itterate to measure the epochs of the gamestate
    tick++;
    gameRunning = 0;
  }

  //post loop to exit
  return result;
}

//function definitions ------------------------------------------------

void splashScreen(){
  cout<<"@--------------------------------------------@"<<endl;
  cout<<"| Welcome to the Cave Generator Game v"<<versionInfo<<" |"<<endl;
  cout<<"@--------------------------------------------@"<<endl;
}

void fillArray(int arr[maxY][maxX], int value) {

  for(int j = 0; j < maxY; ++j)
    for(int i = 0; i < maxX; ++i)
      arr[j][i] = value;
}

void fillArray(char arr[maxY][maxX], char value) {

  for(int j = 0; j < maxY; ++j)
    for(int i = 0; i < maxX; ++i)
      arr[j][i] = value;
}

void fillArray(bool arr[maxY][maxX], bool value) {

  for(int j = 0; j < maxY; ++j)
    for(int i = 0; i < maxX; ++i)
      arr[j][i] = value;
}

void printArray(int arr[maxY][maxX]) {

  for(int j = 0; j < maxY; ++j) {
    for(int i = 0; i < maxX; ++i) {
      cout << arr[j][i] << arr[j][i];
    }
    cout << endl;
  }
}
