#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
int main() {

  const int SIZE_X = 99;
  const int SIZE_Y = 24;

  //map of the above size
  char map[SIZE_Y][SIZE_X];

  //initialize the map
  for (int y = 0; y < SIZE_Y + 1; ++y){

    for (int x = 0; x < SIZE_X + 1; ++x){

      map[y][x] = "a";

    }

  }
  //
  //
  // ifstream path;
  // path.open("path.txt");
  //
  // //path is not created or have error
  // if (path.fail()){
  //
  //   return -1;
  //
  // }
  //
  // //drawing the path
  //
  // int index_x, index_y;  //storing x and y
  // int temp_x, temp_y;
  //
  // while(path >> index_x){
  //
  //   temp_x = index_x;
  //
  //   path >> index_y;
  //   temp_y = index_y;
  //
  //   map[temp_x][temp_y] = 177;
  //
  // }
  //
  // //border making x = 0 to 1 and x = SIZE-1 to SIZE
  // //same for y
  //
  // //for upper border
  // for (int y = 0; y < 1 + 1; ++y){
  //
  //   for (int x = 0; x < SIZE_X + 1; ++x){
  //
  //     map[y][x] = 219;
  //
  //   }
  //
  // }
  //
  // //for left border
  // for (int x = 0; x < 1 + 1; ++x){
  //
  //   for (int y = 0; y < SIZE_Y + 1; ++y){
  //
  //     map[y][x] = 219;
  //
  //   }
  //
  // }
  //
  // //for lower border
  // for (int y = SIZE_Y - 1; y < SIZE_Y + 1; ++y){
  //
  //   for (int x = 0; x < SIZE_X + 1; ++x){
  //
  //     map[y][x] = 219;
  //
  //   }
  //
  // }
  //
  // //for right border
  // for (int x = SIZE_Y - 1; x < SIZE_Y + 1; ++x){
  //
  //   for (int y = 0; y < SIZE_Y + 1; ++y){
  //
  //     map[y][x] = 219;
  //
  //   }
  //
  // }
  //
  //print map
  for (int y = 0; y < SIZE_Y + 1; ++y){

    for (int x = 0; x < SIZE_X + 1; ++x){

      cout << map[y][x];

    }

    cout << '\n';

  }




}
