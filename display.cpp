#include <iostream>
#include <string>

#define A "\u2580"
#define B "\u2584"

using namespace std;

void game_title()
{
  cout << A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A << endl;
  cout <<
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
  cout << B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B B << endl;
  cout << endl;
}

void game_rules()
{
  
}
