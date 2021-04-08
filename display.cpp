#include <iostream>
#include <string>

#define A "\u2580"
#define B "\u2584"
#define C "\u27A4"
#define D "\u2B9E"
#define E "\u2588"
#define CROSS "\u254B"
using namespace std;

void game_title()
{
  cout << "    " << A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A<< endl;
  cout << "    " <<
  R"(
       ###########       ##        ###########  ############  ##           ###########
       ##               ####       ##                ##       ##           ##
       ##              ##  ##      ##                ##       ##           ##
       ##             ##    ##     ###########       ##       ##           ###########
       ##            ##########             ##       ##       ##           ##
       ##           ##        ##            ##       ##       ##           ##
       ########### ##          ##  ###########       ##       ###########  ###########

             ###########  ##                 ##        ###########  ##        ##
             ##           ##                ####       ##           ##        ##
             ##           ##               ##  ##      ##           ##        ##
             ##           ##              ##    ##     ###########  ############
             ##           ##             ##########             ##  ##        ##
             ##           ##            ##        ##            ##  ##        ##
             ###########  ###########  ##          ##  ###########  ##        ##
  )" << endl;
  cout << "    " << B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B << endl;
}

void game_rules()
{
  cout << C << " Game Description" << endl;
  cout << "This game is a Player vs Player game." << "\n" << endl;
  cout << "A 100 x 50 map will be generated. There will be two castles in each of the diagonal corner." << "\n" << endl;
  cout << "Random paths will be created which connects the castle of the first player to that of the second player." << "\n" << endl;
  cout << "Players have to compete with each other to gain full control of the kingdom." << "\n" << endl;
  cout << "\n""\n";

  cout << C << " Game Rule" << endl;
  cout << "Each player will have 4 chess pieces to deploy." << "\n" << endl;
  cout << "Initially, all pieces will remain inside the player’s castle. Players will take turns to move the pieces." << "\n" << endl;
  cout << "In each round, player will choose 1 piece and decide the direction (North, East, South, West) and the number of steps (1, 2, 3, 4, 5) to move." << "\n" << endl;
  cout << "However, the piece can only walk straight within a turn (i.e. the player can only walk horizontally or vertically)" << "\n" << endl;
  cout << "After moving the piece, if there is an enemy piece along a vertical path or a horizontal path, the player can choose whether to attack or not." << "\n" << endl;
  cout << "\n""\n";

  cout << C << " Characters" << endl;
  cout << "The four pieces have their own identity, namely, Emperor, Knight, Soldier and Assassin." << "\n" << endl;
  cout << "\n""\n";

  cout << C << " Battle Rules";
  cout <<
  R"(
  1. Emperor channels power from the core of the sun, he can kill Knight and Soldier ruthlessly
  2. Knight is the apprentice of the combat master, he can kill Soldier and Assassin gracefully
  3. Soldier is equipped with night goggles, he can spot and kill Assassin with full effort
  4. Assassin hides in the dark, he can sneak and kill the emperor without a sound

  If pieces with same status are encountered, the attacker wins.
  The identity of player 1’s own pieces will be revealed when in player 1’s turn and return to unknown when the turn is ended, same case for player 2.
  Therefore, the identity of the enemy’s pieces are unknown. Players have to make the decision on whether to attack or not as the battle result depends on the piece’s identity.
  )";
  cout << "\n""\n""\n";

  cout << C << " Teleporters";
  cout <<
  R"(
  Furthermore, the path contains 2 hidden teleporters, when any of the pieces step into one of the teleporter, it will be transported to the other end of the teleporter
  (i.e. when a chess steps into (3,5) and instantly being transported to (7,4), both player should realize the actual location of the two teleporters).
  If the other end of the teleporter is occupied by a piece, the chess will not be teleported when it steps into the teleporter.
  The location of the two teleporters will change after being used for 3 times.
  )";
  cout << "\n""\n""\n";

  cout << C << " Game Termination";
  cout <<
  R"(
  Case 1: All chess pieces are being killed. When a chess piece is being killed, the screen
          display “player i’s Emperor is killed”.
  Case 2: Any chess piece of the enemy enters your base.

  Players can choose to retrieve previously saved game progress or to start a new game.
  )" << endl;
}

void dead_message(int x)
{
  if (x == 1) {
    cout << E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E << endl;
    for (int i = 0; i < 13; ++i) {
      cout << "\n";
    }
    cout <<
    R"(
      ###########  ##                 ##       ##      ##  ###########  ###########       ####
      ##       ##  ##                ####       ##    ##   ##           ##       ##     ### ##
      ##       ##  ##               ##  ##       ##  ##    ##           ##       ##    ###  ##
      ###########  ##              ##    ##       ####     ###########  ###########         ##
      ##           ##             ##########       ##      ##           ## ####             ##
      ##           ##            ##        ##      ##      ##           ##   ####           ##
      ##           ###########  ##          ##     ##      ###########  ##     ####    ###########








        ##########  ###########         #########     ###########        ##        #########
            ##      ##                  ##      ##    ##                ####       ##      ##
            ##      ##                  ##       ##   ##               ##  ##      ##       ##
            ##      ###########         ##        ##  ###########     ##    ##     ##        ##
            ##               ##         ##       ##   ##             ##########    ##       ##
            ##               ##         ##      ##    ##            ##        ##   ##      ##
        ##########  ###########         #########     ###########  ##          ##  #########
    )" << endl;
    for (int i = 0; i < 13; ++i) {
      cout << "\n";
    }
    cout << E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E << endl;
  }
  else {
    cout << E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E << endl;
    for (int i = 0; i < 13; ++i) {
      cout << "\n";
    }
    cout <<
    R"(
      ###########  ##                 ##       ##      ##  ###########  ###########    ###########
      ##       ##  ##                ####       ##    ##   ##           ##       ##             ##
      ##       ##  ##               ##  ##       ##  ##    ##           ##       ##             ##
      ###########  ##              ##    ##       ####     ###########  ###########    ###########
      ##           ##             ##########       ##      ##           ## ####        ##
      ##           ##            ##        ##      ##      ##           ##   ####      ##
      ##           ###########  ##          ##     ##      ###########  ##     ####    ###########








        ##########  ###########         #########     ###########        ##        #########
            ##      ##                  ##      ##    ##                ####       ##      ##
            ##      ##                  ##       ##   ##               ##  ##      ##       ##
            ##      ###########         ##        ##  ###########     ##    ##     ##        ##
            ##               ##         ##       ##   ##             ##########    ##       ##
            ##               ##         ##      ##    ##            ##        ##   ##      ##
        ##########  ###########         #########     ###########  ##          ##  #########
    )" << endl;
    for (int i = 0; i < 13; ++i) {
      cout << "\n";
    }
    cout << E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E E << endl;
  }
}

void compass()
{
  cout << "  " << "N" << endl;
  cout << "W" << " " << CROSS << " " << "E" << endl;
  cout << "  " << "S" << endl;
}
int main()
{
  game_title();
  game_rules();
  dead_message(1);
  dead_message(2);
  compass();
}
