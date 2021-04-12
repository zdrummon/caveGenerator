//code developed in 2021 by Daikon Environments

#include <iostream>
#include <vector> // need this for auto loops base data
#include <string> // need for string vectors
#include <experimental/filesystem> // gives access to file system queries
#include <fstream> // read files to input data
#include "main.h"

#include <iomanip> // not using yet but plan to

// TODO move code to header 

// standard namespaces
using std::cout; using std::cin; using std::getline;
using std::endl; using std::string; using std::vector;

// making my own namespace for file operations
namespace fs = std::experimental::filesystem;


// prototypes
vector<string> generateList();
bool userChoice(string, int);
void toggleModule(int);
void writeModConfiguration(vector<string>);






//================================================================
// it's main, man!
//================================================================
int main() {
  
  // user enters in a character corresponding to debug option
  string userInput;
  int moduleCount;

  // TODO splash screen function with version and credits of debugger
  cout << endl << "Welcome to the caveGenerator debug system. \nSelect an option below: " << endl << endl;

  // main debug loop
  do {
    moduleCount = 0;

    // generate list of options based on dat files in the filesystem
    for (const auto & parsedEntry : generateList()) {
      moduleCount++;
      cout << " [" << moduleCount << "] " << parsedEntry << endl;
    }

    cout << endl << "You may enter in a number to enable or disable a module.\nYou may press enter to continue or type Q to leave.\nType S to scan and update the system again." << endl << endl;

    getline(cin, userInput);

  } while (userChoice(userInput, moduleCount));


  return 0;  
}






//================================================================
// generate and format the debug options from modID files
//================================================================
vector<string> generateList() {
  
  
  // dynamic string vector to hold list entries
  vector<string> moduleList(0);

  // iterate through current file path for modules
  string path = fs::current_path();
  string modFolderPath = path + "/modules";
  
  string datChunk;
  std::ifstream inputFile;


  for (const auto & file : fs::directory_iterator(modFolderPath)) {

    //parse file path and open modID.dat
    string modPath = file.path();
    inputFile.open(modPath + "/modID.dat");

    //parsed file goes in this ordered list
    bool debugEnabled = true;

    string parsedModule;
    
    // parse file into list entry
    while (getline(inputFile, datChunk)) {

      if (datChunk == "debugEnabled=true") {
        parsedModule += "[enabled]  " ;

      } else if (datChunk == "debugEnabled=false") {
        parsedModule += "[disabled] ";

      } else if (datChunk.substr(0, datChunk.find("=", 0)) == "version") {
        parsedModule += "version " + datChunk.substr(datChunk.find("=", 0) + 1, datChunk.length()) + ": ";

      } else {
        parsedModule += datChunk.substr(datChunk.find("=", 0) + 1, datChunk.length()) + " ";
      }
    }

    moduleList.push_back(parsedModule);
    inputFile.close();
  }

  // write modlist to file
  writeModConfiguration(moduleList);

  // return a string vector
  return moduleList;
}






//================================================================
// write modlist.dat file
//================================================================
void writeModConfiguration(vector<string> moduleList) {
  
  // define path and filename
  string path = fs::current_path();
  string fileName = path + "/modList.dat";

  // open modlist.dat
  std::ofstream outputFile;
  outputFile.open(fileName.c_str());
  
  // write scanned mods into modlist
  for (const auto & parsedMod : moduleList) {
    outputFile << parsedMod << endl;
  }

  outputFile.close();
}






//================================================================
// loop control for debugger and open dependent module
//================================================================
bool userChoice(string userInput, int moduleRange) {
  bool userContinue = true;
  int userModInt = 0;

  if (isdigit(userInput[0])) {
    userModInt = stoi(userInput);
  }

  // quit here
  if (userInput == "q" || userInput == "Q") {
    cout << "Debugger closing." << endl << endl;

    userContinue = false;


  // restart debugger here
  } else if (userInput == "s" || userInput == "S") {
    cout << "Reloading..." << endl << endl << endl;


  // call module loader
  } else if (userModInt > 0 && userModInt <= moduleRange) {

    cout << endl << "you toggled module " << userModInt << endl;

    toggleModule(userModInt);


  // run program
  } else if (userInput == "") {
    modRun();

    cout << "Debugger closing." << endl << endl;
    userContinue = false;


  // input validation here
  } else {
    cout << "Bad input. Try again?" << endl << endl;
  
  }

  //boolean main loop flag  
  return userContinue;
}






//================================================================
// module toggler
//================================================================
void toggleModule(int moduleID) {
  int moduleCounter = 1;

  string path = fs::current_path();  
  string modFolderPath = path + "/modules";
  string fileName;
  string fileLine;
  string modName;
  vector<string> fileUpdater;

  for (const auto & file : fs::directory_iterator(modFolderPath)) {

    if (moduleCounter == moduleID) {

        // define path and filename
        modFolderPath = file.path();
        fileName = modFolderPath + "/modID.dat";


        std::ifstream inputFile;
        inputFile.open(fileName);
        while (getline(inputFile, fileLine)) {

          if (fileLine == "debugEnabled=true") {
            cout << "Disabling mod: ";
            fileUpdater.push_back("debugEnabled=false");

          } else if (fileLine == "debugEnabled=false") {
            cout << "Enabling mod: ";
            fileUpdater.push_back("debugEnabled=true");

          } else {

            if(fileLine.substr(0, fileLine.find("=", 0)) == "modID") {
              modName = fileLine.substr(fileLine.find("=", 0) + 1, fileLine.length());
              cout << modName << endl << endl;
            }

            fileUpdater.push_back(fileLine);
          }
        }

        inputFile.close();

        // open modlist.dat
        std::ofstream outputFile;
        outputFile.open(fileName.c_str());
        
        // write scanned mods into modlist
        for (const auto & fileLine : fileUpdater) {
          outputFile << fileLine << endl;
        }

        outputFile.close();
    }

    moduleCounter++;
  }
}