// Group Project -- Group 13
// Description:
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "map.h"

using namespace std;

int main()
{
  game_title();
  game_rules();
  dead_message(1);
  compass();

  create_path();
}
