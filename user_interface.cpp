// Group Project -- Group 13
// Description: programme that control all user input and output

#include <iostream>
#include <string>
#include "display.h"
#include "map.h"
#include "save.h"
#include "battle_result.h"
#include "save.h"
#include "retrieve.h"
#include "mystruct.h"

#define PATH "\u2591"
#define BORDER "\u2588"
#define P1_COVERED "\u25CF"
#define P2_COVERED "\u25CB"

#define EMPEROR "\u2654"
#define KNIGHT "\u2658"
#define SOLDIER "\u2659"
#define ASSASSIN "\u2657"

using namespace std;


// function to reveal the identity of player x's chess when it is the start his turn
void reveal_chess (int x, int map[][100])
{
  switch (x) {
    case 1:
      if ( player[1].emperor_x != 0 && player[1].emperor_y != 0 ) {
        if ( player[1].emperor_x != -1 && player[1].emperor_y != -1 ) {
          map[player[1].emperor_y][player[1].emperor_x] = 5;
        }
      }
      if ( player[1].knight_x != 0 && player[1].knight_y != 0 ) {
        if ( player[1].knight_x != -1 && player[1].knight_y != -1 ) {
          map[player[1].knight_y][player[1].knight_x] = 6;
        }
      }
      if ( player[1].soldier_x != 0 && player[1].soldier_y != 0 ) {
        if ( player[1].soldier_x != -1 && player[1].soldier_y != -1 ) {
          map[player[1].soldier_y][player[1].soldier_x] = 7;
        }
      }
      if ( player[1].assassin_x != 0 && player[1].assassin_y != 0 ) {
        if ( player[1].assassin_x != -1 && player[1].assassin_y != -1 ) {
          map[player[1].assassin_y][player[1].assassin_x] = 8;
        }
      }
      break;
    case 2:
      if ( player[2].emperor_x != 0 && player[2].emperor_y != 0 ) {
        if ( player[2].emperor_x != -1 && player[2].emperor_y != -1 ) {
          map[player[2].emperor_y][player[2].emperor_x] = 10;
        }
      }
      if ( player[2].knight_x != 0 && player[2].knight_y != 0 ) {
        if ( player[2].knight_x != -1 && player[2].knight_y != -1 ) {
          map[player[2].knight_y][player[2].knight_x] = 11;
        }
      }
      if ( player[2].soldier_x != 0 && player[2].soldier_y != 0 ) {
        if ( player[2].soldier_x != -1 && player[2].soldier_y != -1 ) {
          map[player[2].soldier_y][player[2].soldier_x] = 12;
        }
      }
      if ( player[2].assassin_x != 0 && player[2].assassin_y != 0 ) {
        if ( player[2].assassin_x != -1 && player[2].assassin_y != -1 ) {
          map[player[2].assassin_y][player[2].assassin_x] = 13;
        }
      }
  }
}

// function to hide the identity of player x's chess when it is the end of his turn
void hide_chess(int x, int map[][100])
{
  switch (x) {
    case 1:
      if ( player[1].emperor_x != 0 && player[1].emperor_y != 0 ) {
        if ( player[1].emperor_x != -1 && player[1].emperor_y != -1 ) {
          map[player[1].emperor_y][player[1].emperor_x] = 3;
        }
      }
      if ( player[1].knight_x != 0 && player[1].knight_y != 0 ) {
        if ( player[1].knight_x != -1 && player[1].knight_y != -1 ) {
          map[player[1].knight_y][player[1].knight_x] = 3;
        }
      }
      if ( player[1].soldier_x != 0 && player[1].soldier_y != 0 ) {
        if ( player[1].soldier_x != -1 && player[1].soldier_y != -1 ) {
          map[player[1].soldier_y][player[1].soldier_x] = 3;
        }
      }
      if ( player[1].assassin_x != 0 && player[1].assassin_y != 0 ) {
        if ( player[1].assassin_x != -1 && player[1].assassin_y != -1 ) {
          map[player[1].assassin_y][player[1].assassin_x] = 3;
        }
      }
      break;

    case 2:
      if ( player[2].emperor_x != 0 && player[2].emperor_y != 0 ) {
        if ( player[2].emperor_x != -1 && player[2].emperor_y != -1 ) {
          map[player[2].emperor_y][player[2].emperor_x] = 4;
        }
      }
      if ( player[2].knight_x != 0 && player[2].knight_y != 0 ) {
        if ( player[2].knight_x != -1 && player[2].knight_y != -1 ) {
          map[player[2].knight_y][player[2].knight_x] = 4;
        }
      }
      if ( player[2].soldier_x != 0 && player[2].soldier_y != 0 ) {
        if ( player[2].soldier_x != -1 && player[2].soldier_y != -1 ) {
          map[player[2].soldier_y][player[2].soldier_x] = 4;
        }
      }
      if ( player[2].assassin_x != 0 && player[2].assassin_y != 0 ) {
        if ( player[2].assassin_x != -1 && player[2].assassin_y != -1 ) {
          map[player[2].assassin_y][player[2].assassin_x] = 4;
        }
      }
      break;
  }
}

// function to remove 1 chess from base if a chess is being deployed
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

      else if ( map[24][99] == 4 )
        map[24][99] = 0;

  }

}

// function to check the identity of the chess with coordinate x, y
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

// function to check the loser between two chess in a battle
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
    player[2].emperor_x = -1;
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

// function to check whether the target location contains a teleporter
bool check_teleporter ( int y, int x, int teleport_1[2], int teleport_2[2] )
{
  if ( y == teleport_1[0] && x == teleport_1[1] )
    return true;

  else if ( y == teleport_2[0] && x == teleport_2[1] )
    return true;

  else
    return false;
}

// function to intialize an attack
void attack( int map[][100], int attacker, int teleport_1[2], int teleport_2[2], int O_COVERED, char attack_option, int *&y, int *&x )
{
  int defenser;
  int winner;
  switch (attack_option) {

    // to attack the enemy in the north direction
    case 'N':
      for (int i = 1; i <= 5; ++i) {

        // if the enemy is within 1 step
        if ( map[(*y) - i][*x] == O_COVERED ) {

          defenser = check_identity((*y) - i, *x);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( (*y) - i, *x , teleport_1, teleport_2 ) ) {
              map[(*y) - i][*x] = 9;
            }
            else {
              map[(*y) - i][*x] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( *y, *x, teleport_1, teleport_2 ) ) {
              map[*y][*x] = 9;
            }
            else {
              map[*y][*x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          return;
        }
      }
      break;

    // to attack the enemy in the east direction
    case 'E':
      for (int i = 1; i <= 5; ++i) {

        if ( map[*y][(*x) + i] == O_COVERED ) {

          defenser = check_identity(*y, (*x) + i);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( *y, (*x) + i, teleport_1, teleport_2 ) ) {
              map[*y][(*x) + i] = 9;
            }
            else {
              map[*y][(*x) + i] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( *y, *x, teleport_1, teleport_2 ) ) {
              map[*y][*x] = 9;
            }
            else {
              map[*y][*x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          return;
        }
      }
      break;

    // to attack the enemy in the south direction
    case 'S':
      for (int i = 1; i <= 5; ++i) {

        if ( map[(*y) + i][*x] == O_COVERED ) {

          defenser = check_identity((*y) + i, *x);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( (*y) + i, *x , teleport_1, teleport_2 ) ) {
              map[(*y) + i][*x] = 9;
            }
            else {
              map[(*y) + i][*x] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( *y, *x, teleport_1, teleport_2 ) ) {
              map[*y][*x] = 9;
            }
            else {
              map[*y][*x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          return;
        }
      }
      break;

    // to attack the enemy in the west direction
    case 'W':
      for (int i = 1; i <= 5; ++i) {

        if ( map[*y][(*x) - i] == O_COVERED ) {

          defenser = check_identity(*y, (*x) - i);

          winner = battle_result(attacker, defenser);

          if (winner == attacker) {

            if ( check_teleporter( *y, (*x) - i, teleport_1, teleport_2 ) ) {
              map[*y][(*x) - i] = 9;
            }
            else {
              map[*y][(*x) - i] = 1;
            }
            cout << "you have killed opponent's chess" << endl;
            death(defenser);
          }

          else {

            if ( check_teleporter( *y, *x, teleport_1, teleport_2 ) ) {
              map[*y][*x] = 9;
            }
            else {
              map[*y][*x] = 1;
            }
            cout << "your chess has been killed by opponent's chess" << endl;
            death(attacker);
          }
          return;
        }
      }
      break;

  }

}

// function to check possible attack directions
bool check_attack( int O_COVERED, int map[][100], int *&y, int *&x )
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

  temp_attack = *x - 5;

  if ( temp_attack > attack_min_x ) {
    attack_min_x = *x - 5;
  }

  if ( map[*y][(*x) - 1] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in west direction (W)" << endl;
    can_attack = true;

    goto check_fin_1;
  }

  for ( int i = *x; i >= attack_min_x; --i ) {

    if ( map[*y][i] == O_COVERED ) {

      for ( int j = *x - 1; j >= i + 1; --j ) {

        if ( map[*y][j] != 1 && map[*y][j] != 9 ) {

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

  temp_attack = *x + 5;

  if ( temp_attack < attack_max_x ) {
    attack_max_x = (*x) + 5;
  }
  if ( map[*y][(*x) + 1] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in east direction (E)" << endl;
    can_attack = true;

    goto check_fin_2;
  }

  for ( int i = *x; i <= attack_max_x; ++i ) {

    if ( map[*y][i] == O_COVERED ) {

      for ( int j = (*x) + 1; j <= i - 1; ++j) {

        if ( map[*y][j] != 1 && map[*y][j] != 9 ) {

          goto check_fin_2;
        }
      }
      cout << "you can choose to attack an opponent chess in east direction (E)" << endl;
      can_attack = true;
      break;
    }
  }

  check_fin_2:

  // check for possible north attack

  temp_attack = (*y) - 5;

  if ( temp_attack > attack_min_y ) {
    attack_min_y = (*y) - 5;
  }
  if ( map[(*y) - 1][*x] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in north direction (N)" << endl;
    can_attack = true;

    goto check_fin_3;
  }

  for ( int i = *y; i >= attack_min_y; --i ) {

    if ( map[i][*x] == O_COVERED ) {

      for ( int j = (*y) - 1; j >= i + 1; --j) {

        if ( map[j][*x] != 1 && map[j][*x] != 9 ) {

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

  temp_attack = (*y) + 5;

  if ( temp_attack < attack_max_y ) {
    attack_max_y = (*y) + 5;
  }
  if ( map[(*y) + 1][*x] == O_COVERED ) {

    cout << "you can choose to attack an opponent chess in south direction (S)" << endl;
    can_attack = true;

    goto check_fin_4;
  }

  for ( int i = *y; i <= attack_max_y; ++i ) {

    if ( map[i][*x] == O_COVERED ) {

      for ( int j = (*y) + 1; j <= i - 1; ++j) {

        if ( map[j][*x] != 1 && map[j][*x] != 9 ) {

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
// function to initialize the first move of a chess
void first_move(int map[][100], int *&y, int *&x, int starting_point[2], int teleport_1[2], int teleport_2[2], int identity, int opponent_covered, bool &another_move, bool &another, int p)
{
  reveal_chess(p, map);

  // to check whether the starting point is occupied
  if ( map[starting_point[1]][starting_point[0]] != 1 && map[starting_point[1]][starting_point[0]] != 9) {
    cout << "The starting point is occupied, please choose another move" << endl;
    another_move = true;
    another = false;

    return;
  }

  // to check whether the starting point contains a teleporter
  if ( check_teleporter (starting_point[1], starting_point[0], teleport_1, teleport_2 ) ) {

    if ( ( starting_point[1] == teleport_1[0] ) && ( starting_point[0] == teleport_1[1] ) ) {

      *x = teleport_2[1];

      *y = teleport_2[0];

      map[*y][*x] = identity;

    }

    else {

      *x = teleport_1[1];

      *y = teleport_1[0];

      map[*y][*x] = identity;

    }
    cout << "Your chosen chess is deployed for the first time. No further moves" << endl;
    cout << "The starting point of your side contains a teleporter, your chosen chess is being teleported to the other side" << endl;
  }

  // to check whether the starting point is a normal path
  if ( map[starting_point[1]][starting_point[0]] == 1 ) {

    *x = starting_point[0];

    *y = starting_point[1];

    map[*y][*x] = identity;

    cout << "Your chosen chess is deployed for the first time. No further moves" << endl;
  }

  cancel_base_chess(p, map);

  // game display
  compass();
  print_map(map);
  chess_identity();

  // to check whether there is any possible attack
  if (check_attack(opponent_covered, map, y, x)) {
    char attack_option;
    cout << "please choose the direction to attack, or type X to not attack." << endl;
    cin >> attack_option;
    if (attack_option == 'X') {
      goto final;
    }
    attack(map, identity, teleport_1, teleport_2, opponent_covered, attack_option, y, x);
  }

  else {
    cout << "you do not have any target to attack" << endl;
  }

  final:
  cout << "your chess identity will be hidden now" << endl;
  cout << endl;


}

// function to coordinate the move of a chess
bool ask_move(int map[][100], int *&y, int *&x, int &step, int teleport_1[2], int teleport_2[2], int identity, int opponent_covered)
{
  // input the direction
  cout << "the direction of the move?" << endl;

  char char_dir;

  int max_move;

  cin >> char_dir;

  while (char_dir != 'E' && char_dir != 'N' && char_dir != 'S' && char_dir != 'W') {
    cout << "Invalid command, please try again" << endl;
    cout << "the direction of the move?" << endl;
    cin >> char_dir;
  }

  // input the number of steps to move
  cout << "how many step do you want to move?" << endl;

  cin >> step;    // Assume the user will input an integer

  switch (char_dir) {
    case 'N':

      for (int i = 1; i < step + 1; ++i){
        if ((map[(*y) - i][*x] != 1) && (map[(*y) - i][*x] != 9)){
          cout << "Sorry, this move is invalid T_T\n" << endl;
          return true;
        }
      }

      break;

    case 'E':

      for (int i = 1; i < step + 1; ++i){
        if ((map[*y][(*x) + i] != 1) && (map[*y][(*x) + i] != 9)){
          cout << "Sorry, this move is invalid T_T\n" << endl;
          return true;
        }
      }

      break;

    case 'S':

      for (int i = 1; i < step + 1; ++i){
        if ((map[(*y) + i][*x] != 1) && (map[(*y) + i][*x] != 9)){
          cout << "Sorry, this move is invalid T_T\n" << endl;
          return true;
        }
      }

      break;

    case 'W':

      for (int i = 1; i < step + 1; ++i){
        if ((map[*y][(*x) - i] != 1) && (map[*y][(*x) - i] != 9)){
          cout << "Sorry, this move is invalid T_T\n" << endl;
          return true;
        }
      }

      break;

    }

    int new_x, new_y;


      switch (char_dir) {
        case 'N':

          new_y = *y - step;
          new_x = *x;

          break;

        case 'E':

          new_x = *x + step;
          new_y = *y;

          break;

        case 'S':

          new_y = *y + step;
          new_x = *x;

          break;

        case 'W':

          new_x = *x - step;
          new_y = *y;

          break;

      }



    // check teleporter
    if ( check_teleporter(*y, *x, teleport_1, teleport_2) ) {
      map[*y][*x] = 9;
    }
    else {
      map[*y][*x] = 1;
    }

    if ( check_teleporter(new_y, new_x, teleport_1, teleport_2) ) {

      if ( ( new_y == teleport_1[0] ) && ( new_x == teleport_1[1] ) ) {

        *x = teleport_2[1];

        *y = teleport_2[0];

        map[*y][*x] = identity;

      }

      else {

        *x = teleport_1[1];

        *y = teleport_1[0];

        map[*y][*x] = identity;

      }

      cout << "The destination of your chess contains a teleporter, your chosen chess is being teleported to the other side" << endl;

    }
    else {

      *y = new_y;
      *x = new_x;
      map[*y][*x] = identity;


    }

    // game display
    compass();
    print_map(map);
    chess_identity();

    // check possible attack
    if (check_attack(opponent_covered, map, y, x)) {
      char attack_option;
      cout << "please choose the direction to attack, or type X to not attack" << endl;
      cin >> attack_option;
      if (attack_option == 'X') {
        goto final;
      }
      attack(map, identity, teleport_1, teleport_2, opponent_covered, attack_option, y, x);
    }

    else {
      cout << "you do not have any target to attack" << endl;
    }
    
    final:
    cout << "your chess identity will be hidden now" << endl;
    cout << endl;

    return false;

}

// function to control player 1's action
bool player1_interface( int player1_starting_point[2], int map[][100], int teleport_1[2], int teleport_2[2] )
{
  reveal_chess(1, map);
  hide_chess(2,map);
  bool another_move = true;
  int * current_x = NULL;
  int * current_y = NULL;
  bool another = true;
  int step;
  int identity;
  while (another_move) {
    reveal_chess(1, map);
    another_move = false;
    char chosen_chess;

    // all display element when printing map
    compass();
    print_map(map);
    chess_identity();

    cout << "Player 1, which chess would you like to move?" << endl;
    cout << "Emperor / Knight / Soldier / Assassin" << endl;
    cout << "Type (E / K / S / A) to move, T to save and terminate the game" << endl;
    cout << "\n" << endl;
    cin >> chosen_chess;

    while (chosen_chess != 'E' && chosen_chess != 'K' && chosen_chess != 'S' && chosen_chess != 'A' && chosen_chess != 'T') {
      cout << "Invalid command, please try again" << endl;
      cout << "Player 1, which chess would you like to move?" << endl;
      cout << "Emperor / Knight / Soldier / Assassin" << endl;
      cout << "Type (E / K / S / A) to move, T to save and terminate the game" << endl;
      cin >> chosen_chess;
    }

    switch (chosen_chess) {

      case 'T':
        cout << "The game is ended" << endl;
        store_profile(player);
        store_teleport(teleport_1, teleport_2);

        return true;
        break;

      case 'E':
        current_x = &player[1].emperor_x;
        current_y = &player[1].emperor_y;
        identity = 5;
        break;
      case 'K':
        current_x = &player[1].knight_x;
        current_y = &player[1].knight_y;
        identity = 6;
        break;

      case 'S':
        current_x = &player[1].soldier_x;
        current_y = &player[1].soldier_y;
        identity = 7;
        break;

      case 'A':
        current_x = &player[1].assassin_x;
        current_y = &player[1].assassin_y;
        identity = 8;
        break;

      default:
      cout << "Sorry, wrong input :(" << endl;
      another_move = true;
    }

    if ( ( *current_x == 0 ) && ( *current_y == 0 ) ) {

      first_move( map, current_y, current_x, player1_starting_point, teleport_1, teleport_2, identity, 4, another_move, another, 1);
      hide_chess(1, map);
    }

    else if (( *current_x == -1 ) && ( *current_y == -1 )) {
      cout << "Your chess is already dead. Please choose another chess" << endl;
      another_move = true;
      another = false;
    }

    else {
      another_move = ask_move(map, current_y, current_x, step, teleport_1, teleport_2, identity, 4);
      hide_chess(1, map);
    }

    if ( *current_x == 97 ) {
      cout << "As player 2's boarder has been invaded by player 1" << endl;
      cout << "player 1 wins the game" << endl;
      return true;
    }

    if (player[1].emperor_x == -1 && player[1].emperor_y == -1) {
      if ( player[1].knight_x == -1 && player[1].knight_y == -1 ) {
        if ( player[1].soldier_x != -1 && player[1].soldier_y != -1 ) {
          if ( player[1].assassin_x != -1 && player[1].assassin_y != -1 ) {
            cout << "As all the chess of player 1 have been terminated" << endl;
            cout << "Player 2 wins the game" << endl;
            return true;
          }
        }
      }
    }

    if (player[2].emperor_x == -1 && player[2].emperor_y == -1) {
      if ( player[2].knight_x == -1 && player[2].knight_y == -1 ) {
        if ( player[2].soldier_x != -1 && player[2].soldier_y != -1 ) {
          if ( player[2].assassin_x != -1 && player[2].assassin_y != -1 ) {
            cout << "As all the chess of player 2 have been terminated" << endl;
            cout << "Player 1 wins the game" << endl;
            return true;
          }
        }
      }
    }

    if ( another ) {
      char response;
      cout << "Player 1, are you ready?" << endl;
      cout << "Please press Y when you are ready" << endl;
      cin >> response;
    }

  }
  return false;
}

// function to control player 2's action
bool player2_interface( int player2_starting_point[2], int map[][100], int teleport_1[2], int teleport_2[2] )
{
  reveal_chess(2, map);
  hide_chess(1,map);
  bool another_move = true;
  bool another = true;
  int * current_x = NULL;
  int * current_y = NULL;
  int step;
  int identity;

  while (another_move) {
    reveal_chess(2, map);
    another_move = false;
    char chosen_chess;

    // all display element when printing map
    compass();
    print_map(map);
    chess_identity();

    cout << "Player 2, which chess would you like to move?" << endl;
    cout << "Emperor / Knight / Soldier / Assassin" << endl;
    cout << "Type (E / K / S / A) to move, T to save and terminate the game" << endl;
    cout << "\n" << endl;
    cin >> chosen_chess;

    while (chosen_chess != 'E' && chosen_chess != 'K' && chosen_chess != 'S' && chosen_chess != 'A' && chosen_chess != 'T') {
      cout << "Invalid command, please try again" << endl;
      cout << "Player 2, which chess would you like to move?" << endl;
      cout << "Emperor / Knight / Soldier / Assassin" << endl;
      cout << "Type (E / K / S / A) to move, T to save and terminate the game" << endl;
      cin >> chosen_chess;
    }


    switch (chosen_chess) {

      case 'T':
        cout << "The game is ended" << endl;
        store_profile(player);
        store_teleport(teleport_1, teleport_2);

        return true;
        break;

      case 'E':
        current_x = &player[2].emperor_x;
        current_y = &player[2].emperor_y;
        identity = 10;
        break;

      case 'K':
        current_x = &player[2].knight_x;
        current_y = &player[2].knight_y;
        identity = 11;
        break;

      case 'S':
        current_x = &player[2].soldier_x;
        current_y = &player[2].soldier_y;
        identity = 12;
        break;

      case 'A':
        current_x = &player[2].assassin_x;
        current_y = &player[2].assassin_y;
        identity = 13;
        break;

      default:
      cout << "Sorry, wrong input :(" << endl;
      another_move = true;

    }

    if ( ( *current_x == 0 ) && ( *current_y == 0 ) ) {

      first_move( map, current_y, current_x, player2_starting_point, teleport_1, teleport_2, identity, 3, another_move, another, 2);
      hide_chess(2, map);
    }

    else if (( *current_x == -1 ) && ( *current_y == -1 )) {
      cout << "Your chess is already dead. Please choose another chess" << endl;
      another_move = true;
      another = false;
    }

    else {
      another_move = ask_move(map, current_y, current_x, step, teleport_1, teleport_2, identity, 3);
      hide_chess(2, map);
    }

    if ( *current_x == 2 ) {
      cout << "player 2 win the game" << endl;
      return true;
    }

    if (player[1].emperor_x == -1 && player[1].emperor_y == -1) {
      if ( player[1].knight_x == -1 && player[1].knight_y == -1 ) {
        if ( player[1].soldier_x != -1 && player[1].soldier_y != -1 ) {
          if ( player[1].assassin_x != -1 && player[1].assassin_y != -1 ) {
            cout << "As all the chess of player 1 have been terminated" << endl;
            cout << "Player 2 wins the game" << endl;
            return true;
          }
        }
      }
    }

    if (player[2].emperor_x == -1 && player[2].emperor_y == -1) {
      if ( player[2].knight_x == -1 && player[2].knight_y == -1 ) {
        if ( player[2].soldier_x != -1 && player[2].soldier_y != -1 ) {
          if ( player[2].assassin_x != -1 && player[2].assassin_y != -1 ) {
            cout << "As all the chess of player 2 have been terminated" << endl;
            cout << "Player 1 wins the game" << endl;
            return true;
          }
        }
      }
    }

    if (another) {
      char response;
      cout << "Player 2, are you ready?" << endl;
      cout << "Please press Y when you are ready" << endl;
      cin >> response;
    }

  }
  return false;
}
