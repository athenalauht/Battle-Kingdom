#include <iostream>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main() {

  //map size of 75*75

  const int SIZE = 75;

  //random generate paths connecting (2,2) and (SIZE-2, SIZE-2)
  //first path start from (2,2)
  //random generate the direction by taking:
  //vertical(0) : 1 as North, -1 as South
  //horizonal(1) : 1 as East, -1 as West

  //prevent unnesssary looping of a path/ errors:
  //restriction for random generation:
  //if -y is generated in x-1, x cannot be y
  //the current position cannot be out of range (i.e. x = 2 to SIZE-2, y = 2 to SIZE-2)

  //first path start from (2,2)
  int cur_x = 2, cur_y = 2;
  int temp_x, temp_y;
  int xy, temp_xy;            //hor or vert
  int dir, temp_dir;          //given hor or vert, choose actual dir
  int movex = 0, movey = 0;

  while ((cur_x != SIZE - 2) && (cur_x != SIZE - 2)){

    //choosing hor or vertical
    xy = rand() % 2;

    //define multiplier
    switch (xy) {
      case 0:
      goto temp_move_x;

      case 1:
      goto temp_move_y;

    }

    temp_move_x:
    temp_x = cur_x;
    temp_dir = (rand() % 3) - 1;          //store -1, 0, 1
    temp_x += temp_dir;
    if ((cur_x >= 2) && (cur_x <= (SIZE - 2))){
      if (movex = 1){
        if (temp_dir = dir){

        }
      }
    }







  }



  //player start from (2,2)
  //player 1 initial chess stays at (0,0),(0,1),(1,0),(1,1)
  //player 2 initial chess stays at (SIZE,SIZE), (SIZE,SIZE-1), (SIZE-1,SIZE),(SIZE-1,SIZE-1)





}
