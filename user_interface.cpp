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



bool player1_interface()
{
  string chosen_chess;

  cout << "which chess would you like to move?" << endl;
  cout << "Emperor / Knight / Soldier / Assassin" << endl;
  cout << "Type (E / K / S / A) for the chess to move, T to save and terminate the game" << endl;
  cin >> chosen_chess;

  if (chosen_chess == "T") {
    cout << "The game is ended" << endl;
    return true;
  }

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
