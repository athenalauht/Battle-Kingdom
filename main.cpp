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
#include "teleport.h"
// #include "user_interface.h"


#define PATH "\u2591"
#define BORDER "\u2588"
#define P1_COVERED "\u25CF"
#define P2_COVERED "\u25CB"

#define EMPEROR "\u2654"
#define KNIGHT "\u2658"
#define SOLDIER "\u2659"
#define ASSASSIN "\u2657"

using namespace std;

bool termination = false;

int main()
{
  //initialize the map

  const int SIZE_X = 100;
  const int SIZE_Y = 25;


    int map[25][100];

    for (int y = 0; y < SIZE_Y; ++y){

      for (int x = 0; x < SIZE_X; ++x){

        map[y][x] = 0;

      }

    }

  //initialize the teleport
  int teleport_1[2];
  int teleport_2[2];

  //--------------------------------------------

  //display to player before game
  //
  // game_title();
  // game_rules();

  //--------------------------------------------

  // dead_message(1);

  //--------------------------------------------

  create_path();
  initial_path(map);
  create_teleport(teleport_1, teleport_2);

  //--------------------------------------------

  print_map(map);

  cout << teleport_1[0]<<endl;
  cout << teleport_1[1]<<endl;
  cout << teleport_2[0]<<endl;
  cout << teleport_2[1]<<endl;

}
