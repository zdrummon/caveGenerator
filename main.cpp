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
  
  string datChunk;
  std::ifstream inputFile;
  int moduleCount = 0;

  for (const auto & file : fs::directory_iterator(path)) {

    //parse file path and open modID.dat
    string modPath = file.path();
    inputFile.open(modPath + "/modID.dat");

    //parsed file goes in this ordered list
    bool debugEnabled = true;

    string parsedModule;
    
    // parse file into list entry
    while (getline(inputFile, datChunk) && debugEnabled) {

      if (datChunk == "debugEnabled=true") {
        debugEnabled = true;

      } else if (datChunk == "debugEnabled=false") {
        debugEnabled = false;

      } else if (datChunk.substr(0, datChunk.find("=", 0)) == "version") {
        parsedModule += "version " + datChunk.substr(datChunk.find("=", 0) + 1, datChunk.length()) + ": ";

      } else {
        parsedModule += datChunk.substr(datChunk.find("=", 0) + 1, datChunk.length()) + " ";
      }
    }

    parsedModule = "[" + std::to_string(moduleCount) + "] " + parsedModule;

    moduleList.push_back(parsedModule);
    inputFile.close();
    moduleCount++;
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


    // NEXT STEP OF PROGRAM HERE 

    userContinue = false;


  //input validation here
  } else {
    cout << "Bad input. Try again?" << endl << endl;


  }

  //boolean main loop flag  
  return userContinue;
}