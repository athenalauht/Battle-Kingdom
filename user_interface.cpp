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

void cancel_base_chess(int player, int map[][100])
{
  switch (player) {

    case 1:
      if ( map[0][0] == 3 )
        map[0][0] = 0;

      else if ( map[0][1] == 3 )
        map[0][1] = 0;

      else if ( map[1][0] == 3 )
        map[1][0] = 0;

      else if ( map[1][1] == 3 )
        map[1][1] = 0;
      break;

    case 2:
      if ( map[23][98] == 4 )
        map[23][98] = 0;

      else if ( map[23][99] == 4 )
        map[23][99] = 0;

      else if ( map[24][98] == 4 )
        map[24][98] = 0;

      else if ( map[24][99] == 0 )
        map[24][99] = 0;

  }

}

int check_identity ( int y, int x )
{
  if ( y == player[1].emperor_y && x == player[1].emperor_x )
    return 5;

  else if ( y == player[1].knight_y && x == player[1].knight_x )
    return 6;

  else if ( y == player[1].soldier_y && x == player[1].soldier_x )
    return 7;

  else if ( y == player[1].assassin_y && x == player[1].assassin_x )
    return 8;

  else if ( y == player[2].emperor_y && x == player[2].emperor_x )
    return 10;

  else if ( y == player[2].knight_y && x == player[2].knight_x )
    return 11;

  else if ( y == player[2].soldier_y && x == player[2].soldier_x )
    return 12;

  else if ( y == player[2].assassin_y && x == player[2].assassin_x )
    return 13;

  return 0;
}

void death ( int loser )
{
  if ( loser == 5 ) {
    player[1].emperor_y = -1;
    player[1].emperor_x = -1;
  }
  else if ( loser == 6 ) {
    player[1].knight_y = -1;
    player[1].knight_x = -1;
  }
  else if ( loser == 7 ) {
    player[1].soldier_y = -1;
    player[1].soldier_x = -1;
  }
  else if ( loser == 8 ) {
    player[1].assassin_y = -1;
    player[1].assassin_x = -1;
  }
  else if ( loser == 10 ) {
    player[2].emperor_y = -1;
    player[1].emperor_x = -1;
  }
  else if ( loser == 11 ) {
    player[2].knight_y = -1;
    player[2].knight_x = -1;
  }
  else if ( loser == 12 ) {
    player[2].soldier_y = -1;
    player[2].soldier_x = -1;
  }
  else if ( loser == 13 ) {
    player[2].assassin_y = -1;
    player[2].assassin_x = -1;
  }
}

bool check_teleporter ( int y, int x, int teleport_1[2], int teleport_2[2] )
{
  if ( y == teleport_1[0] && x == teleport_1[1] )
    return true;

  else if ( y == teleport_2[0] && x == teleport_2[1] )
    return true;

  else
    return false;
}

void attack( int map[][100], int attacker, int teleport_1[2], int teleport_2[2], int O_COVERED, char attack_option, int y, int x )
{
  int defenser;
  int winner;
  switch (attack_option) {
    case 'N':
      for (int i = 1; i <= 5; ++i) {

        if ( map[y - i][x] == O_COVERED ) {

          defenser = check_identity(y - i, x);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( y - i, x , teleport_1, teleport_2 ) ) {
              map[y - i][x] = 9;
            }
            else {
              map[y - i][x] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( y, x, teleport_1, teleport_2 ) ) {
              map[y][x] = 9;
            }
            else {
              map[y][x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          goto leave;
        }
      }
      break;

    case 'E':
      for (int i = 1; i <= 5; ++i) {

        if ( map[y][x + i] == O_COVERED ) {

          defenser = check_identity(y, x + i);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( y, x + i, teleport_1, teleport_2 ) ) {
              map[y][x + i] = 9;
            }
            else {
              map[y][x + i] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( y, x, teleport_1, teleport_2 ) ) {
              map[y][x] = 9;
            }
            else {
              map[y][x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          goto leave;
        }
      }
      break;

    case 'S':
      for (int i = 1; i <= 5; ++i) {

        if ( map[y + i][x] == O_COVERED ) {

          defenser = check_identity(y + i, x);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( y + i, x , teleport_1, teleport_2 ) ) {
              map[y + i][x] = 9;
            }
            else {
              map[y + i][x] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( y, x, teleport_1, teleport_2 ) ) {
              map[y][x] = 9;
            }
            else {
              map[y][x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          goto leave;
        }
      }
      break;

    case 'W':
      for (int i = 1; i <= 5; ++i) {

        if ( map[y][x - i] == O_COVERED ) {

          defenser = check_identity(y, x - i);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( y, x - i, teleport_1, teleport_2 ) ) {
              map[y][x - i] = 9;
            }
            else {
              map[y][x - i] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( y, x, teleport_1, teleport_2 ) ) {
              map[y][x] = 9;
            }
            else {
              map[y][x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          goto leave;
        }
      }
      break;
    }
    leave:
}

bool check_attack( int O_COVERED, int map[][100], int y, int x )
{
  const int SIZE_X = 100;
  const int SIZE_Y = 25;

  //define for x
  int attack_max_x = SIZE_X - 3;
  int attack_min_x = 2;


  //define for y
  int attack_max_y = SIZE_Y - 3;
  int attack_min_y = 2;

  // others
  bool can_attack = false;
  int temp_attack;
  int defenser;
  int winner;

  // check for possible west attack

  temp_attack = x - 5;

  if ( temp_attack > attack_min_x ) {
    attack_min_x = x - 5;
  }

  if ( map[y][x - 1] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in west direction (W)" << endl;
    can_attack = true;

    goto check_fin_1;
  }

  for ( int i = x; i >= attack_min_x; --i ) {

    if ( map[y][i] == O_COVERED ) {

      for ( int j = x - 1; j >= i + 1; --j ) {

        if ( map[y][j] != 1 && map[y][j] != 9 ) {

          goto check_fin_1;
        }
      }
      cout << "you can choose to attack an opponent chess in west direction (W)" << endl;
      can_attack = true;
      break;
    }
  }

  check_fin_1:
  // check for possible east attack

  temp_attack = x + 5;

  if ( temp_attack < attack_max_x ) {
    attack_max_x = x + 5;
  }
  if ( map[y][x + 1] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in east direction (E)" << endl;
    can_attack = true;

    goto check_fin_2;
  }

  for ( int i = x; i <= attack_max_x; ++i ) {

    if ( map[y][i] == O_COVERED ) {

      for ( int j = x + 1; j <= i - 1; ++j) {

        if ( map[y][j] != 1 && map[y][j] != 9 ) {

          goto check_fin_1;
        }
      }
      cout << "you can choose to attack an opponent chess in east direction (E)" << endl;
      can_attack = true;
      break;
    }
  }

  check_fin_2:
  // check for possible north attack

  temp_attack = y - 5;

  if ( temp_attack > attack_min_y ) {
    attack_min_y = y - 5;
  }
  if ( map[y - 1][x] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in north direction (N)" << endl;
    can_attack = true;

    goto check_fin_3;
  }

  for ( int i = y; i >= attack_min_y; --i ) {

    if ( map[i][x] == O_COVERED ) {

      for ( int j = y - 1; j >= i + 1; --j) {

        if ( map[j][x] != 1 && map[j][x] != 9 ) {

          goto check_fin_3;
        }
      }
      cout << "you can choose to attack an opponent chess in north direction (N)" << endl;
      can_attack = true;
      break;
    }
  }

  check_fin_3:
  // check for possible south attack

  temp_attack = y + 5;

  if ( temp_attack < attack_max_y ) {
    attack_max_y = y + 5;
  }
  if ( map[y + 1][x] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in south direction (S)" << endl;
    can_attack = true;

    goto check_fin_3;
  }

  for ( int i = y; i <= attack_max_y; ++i ) {

    if ( map[i][x] == O_COVERED ) {

      for ( int j = y + 1; j <= i - 1; ++j) {

        if ( map[j][x] != 1 && map[j][x] != 9 ) {

          goto check_fin_4;
        }
      }
      cout << "you can choose to attack an opponent chess in south direction (S)" << endl;
      can_attack = true;
      break;
    }
  }

  check_fin_4:
  if (can_attack == true) {
    return true;
  }
  else {
    return false;
  }

}

int ask_move(int map[][100], int x, int y, int &step){

  cout << "the direction of the move?" << endl;

  char char_dir;

  int max_move;

  cin >> char_dir;

  cout << "how many step do you want to move?" << endl;

  cin >> step;

  bool allow_move = true;

  switch (char_dir) {
    case 'N':

      for (int i = 1; i < step + 1; ++i){
        if ((map[y-i][x] != 1) && (map[y-i][x] != 9)){
          allow_move = false;
        }
      }

      break;

    case 'E':

      for (int i = 1; i < step + 1; ++i){
        if ((map[y][x + i] != 1) && (map[y][x + i] != 9)){
          allow_move = false;
        }
      }

      break;

    case 'S':

      for (int i = 1; i < step + 1; ++i){
        if ((map[y + i][x] != 1) && (map[y + i][x] != 9)){
          allow_move = false;
        }
      }

      break;

    case 'W':

      for (int i = 1; i < step + 1; ++i){
        if ((map[y][x - i] != 1) && (map[y][x - i] != 9)){
          allow_move = false;
        }
      }

      break;

    }

    int new_x, new_y;

    if (allow_move){

      switch (char_dir) {
        case 'N':

          new_y = y - step;

          break;

        case 'E':

          new_x = x + step;

          break;

        case 'S':

          new_y = y + step;

          break;

        case 'W':

          new_x = x - step;

          break;

      }


    }

    if (check_teleporter(y, x, teleport_1, teleport_2)){
      map[y][x] = 9;
    }
    else{
      map[y][x] = 1;
    }

    if (check_teleporter(new_y, new_x, teleport_1, teleport_2){

      if ( ( new_y == teleport_1[0] ) && ( new_x == teleport_1[1] ) ) {

        player[1].emperor_x = teleport_2[1];

        player[1].emperor_y = teleport_2[0];

        map[player[1].emperor_y][player[1].emperor_x] = 5;

      }

      else {

        player[1].emperor_x = teleport_1[1];

        player[1].emperor_y = teleport_1[0];

        map[player[1].emperor_y][player[1].emperor_x] = 5;

      }

    }
    else{

      player[1].emperor_y = new_y;
      player[1].emperor_x = new_x;
      map[player[1].emperor_y][player[1].emperor_x] = 5;
      cout << "The destination of your chess contains a teleporter, your chosen chess is being teleported to the other side" << endl;

    }

    cancel_base_chess(1, map);
    compass();
    print_map(map);
    chess_identity();

    if (check_attack(4, map, player[1].emperor_y, player[1].emperor_x)) {
      char attack_option;
      cout << "please choose the direction to attack, or type X to not attack" << endl;
      cin >> attack_option;
      if (attack_option == 'X') {
        goto final;
      }
      attack(map, 5, teleport_1, teleport_2, 4, attack_option, player[1].emperor_y, player[1].emperor_x);
    }

    else {
      cout << "you do not have any target to attack" << endl;
    }

    final:
    cout << "your chess identity will be hidden now" << endl;
    cout << endl;

    map[player[1].emperor_y][player[1].emperor_x] = 3;







}

bool player1_interface( int player1_starting_point[2], int map[][100], int teleport_1[2], int teleport_2[2] )
{
  bool another_move = true;

  while (another_move) {
    another_move = false;
    char chosen_chess;

    // all display element when printing map
    compass();
    print_map(map);
    chess_identity();

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

          if ( map[player1_starting_point[1]][player1_starting_point[0]] != 1 && map[player1_starting_point[1]][player1_starting_point[0]] != 9) {
            cout << "The starting point is occupied, please choose another move" << endl;
            another_move = true;
            goto another;
          }

          if ( check_teleporter (player1_starting_point[1], player1_starting_point[0], teleport_1, teleport_2 ) ) {

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
            cout << "Your chosen chess is deployed for the first time. No further moves" << endl;
            cout << "The starting point of your side contains a teleporter, your chosen chess is being teleported to the other side" << endl;
          }

          if ( map[player1_starting_point[1]][player1_starting_point[0]] == 1 ) {

            player[1].emperor_x = player1_starting_point[0];

            player[1].emperor_y = player1_starting_point[1];

            map[player[1].emperor_y][player[1].emperor_x] = 5;

            cout << "Your chosen chess is deployed for the first time. No further moves" << endl;
          }

          cancel_base_chess(1, map);
          compass();
          print_map(map);
          chess_identity();

          if (check_attack(4, map, player[1].emperor_y, player[1].emperor_x)) {
            char attack_option;
            cout << "please choose the direction to attack, or type X to not attack" << endl;
            cin >> attack_option;
            if (attack_option == 'X') {
              goto final;
            }
            attack(map, 5, teleport_1, teleport_2, 4, attack_option, player[1].emperor_y, player[1].emperor_x);
          }

          else {
            cout << "you do not have any target to attack" << endl;
          }

          final:
          cout << "your chess identity will be hidden now" << endl;
          cout << endl;

          map[player[1].emperor_y][player[1].emperor_x] = 3;

        }

        else if (( player[1].emperor_x == -1 ) && ( player[1].emperor_y == -1 )) {
          cout << "Your chess is already dead. Please choose another chess" << endl;
          another_move = true;
          goto another;
        }

        else{

          int current_x = player[1].emperor_x;
          int current_y = player[1].emperor_y;
          int step;
          int direction;

          step = ask_move(map, current_x, current_y, step);


        }


        break;






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
    another:
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
