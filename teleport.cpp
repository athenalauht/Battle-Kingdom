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

void create_teleport( int teleport_1[2], int teleport_2[2]){

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

  path.close();


  //random generate a number from 1 to the max number of lines
  temp_line_1 = rand() % count + 1;

  temp_line_2 = rand() % count + 1;

  while (temp_line_1 == temp_line_2){

    temp_line_2 = rand() % count + 1;

  }

  int line_1, line_2;
  if (temp_line_1 < temp_line_2){
    line_1 = temp_line_1;
    line_2 = temp_line_2;
  }
  else{
    line_1 = temp_line_2;
    line_2 = temp_line_1;
  }

  int store;

  for (int i = 1; i < line_1 * 2 - 1; ++i){

    path >> store;

  }

  path >> teleport_1[0];
  path >> teleport_1[1];

  for (int i = line_1 * 2 + 1; i < line_2 * 2 - 1; ++i){

    path >> store;

  }

  path >> teleport_2[0];
  path >> teleport_2[1];

  path.open("path.txt");





}
