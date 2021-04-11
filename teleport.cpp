// Group Project -- Group 13
// Description: programme that generate a teleport in the map
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void create_teleport(){

  //read the path
  ifstream path;
  path.open("path.txt");

  //count lines in the file
  string temp_line_1, temp_line_2;
  int count = 0;

  srand(time(NULL));

  while (getline(path,temp_line)){
    count = count + 1;
  }


  //random generate a number from 1 to the max number of lines
  temp_line_1 = rand() % count + 1;






}
