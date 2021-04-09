#include <iostream>
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
