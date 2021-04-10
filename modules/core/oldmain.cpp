#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

//constants declarations----------------------------------------------
const string versionInfo = "0.0.02";

//the dimensions of the arrays in total
const int maxY = 32;
const int maxX = 32;

//the constants for room properties
const int maxRoomCount = 10;
const int maxRoomSize = 10;

//seed of the random number generator
const int seedForRandom = 99;

//string used for lighting and screen printing
const string grayScale[] = { "  ","░░","▒▒","▓▓","██"};

//structure that explains 2d locationality
struct rooms {  
  int xloc, yloc, xsize, ysize;
};

//structure that holds the values found from locations in check neighbors
struct neighborResults{
  int q, c, n, ne, e, se, s, sw, w, nw;
};

//arrays-------------------------------------------------------------
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

//check neighbor values
neighborResults checkNeighbor(int [maxY][maxX], int, int);

//smooths arrays
void smoothPerlin(int [maxY][maxX]);


//printing functions
void printArray(int [maxY][maxX]);
void printArray(char [maxY][maxX]);

void printArraySpecial(int [maxY][maxX]);




//main-------------------------------------------------------------------------------------------
int oldmain() {
  srand (seedForRandom);
  int result = 0;
  int tick = 0;
  int gameRunning = 1;

  //intro splash screen
  splashScreen();
  //initialization

  //fill the biome with random numbers
  cout<<"filling arrays"<<endl;
  randomizeArray(biomeArray, 1, 3);
  printArraySpecial(biomeArray);
  cout<<endl<<endl<<endl<<endl<<endl;

  //smooth biome array
  smoothPerlin(biomeArray);
  printArraySpecial(biomeArray);

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

//function definitions -----------------------------------------------------------------------------
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
//copy one array to another
void arrayCopyTo(int arr[maxY][maxX], int arrTwo[maxY][maxX]){
  for(int j = 0; j < maxY; j++){
    for(int i = 0; i < maxX; i++){ 
      arrTwo[j][i] = arr[j][i]; 
    }
  }
}



//randomize array functions --------------------------------------------------------------------------------------
void randomizeArray(int arr[maxY][maxX], int minValue, int maxValue) {

  for(int j = 0; j < maxY; ++j)
    for(int i = 0; i < maxX; ++i)
      arr[j][i] = ( rand() % (maxValue - minValue + 1) ) + minValue;
}

//checkNeighbor functions------------------------------------------------------------------------------------------
neighborResults checkNeighbor(int arr[maxY][maxX], int xloc, int yloc){
  neighborResults results;
  int neighborCount = 1;
  results.c = arr[yloc][xloc];
  
  yloc > 0 ? results.n = arr[yloc - 1][xloc], neighborCount++: results.n = 0;

  (( xloc < maxX - 1 ) && ( yloc > 0 )) ? results.ne = arr[yloc - 1][xloc + 1], neighborCount++: results.ne = 0;

  xloc < maxX - 1 ? results.e = arr[yloc][xloc + 1], neighborCount++ : results.e = 0;

  (( xloc < maxX - 1 ) && ( yloc < maxY - 1 )) ? results.se = arr[yloc + 1][xloc + 1], neighborCount++ : results.se = 0;

  yloc < maxY - 1 ? results.s = arr[yloc + 1][xloc], neighborCount++ : results.s = 0;

  (( xloc > 0 ) && ( yloc < maxY - 1 )) ? results.sw = arr[yloc + 1][xloc - 1], neighborCount++ : results.sw = 0;

  xloc > 0 ? results.w = arr[yloc][xloc - 1], neighborCount++ : results.w = 0;

  (( xloc > 0 ) && ( yloc > 0 )) ? results.nw = arr[yloc - 1][xloc - 1], neighborCount++ : results.nw = 0;

  
  results.q = neighborCount;
  return results;
}


//smoothing algorithms
void smoothPerlin(int arr[maxY][maxX]){
  neighborResults nCursor;
  int accumulator;
  for(int j = 0; j < maxY; j++){
    accumulator = 0;
    for(int i = 0; i < maxX; i++){
      nCursor = checkNeighbor(arr,i,j); 
      accumulator = (nCursor.c + nCursor.n +
                    nCursor.ne + nCursor.e +
                    nCursor.se + nCursor.s +
                    nCursor.sw + nCursor.w +
                    nCursor.nw) / nCursor.q;
      bufferArray[j][i] = accumulator; 
    }
  }
  arrayCopyTo(bufferArray,arr);
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

//print special like and such

void printArraySpecial(int arr[maxY][maxX]) {

  for(int j = 0; j < maxY; ++j) {
    for(int i = 0; i < maxX; ++i) {
      cout << grayScale[arr[j][i]] << grayScale[arr[j][i]];
    }
    cout << endl;
  }
}


