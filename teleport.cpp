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

void create_teleport( int teleport_1[2], int teleport_2[2], int map[][100]){

  // //read the path
  // ifstream path;
  // path.open("path.txt");
  //
  // //count lines in the file
  // int temp_line_1, temp_line_2;
  // string temp_line;
  // int count = 0;
  //
  // srand(time(NULL));
  //
  // while (getline(path,temp_line)){
  //   count = count + 1;
  // }
  //
  // path.close();
  //
  //
  // //random generate a number from 1 to the max number of lines
  // temp_line_1 = rand() % count + 1;
  //
  // temp_line_2 = rand() % count + 1;
  //
  // while (temp_line_1 == temp_line_2){
  //
  //   temp_line_2 = rand() % count + 1;
  //
  // }
  //
  // int line_1, line_2;
  // if (temp_line_1 < temp_line_2){
  //   line_1 = temp_line_1;
  //   line_2 = temp_line_2;
  // }
  // else{
  //   line_1 = temp_line_2;
  //   line_2 = temp_line_1;
  // }
  //
  //
  // path.open("path.txt");
  //
  // int store;
  //
  // for (int i = 1; i < line_1 * 2 - 1; ++i){
  //
  //   path >> store;
  //
  // }
  //
  // path >> teleport_1[0];
  // path >> teleport_1[1];
  //
  // for (int i = line_1 * 2 + 1; i < line_2 * 2 - 1; ++i){
  //
  //   path >> store;
  //
  // }
  //
  // path >> teleport_2[0];
  // path >> teleport_2[1];
  //
  // path.close();
  //
  const int SIZE_X = 100;
  const int SIZE_Y = 25;

  srand(time(NULL));

  int rand_x_1, rand_y_1, rand_x_2, rand_y_2;

  rand_x_1 = rand() % SIZE_X;
  rand_y_1 = rand() % SIZE_Y;

  while (map[rand_y_1][rand_x_1] != 1){
    rand_x_1 = rand() % SIZE_X;
    rand_y_1 = rand() % SIZE_Y;
  }

  teleport_1[0] = rand_y_1;
  teleport_1[1] = rand_x_1;

  rand_x_2 = rand() % SIZE_X;
  rand_y_2 = rand() % SIZE_Y;

  while ((map[rand_y_2][rand_x_2] != 1) || (rand_y_1 == rand_y_2) || (rand_x_2 == rand_x_1)){

    rand_x_2 = rand() % SIZE_X;
    rand_y_2 = rand() % SIZE_Y;

  }

  teleport_2[0] = rand_y_2;
  teleport_2[1] = rand_x_2;


  map[teleport_1[0]][teleport_1[1]] = 9;
  map[teleport_2[0]][teleport_2[1]] = 9;


}
