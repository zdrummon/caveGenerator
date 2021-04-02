#include <iostream>
#include <iomanip>
using namespace std;

//variable declarations
const string versionInfo = "0.0.01";

//function prototyping
void splashScreen();
bool game();

//main
int main(){
  int result = 0;
  int tick = 0;
  int gameRunning = 1;
  
  //intro splash screen 
  splashScreen();
  //initialization
  
  //loop
    tick++;
  while(gameRunning == 1){
  
  }
  //post loop to exit
  
  return result;
}


void splashScreen(){
  cout<<"x" * 5<<;
  cout<<"Welcome to the Cave Generator Game v"<<versionInfo<<endl;

  
}