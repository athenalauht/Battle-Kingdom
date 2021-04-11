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
#include "user_interface.h"


#define PATH "\u2591"
#define BORDER "\u2588"
#define P1_COVERED "\u25CF"
#define P2_COVERED "\u25CB"

#define TELEPORT "\u2298"

#define EMPEROR "\u2654"
#define KNIGHT "\u2658"
#define SOLDIER "\u2659"
#define ASSASSIN "\u2657"

using namespace std;

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
  create_teleport(teleport_1, teleport_2,map);

  //--------------------------------------------

  print_map(map);

<<<<<<< HEAD
  player[1].emperor_x = 0;
  player[1].emperor_y = 0;
  player[1].knight_x = 0;
  player[1].knight_y = 0;
  player[1].soldier_x = 0;
  player[1].soldier_y = 0;
  player[1].assassin_x = 0;
  player[1].assassin_y = 0;

  player[2].emperor_x = 0;
  player[2].emperor_y = 0;
  player[2].knight_x = 0;
  player[2].knight_y = 0;
  player[2].soldier_x = 0;
  player[2].soldier_y = 0;
  player[2].assassin_x = 0;
  player[2].assassin_y = 0;

  int count = 1;
  bool termination = false;
  while (!termination) {

    if (count % 2 == 0) {
      // termination = player2_interface();
      count += 1;
    }

    else {
      termination = player1_interface();
      count += 1;
    }
  }
=======
  // player[1].emperor_x = 0;
  // player[1].emperor_y = 0;
  // player[1].knight_x = 0;
  // player[1].knight_y = 0;
  // player[1].soldier_x = 0;
  // player[1].soldier_y = 0;
  // player[1].assassin_x = 0;
  // player[1].assassin_y = 0;
  //
  // player[2].emperor_x = 0;
  // player[2].emperor_y = 0;
  // player[2].knight_x = 0;
  // player[2].knight_y = 0;
  // player[2].soldier_x = 0;
  // player[2].soldier_y = 0;
  // player[2].assassin_x = 0;
  // player[2].assassin_y = 0;
  //
  // int count = 1;
  // bool termination = false;
  // while (!termination) {
  //
  //   if (count % 2 == 0) {
  //     termination = player2_interface();
  //     count += 1;
  //   }
  //
  //   else {
  //     termination = player1_interface();
  //     count += 1;
  //   }
  // }
>>>>>>> d40c46d51cea38aa6369a1d636d3f6d1d97f31ec

}
