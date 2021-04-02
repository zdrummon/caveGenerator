#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//variable declarations----------------------------------------------
const string versionInfo = "0.0.01";

//the dimensions of the arrays in total
const int maxY = 32;
const int maxX = 32;

//the constants for room properties
const int maxRoomCount = 10;
const int maxRoomSize = 10;

//seed of the random number generator
const int seedForRandom = 99;

//structure that explains 2d locationality
struct rooms{  int xloc, yloc, xsize, ysize;  };

int bufferArray[maxY][maxX];

int biomeArray[maxY][maxX];

rooms roomArray[maxRoomCount];
int regionArray[maxY][maxX];
int movementArray[maxY][maxX];

int materialArray[maxY][maxX];
int visibilityArray[maxY][maxX];

int entityArray[maxY][maxX];
bool inventoryArray[7];

int lightingArray[maxY][maxX];
int fogOfWarArray[maxY][maxX];
char graphicsArray[maxY][maxX];

//function prototyping------------------------------------------------

void splashScreen();

//fill input array with input value
void fillArray(int [maxY][maxX], int);
void fillArray(char [maxY][maxX], char);
void fillArray(bool [maxY][maxX], bool);

//fill input array with values between the input values
void randomizeArray(int  [maxY][maxX], int, int);

//printing functions
void printArray(int [maxY][maxX]);
void printArray(char [maxY][maxX]);



//main---------------------------------------------------------------
int main(){
  srand (seedForRandom);
  int result = 0;
  int tick = 0;
  int gameRunning = 1;

  //intro splash screen
  splashScreen();
  //initialization
  /*
  -fill arrays with a uniform int (use the auto for, 0 for all defaults)
  -define room count
  -difine room dimensions
  -define room locations
  -define tunnels
  -difine structured tiles (exempt from smoothing)
  -"smoothing" algorithms
  -define doorways
  -validate the map and respond
  */
  
  //
  cout<<"filling arrays"<<endl;
  randomizeArray(biomeArray, 0, 9);
  printArray(biomeArray);
  
  
  int roomCount = ( rand() % maxRoomCount ) + 1;
  cout << "There will be " << roomCount << " rooms" << endl;

  for(int i = 0; i < roomCount; i++) {
    roomArray[i].xloc = rand() % ( maxX + 1 );
    roomArray[i].yloc = rand() % ( maxY + 1 );
    roomArray[i].xsize = rand() % ( maxRoomSize );
    roomArray[i].ysize = rand() % ( maxRoomSize );

    cout << "room center No." << i <<" at ("<< roomArray[i].xloc << ", " << roomArray[i].yloc << ")"<< endl;
    cout << "  with the dimensions ("<< roomArray[i].xsize << ", " << roomArray[i].ysize << ")"<< endl;
  }
  

  
  //loop so long as the game is running
  while(gameRunning == 1) {
    printArray(graphicsArray);
    
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


//--------------------------fill array grouping
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
//randomize array functions --------------------
void randomizeArray(int arr[maxY][maxX], int minValue, int maxValue) {

  for(int j = 0; j < maxY; ++j)
    for(int i = 0; i < maxX; ++i)
      arr[j][i] = ( rand() % (maxValue - minValue + 1) ) + minValue;
}


//printing functions----------------------------
void printArray(int arr[maxY][maxX]) {

  for(int j = 0; j < maxY; ++j) {
    for(int i = 0; i < maxX; ++i) {
      cout << arr[j][i] << arr[j][i];
    }
    cout << endl;
  }
}

void printArray(char arr[maxY][maxX]) {

  for(int j = 0; j < maxY; ++j) {
    for(int i = 0; i < maxX; ++i) {
      cout << arr[j][i] << arr[j][i];
    }
    cout << endl;
  }
}

