// Group Project -- Group 13
// Description: programme to retrieve the saved game progress

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystruct.h"

#include "user_interface.h"

using namespace std;

void base_chess_retrieve(int map[][100], profile player[3]){

  int count = 0;
  if (player[1].emperor_x != 0 && player[1].emperor_y != 0){
    count = count + 1;
  }
  if (player[1].knight_x != 0 && player[1].knight_y != 0){
    count = count + 1;
  }
  if (player[1].soldier_x != 0 && player[1].soldier_y != 0){
    count = count + 1;
  }
  if (player[1].assassin_x != 0 && player[1].assassin_y != 0){
    count = count + 1;
  }

  if (count > 0){
    map[0][0] = 0;
  }
  if (count > 1){
    map[0][1] = 0;
  }
  if (count > 2){
    map[1][0] = 0;
  }
  if (count > 3){
    map[1][1] = 0;
  }

  count = 0;
  if (player[2].emperor_x != 0 && player[2].emperor_y != 0){
    count = count + 1;
  }
  if (player[2].knight_x != 0 && player[2].knight_y != 0){
    count = count + 1;
  }
  if (player[2].soldier_x != 0 && player[2].soldier_y != 0){
    count = count + 1;
  }
  if (player[2].assassin_x != 0 && player[2].assassin_y != 0){
    count = count + 1;
  }

  if (count > 0){
    map[23][98] = 0;
  }
  if (count > 1){
    map[23][99] = 0;
  }
  if (count > 2){
    map[24][98] = 0;
  }
  if (count > 3){
    map[24][99] = 0;
  }



}

bool retrieve(int map[][100], int teleport_1[2], int teleport_2[2], profile player[3], int &count){

  //return 1 if fail

  //retrieve path
  initial_path(map);

//-------------------------------------

  //checking stage, return 1 if failed for any file


  //read file
  //open p1.txt
  ifstream p1;
  p1.open("p1.txt");
  if (p1.fail()) {
    return false;
  }
  else{
    p1.close();
  }

  //open p2.txt
  ifstream p2;
  p2.open("p2.txt");
  if (p2.fail()) {
    return false;
  }
  else{
    p2.close();
  }

  //open teleport.txt
  ifstream teleport;
  teleport.open("teleport.txt");
  if (teleport.fail()) {
    return false;
  }
  else{
    teleport.close();
  }

  ifstream count_f;
  count_f.open("count.txt");
  if (count_f.fail()) {
    return false;
  }
  else{
    count_f.close();
  }

  //-------------------------------------

  //execute stage

  //path.txt
  initial_path(map);

  //p2.txt
  p1.open("p1.txt");
  p1 >> player[1].emperor_y;
  p1 >> player[1].emperor_x;
  p1 >> player[1].knight_y;
  p1 >> player[1].knight_x;
  p1 >> player[1].soldier_y;
  p1 >> player[1].soldier_x;
  p1 >> player[1].assassin_y;
  p1 >> player[1].assassin_x;
  p1.close();


  //p2.txt
  p2.open("p2.txt");
  p2 >> player[2].emperor_y;
  p2 >> player[2].emperor_x;
  p2 >> player[2].knight_y;
  p2 >> player[2].knight_x;
  p2 >> player[2].soldier_y;
  p2 >> player[2].soldier_x;
  p2 >> player[2].assassin_y;
  p2 >> player[2].assassin_x;
  p2.close();

  //teleport.txt
  teleport.open("teleport.txt");
  teleport >> teleport_1[0];
  teleport >> teleport_1[1];
  teleport >> teleport_2[0];
  teleport >> teleport_2[1];
  teleport.close();

  count_f.open("count.txt");
  count_f >> count;
  count_f.close();

  return true;


}
