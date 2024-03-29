// Group Project -- Group 13
// Description: programme to save the game progress when the game is terminated

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystruct.h"


using namespace std;

//save the position of the chess into txt
void store_profile(profile player[3]){

  //open p1.txt
  ofstream p1;
  p1.open("p1.txt");

  p1 << player[1].emperor_y << " " << player[1].emperor_x << '\n';
  p1 << player[1].knight_y << " " << player[1].knight_x << '\n';
  p1 << player[1].soldier_y << " " << player[1].soldier_x << '\n';
  p1 << player[1].assassin_y << " " << player[1].assassin_x << '\n';

  p1.close();

  //open p2.txt
  ofstream p2;
  p2.open("p2.txt");

  p2 << player[2].emperor_y << " " << player[2].emperor_x << '\n';
  p2 << player[2].knight_y << " " << player[2].knight_x << '\n';
  p2 << player[2].soldier_y << " " << player[2].soldier_x << '\n';
  p2 << player[2].assassin_y << " " << player[2].assassin_x << '\n';

  p2.close();


}

//save the teleport location into txt
void store_teleport(int teleport_1[2],int teleport_2[2]){

  //open teleport.txt
  ofstream teleport;
  teleport.open("teleport.txt");

  teleport << teleport_1[0] << " " << teleport_1[1] << '\n';
  teleport << teleport_2[0] << " " << teleport_2[1] << '\n';

  teleport.close();

}

//save and store the following player in turn  to play the game
void store_count(int x){
  ofstream count;
  count.open("count.txt");
  count << x;
  count.close();
}
