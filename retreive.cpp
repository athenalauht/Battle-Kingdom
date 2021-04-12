// Group Project -- Group 13
// Description: programme to output the saved game progress

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool retrieve(int map[][100]){

  //retrieve path
  initial_path(map);

//-------------------------------------

  //checking stage, return 1 if failed for any file


  //read file
  //open p2.txt
  ifstream p2;
  p2.open("p2.txt");
  if (p2.fail()) {
    return 1;
  }
  else{
    p2.close();
  }

  //open p2.txt
  ifstream p2;
  p2.open("p2.txt");
  if (p2.fail()) {
    return 1;
  }
  else{
    p2.close();
  }

  //open teleport.txt
  ifstream teleport;
  teleport.open("teleport.txt");
  if (teleport.fail()) {
    return 1;
  }
  else{
    teleport.close();
  }

  //-------------------------------------

  //execute stage

  //path.txt
  initial_path(map);

  //p2.txt
  p2.open("p2.txt");
  p2 >> player[1].emperor_y;
  p2 >> player[1].emperor_x;
  p2 >> player[1].knight_y;
  p2 >> player[1].knight_x;
  p2 >> player[1].soldier_y;
  p2 >> player[1].soldier_x;
  p2 >> player[1].assassin_y;
  p2 >> player[1].assassin_x;
  p2.close();


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

  return 0;
}
