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
