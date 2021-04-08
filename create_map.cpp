#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
void create_map()
{
  //map size of 75*75

  const int SIZE_X = 100 - 1;
  const int SIZE_Y = 25 - 1;

  //random generate paths connecting (2,2) and (SIZE-2, SIZE-2)
  //first path start from (2,2)
  //random generate the direction by taking:
  // 0 as North, 12 as East, 456 as South, 7 as West
  //divided into eight part, increase the prob of going west and south



  int cur_x = 2, cur_y = 2;
  int temp_cur_x, temp_cur_y;
  int dir = -1;                       //init direction
  int temp_rand;


  //open path.txt
  ofstream path;
  path.open("path.txt");

  path << "2 2\n";
  srand (time(NULL));

  cur_x = 2, cur_y = 2;

  while ((cur_x != SIZE_X - 2) || (cur_y != SIZE_Y - 2)){

    temp_rand = rand() % 8;
    switch (temp_rand){

      case 0:
      case 6:
      temp_cur_y = cur_y - 1;
      break;

      case 1:
      case 4:
      case 7:
      temp_cur_x = cur_x + 1;
      break;

      case 2:
      case 5:
      temp_cur_y = cur_y + 1;
      break;

      case 3:
      temp_cur_x = cur_x - 1;
      break;

      }

      if ((temp_cur_x <= SIZE_X - 2) && (temp_cur_y <= SIZE_Y - 2) && (temp_cur_x >= 2) && (temp_cur_y >= 2)){

        cur_x = temp_cur_x;
        cur_y = temp_cur_y;

        path << cur_x << " ";
        path << cur_y << '\n';


      }


    }

    cur_x = 2, cur_y = 2;
    while ((cur_x != SIZE_X - 2) || (cur_y != SIZE_Y - 2)){

      temp_rand = rand() % 7;
      switch (temp_rand){

        case 0:
        case 6:
        temp_cur_y = cur_y - 1;
        break;

        case 1:
        case 4:

        temp_cur_x = cur_x + 1;
        break;

        case 2:
        case 5:
        temp_cur_y = cur_y + 1;
        break;

        case 3:
        temp_cur_x = cur_x - 1;
        break;

        }

        if ((temp_cur_x <= SIZE_X - 2) && (temp_cur_y <= SIZE_Y - 2) && (temp_cur_x >= 2) && (temp_cur_y >= 2)){

          cur_x = temp_cur_x;
          cur_y = temp_cur_y;

          path << cur_x << " ";
          path << cur_y << '\n';


        }


      }


  path.close();

  //player start from (2,2)
  //player 1 initial chess stays at (0,0),(0,1),(1,0),(1,1)
  //player 2 initial chess stays at (SIZE,SIZE), (SIZE,SIZE-1), (SIZE-1,SIZE),(SIZE-1,SIZE-1)


}
