//code developed in 2021 by Zac Drummond and Trevor Haggerty

#include <iostream>
#include <vector> // need this for auto loops base data
#include <string> // need for string vectors
#include <experimental/filesystem> // gives access to file system queries
#include <fstream> // read files to input data

#include <iomanip> // not using yet but plan to


// standard namespaces
using std::cout; using std::cin;
using std::endl; using std::string; using std::vector;

// making my own namespace for file operations
namespace fs = std::experimental::filesystem;


// prototypes
vector<string> listEntry();
bool userChoice(char);






//================================================================
// it's main, man!
//================================================================
int main() {

  // user enters in a character corresponding to debug option
  char userInput;
  
  // main debug loop
  do {
    cout << endl << "Welcome to the caveGenerator debug system. \nSelect a load option below: " << endl << endl;

    // generate list of options based on dat files in the filesystem
    for (const auto & parsedEntry : listEntry()) {
      cout << parsedEntry << endl;
    }

    cout << endl << "You may also press Q to leave, or S to scan the system again." << endl << endl;

    cin >> userInput;

  } while (userChoice(userInput));


  return 0;  
}






//================================================================
// generate and format one of the debug options
//================================================================
vector<string> listEntry() {
  
  
  // dynamic string vector to hold list entries
  vector<string> moduleList(0);

  // iterate through current file path for modules
  string path = fs::current_path();
  path = path + "/modules";
  
  string fileLine;
  std::ifstream inputFile;

  for (const auto & file : fs::directory_iterator(path)) {

    //parse file path and open modID.dat
    string modPath = file.path();
    inputFile.open(modPath + "/modID.dat");
    string moduleDetails;

    // parse file into list entry
    while (inputFile >> fileLine) {

        //iomanip string operations to parse strings in the file, needs work
        moduleDetails = moduleDetails + " " + fileLine;
    }

    moduleList.push_back(moduleDetails);
    inputFile.close();
  }


  // return a string vector
  return moduleList;
}






//================================================================
// loop control for debugger and open dependent module
//================================================================
bool userChoice(char userInput) {
  bool userContinue = true;


  // quit here
  if (userInput == 'q' || userInput == 'Q') {
    cout << "Debugger closing." << endl << endl;

    userContinue = false;


  // restart debugger here
  } else if (userInput == 's' || userInput == 'S') {
    cout << "Reloading..." << endl << endl << endl;


  //__________________________________________________load program here___________
  } else if (userInput == '1') {

    
    // todo

    userContinue = false;


  //input validation here
  } else {
    cout << "Bad input. Try again?" << endl << endl;


  }

  //boolean main loop flag  
  return userContinue;
}