// Group Project -- Group 13
// Description: program to run the game

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
#include "save.h"
#include "retrieve.h"
#include "user_interface.h"
#include "battle_result.h"
#include "mystruct.h"

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
  // initialize the array to store the starting point of the two players
  int player1_starting_point[2];
  int player2_starting_point[2];

  // to set the initial coordinates of all chess to be (0, 0)
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
  player[2].assassin_y = 0

  //initialize the map

  const int SIZE_X = 100;
  const int SIZE_Y = 25;


  int map[25][100];

  for (int y = 0; y < SIZE_Y; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 0;

    }

  }

  //initialize the teleporter position
  int teleport_1[2];
  int teleport_2[2];

  //--------------------------------------------

  //display to player before game
  //
  game_title();
  game_rules();

  //--------------------------------------------

  // to retrieve previous record
  char choice;
  int count = 1;

  cout << "Do you want to retrieve previous game data? ( Y / N )" << endl;
  cin >> choice;

  while (choice != 'Y' && choice != 'N') {
    cout << "Invalid command, please try again" << endl;
    cout << "Do you want to retrieve previous game data? ( Y / N )" << endl;
    cin >> choice;
  }

  if (choice == 'Y') {

    if (!retrieve(map, teleport_1, teleport_2, player,count)) {
      cout << "Sorry, there are no saved games.\nLets start a new match!\n";
      cout << "This is the initial map setting. Player 1 will first start his/her round" << endl;
      create_path();
      initial_path(map);
      create_teleport(teleport_1, teleport_2, map);
    }

    else {
      cout << "The saved game is retrieved.\nYou can start now!" << endl;
      map[teleport_1[0]][teleport_1[1]] = 9;
      map[teleport_2[0]][teleport_2[1]] = 9;
      base_chess_retrieve(map,player);
    }

  }

  else {
    create_path();
    initial_path(map);
    create_teleport(teleport_1, teleport_2, map);
    cout << "This is the initial map setting. Player 1 will first start his/her round" << endl;

  }

  // to locate the starting point of each player
  for (int i = 0; i < 23; ++i) {
    if (map[i][2] == 1 || map[i][2] == 9) {
      player1_starting_point[0] = 2;
      player1_starting_point[1] = i;
      break;
    }
  }

  for (int i = 22; i > 1; --i) {
    if (map[i][97] == 1 || map[i][2] == 9) {
      player2_starting_point[0] = 97;
      player2_starting_point[1] = i;
      break;
    }
  }


  // to start the game
  bool termination = false;
  while (!termination) {

    if (count % 2 == 0) {
      termination = player2_interface( player2_starting_point, map, teleport_1, teleport_2);
      count += 1;
    }

    else {
      termination = player1_interface( player1_starting_point, map, teleport_1, teleport_2 );
      count += 1;
    }

  }
  store_count(count - 1);

  return 0;
}
