#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

// namespaces
using std::cout; using std::cin;
using std::string; using std::vector; using std::endl;

// variables
const string versionInfo = "0.0.03";
const int maxX = 16;
const int maxY = 16;
const int maxRoomCount = 10;
const int maxRoomSize = 10;
const string grayScale[] = {" ","░","▒","▓","█"};

// prototypes
void splashScreen(string);
void modifySeed();
void printScreen();
void fillWithEmpty(int *targetArray);
void fillWithRandom(int *targetArray);

