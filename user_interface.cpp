// Group Project -- Group 13
// Description: programme that control all user input and output

#include <iostream>
#include <string>
#include "display.h"
#include "map.h"
#include "save.h"
#include "battle_result.h"

#define PATH "\u2591"
#define BORDER "\u2588"
#define P1_COVERED "\u25CF"
#define P2_COVERED "\u25CB"

#define EMPEROR "\u2654"
#define KNIGHT "\u2658"
#define SOLDIER "\u2659"
#define ASSASSIN "\u2657"

using namespace std;
struct profile
{
  int emperor_x;
  int emperor_y;
  int knight_x;
  int knight_y;
  int soldier_x;
  int soldier_y;
  int assassin_x;
  int assassin_y;
};

profile player[3];

void cancel_base_chess()
{
  if ( map[0][0] == 3 )
    map[0][0] = 0;

  else if ( map[0][1] == 3 )
    map[0][1] = 0;

  else if ( map[1][0] == 3 )
    map[1][0] = 0;

  else if ( map[1][1] == 3 )
    map[1][1] = 0;
}

void check_attack( int map[][100], int a, int b)
{
  // check for possible horizontal left attack

  for ( int i = map[player[1].emperor_x]; i >= map[player[1].emperor_x] - 5; --i ) {

    if ( a <= map[player[1].emperor_y][i] <= b ) {

      for ( int j = map[player[1].emperor_x] - 1; j >= i + 1 ) {

        if ( map[player[1].emperor_y][j] != 1 && map[player[1].emperor_y][j] != 9 ) {

          goto check_fin_1;
        }
      }
      int attack = 5
    }
  }

  check_fin_1:

  // check for possible vertical attack
}

bool player1_interface( int player1_starting_point[2], int map[][100], int teleport_1[2], int teleport_2[2] )
{
  char chosen_chess;

  compass();
  print_map(map);

  cout << "which chess would you like to move?" << endl;
  cout << "Emperor / Knight / Soldier / Assassin" << endl;
  cout << "Type (E / K / S / A) to move, T to save and terminate the game" << endl;
  cout << "\n" << endl;
  cin >> chosen_chess;

  switch (chosen_chess) {

    case 'T':
      cout << "The game is ended" << endl;
      // store_profile(player);
      return true;
      break;

    case 'E':
      if ( ( player[1].emperor_x == 0 ) && ( player[1].emperor_y == 0 ) ) {

        if ( map[player1_starting_point[1]][player1_starting_point[0]] == 1 ) {

          player[1].emperor_x = player1_starting_point[0];

          player[1].emperor_y = player1_starting_point[1];

          map[player[1].emperor_y][player[1].emperor_x] = 5;


          cancel_base_chess();
          compass();
          print_map(map);

          cout << "Your chosen chess is deployed for the first time. No further moves" << endl;


          ////////attack

          cout << "your chess identity will be hidden now" << endl;
          cout << endl;

          map[player[1].emperor_y][player[1].emperor_x] = 3;

        }

        else if ( map[player1_starting_point[1]][player1_starting_point[0]] == 9 ) {

          if ( ( player1_starting_point[1] == teleport_1[0] ) && ( player1_starting_point[0] == teleport_1[1] ) ) {

            player[1].emperor_x = teleport_2[1];

            player[1].emperor_y = teleport_2[0];

            map[player[1].emperor_y][player[1].emperor_x] = 5;

          }

          else {

            player[1].emperor_x = teleport_1[1];

            player[1].emperor_y = teleport_1[0];

            map[player[1].emperor_y][player[1].emperor_x] = 5;

          }

          cancel_base_chess();
          compass();
          print_map(map);

          cout << "Your chosen chess is deployed for the first time. No further moves." << endl;
          cout << "The starting point of your side contains a teleporter, your chosen chess is being teleported to the other side" << endl;

          // check for possible horizontal attack
          // check for possible vertical attack

          cout << "your chess identity will be hidden now" << endl;
          cout << endl;

          map[player[1].emperor_y][player[1].emperor_x] = 3;
        }

        else {
          cout << "The starting point is occupied, please choose another move" << endl;
        }

      }






    case 'K':
      break;

    case 'S':
      break;

    case 'A':
      break;

  }

  char response;
  cout << "Player 1, are you ready?" << endl;
  cout << "Press Y to pass the control to player 2" << endl;
  cin >> response;

  return false;
}

// bool player2_interface()
// {
//
// }

// int main()
// {
//   void player1_interface();
// }
