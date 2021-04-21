// Group Project -- Group 13
// Description: programme to check which chess will win

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int battle_result(int attack, int defense){
  int pos_attack = attack;
  int pos_defense = defense - 5;

  if ((attack == 5) && (defense == 8)){
    return defense;
  }
  else if ((attack == 8) && (defense == 5)){
    return attack;
  }
  else{
    if (pos_attack > pos_defense){
      return defense;
    }
    else if (pos_attack < pos_defense){
      return attack;
    }
    else if (pos_attack == pos_defense){
      return attack;
    }
  }
  return -1;
}
