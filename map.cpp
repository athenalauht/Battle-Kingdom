#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main() {

  //map size of 75*75

  const int SIZE_X = 100 - 1;
  const int SIZE_Y = 25 - 1;

  //random generate paths connecting (2,2) and (SIZE-2, SIZE-2)
  //first path start from (2,2)
  //random generate the direction by taking:
  // 0 as North, 1 as East, 2 as South, 3 as West
  // step with 0 - 10, with high probabilty for 0(2),6,7,8
  //divided into eight part, increase the prob of going west and south

  int temp_rand;

  //map of the above size
  int map[25][100];

  //open path.txt
  ofstream path;
  path.open("path.txt");

  srand (time(NULL));

  int cur_x = 2, cur_y = 2;

  int temp_step, step;
  int temp_cur_x, temp_cur_y;
  int temp_dir;

  path << cur_y << " " << cur_x<< '\n';


  while ((cur_x != SIZE_X - 2) || (cur_y != SIZE_Y - 2)){

    temp_step = rand() % 16;

    switch(temp_step){

      case 11:
      case 12:
        step = 0;
        break;

      case 13:
        step = 6;
        break;

      case 14:
        step = 7;
        break;

      case 15:
        step = 8;
        break;

      default:
        step = temp_step;
        break;

    }

    temp_dir = rand() % 7;

    //North
    if (temp_dir == 0){

      temp_cur_x = cur_x;
      temp_cur_y = cur_y - step;

    }

    //East
    else if ((temp_dir == 1) || (temp_dir == 4)){

      temp_cur_x = cur_x + step;
      temp_cur_y = cur_y;

    }

    //South
    else if ((temp_dir == 2) || (temp_dir == 6)){

      temp_cur_x = cur_x;
      temp_cur_y = cur_y + step;

    }

    //West
    else if (temp_dir == 3){

      temp_cur_x = cur_x - step;
      temp_cur_y = cur_y;

    }

    if ((temp_cur_x <= SIZE_X - 2) && (temp_cur_y <= SIZE_Y - 2) && (temp_cur_x >= 2) && (temp_cur_y >= 2)){


      //North
      if (temp_dir == 0){

        for (int p = temp_cur_y; p < cur_y + 1; ++p){

          path << p << " ";
          path << cur_x << '\n';

        }

        cur_x = temp_cur_x;
        cur_y = temp_cur_y;

      }

      //East
      else if ((temp_dir == 1)){

        for (int p = cur_x; p < temp_cur_x + 1; ++p){

          path << cur_y << " ";
          path << p << '\n';

        }

        cur_x = temp_cur_x;
        cur_y = temp_cur_y;


      }

      //South
      else if ((temp_dir == 2)){

        for (int p = cur_y; p < temp_cur_y + 1; ++p){

          path << p << " ";
          path << cur_x << '\n';

        }

        cur_x = temp_cur_x;
        cur_y = temp_cur_y;


      }

      //West
      else if (temp_dir == 3){

        for (int p = temp_cur_x; p < cur_x + 1; ++p){

          path << cur_y << " ";
          path << p << '\n';

        }

        cur_x = temp_cur_x;
        cur_y = temp_cur_y;


      }


    }

  }






  path.close();

  //player start from (2,2)
  //player 1 initial chess stays at (0,0),(0,1),(1,0),(1,1)
  //player 2 initial chess stays at (SIZE,SIZE), (SIZE,SIZE-1), (SIZE-1,SIZE),(SIZE-1,SIZE-1)


}
