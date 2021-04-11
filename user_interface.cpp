#include <iostream>
#include <string>
#include "map.h"

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

int player1_starting_point;


bool player1_interface( int player1_starting_point[2], int map[][100] )
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
      return true;
      break;

    case 'E':
      if ( ( player[1].emperor_x == 0 ) && ( player[1].emperor_y == 0 ) ) {

        if ( map[player1_starting_point[1]][player1_starting_point[0]] == 1 ) {

          player[1].emperor_x = player1_starting_point[0];

          player[1].emperor_y = player1_starting_point[1];

          map[player[1].emperor_y][player[1].emperor_x] = 5;

          if ( map[0][0] == 3 )
            map[0][0] = 0;

          else if ( map[0][1] == 3 )
            map[0][1] = 0;

          else if ( map[1][0] == 3 )
            map[1][0] = 0;

          else if ( map[1][1] == 3 )
            map[1][1] = 0;

          compass();
          print_map(map);

          cout << "your chosen chess is deployed for the first time. No further moves" << endl;
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
