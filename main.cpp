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
void fillArray(int (&arr), int, int)


//main---------------------------------------------------------------
int main(){
  int result = 0;
  int tick = 0;
  int gameRunning = 1;
  
  //intro splash screen 
  splashScreen();
  //initialization
  
  //loop so long as the game is running
  while(gameRunning == 1){
  
  //itterate to measure the epochs of the gamestate
  tick++;
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

