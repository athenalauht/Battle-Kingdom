// Group Project -- Group 13
// Description: generate the inital path (including chess)
//              read path.txt
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



using namespace std;

void initial_path(map[25][100]){

  const int SIZE_X = 100;
  const int SIZE_Y = 25;


  //read file
  ifstream path;
  path.open("path.txt");


  //drawing the path

  int index_x, index_y;  //storing x and y
  int temp_x, temp_y;

  while(path >> index_y){

    temp_y = index_y;

    path >> index_x;
    temp_x = index_x;

    map[temp_y][temp_x] = 1;

  }


  //border making x = 0 to 1 and x = SIZE-1 to SIZE
  //same for y

  //for upper border

  for (int y = 0; y < 2; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 2;

    }

  }


  //for left border

  for (int x = 0; x < 1 + 1; ++x){

    for (int y = 0; y < SIZE_Y; ++y){

      map[y][x] = 2;

    }

  }


  //for lower border

  for (int y = SIZE_Y - 2; y < SIZE_Y; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 2;

    }

  }


  //for right border

  for (int x = SIZE_X - 2; x < SIZE_X; ++x){

    for (int y = 0; y < SIZE_Y; ++y){

      map[y][x] = 2;

    }

  }

  //put chess into place (inital state)

  //player 1

  map[0][0] = 3
  map[0][1] = 3
  map[1][0] = 3
  map[1][1] = 3

  //player 2

  map[SIZE_Y - 2][SIZE_X - 2] = 4
  map[SIZE_Y - 2][SIZE_X - 1] = 4
  map[SIZE_Y - 1][SIZE_X - 2] = 4
  map[SIZE_Y - 1][SIZE_X - 1] = 4


}
