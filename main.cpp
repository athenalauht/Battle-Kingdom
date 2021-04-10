// Group Project -- Group 13
// Description:
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "map.h"

using namespace std;


int main()
{
  //initialize the map

    int map[25][100];

    for (int y = 0; y < SIZE_Y; ++y){

      for (int x = 0; x < SIZE_X; ++x){

        map[y][x] = 0;

      }

    }

  //--------------------------------------------


  //display to player before game

  game_title();
  game_rules();
  compass();

  //--------------------------------------------

  dead_message(1);

  create_path();
}
