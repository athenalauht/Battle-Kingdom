#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
int main() {

  const int SIZE_X = 100;
  const int SIZE_Y = 25;

  //map of the above size
  char map[25][100];

  //initialize the map
  for (int y = 0; y < SIZE_Y; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 32;

    }

  }


  ifstream path;
  path.open("path.txt");

  //path is not created or have error
  if (path.fail()){

    return -1;

  }

  //drawing the path

  int index_x, index_y;  //storing x and y
  int temp_x, temp_y;

  while(path >> index_x){

    temp_x = index_x;

    path >> index_y;
    temp_y = index_y;

    map[temp_x][temp_y] = '.';

  }

  //border making x = 0 to 1 and x = SIZE-1 to SIZE
  //same for y

  //for upper border
  for (int y = 0; y < 2; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 47;

    }

  }

  //for left border
  for (int x = 0; x < 1 + 1; ++x){

    for (int y = 0; y < SIZE_Y; ++y){

      map[y][x] = 47;

    }

  }

  //for lower border
  for (int y = SIZE_Y - 2; y < SIZE_Y; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 47;

    }

  }

  //for right border
  for (int x = SIZE_X - 2; x < SIZE_X; ++x){

    for (int y = 0; y < SIZE_Y; ++y){

      map[y][x] = 47;

    }

  }




}
