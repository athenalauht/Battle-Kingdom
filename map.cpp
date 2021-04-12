// Group Project -- Group 13
// Description: programme that create a map and store the path position into path.txt
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PATH "\u2591"
#define BORDER "\u2588"
#define P1_COVERED "\u25CF"
#define P2_COVERED "\u25CB"

#define TELEPORT "\u2298"

#define EMPEROR "\u2654"
#define KNIGHT "\u2658"
#define SOLDIER "\u2659"
#define ASSASSIN "\u2657"

using namespace std;

void create_path() {

 //map size of 75*75

 const int SIZE_X = 100 - 1;
 const int SIZE_Y = 25 - 1;

 //random generate paths connecting left and right border
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



 int starting_x, starting_y;

 //random generate starting point on left border
 starting_y = rand() % (SIZE_Y - 3 ) + 2;

 int cur_x = 2, cur_y = starting_y;

 int temp_step, step;
 int temp_cur_x, temp_cur_y;
 int temp_dir;

 path << cur_y << " " << cur_x<< '\n';


 //stop once reach right border
 while ((temp_cur_x <= SIZE_X - 2)){

   step = rand() % 6;

   temp_dir = rand() % 9;

   //North
   if ((temp_dir == 0) || (temp_dir == 1)){

     temp_cur_x = cur_x;
     temp_cur_y = cur_y - step;

   }

   //East
   else if ((temp_dir == 2) || (temp_dir == 3) || (temp_dir == 4)){

     temp_cur_x = cur_x + step;
     temp_cur_y = cur_y;

   }

   //South
   else if ((temp_dir == 5) || (temp_dir == 6)){

     temp_cur_x = cur_x;
     temp_cur_y = cur_y + step;

   }

   //West
   else if ((temp_dir == 7) || (temp_dir == 8)){

     temp_cur_x = cur_x - step;
     temp_cur_y = cur_y;

   }

   if ((temp_cur_x <= SIZE_X - 2) && (temp_cur_y <= SIZE_Y - 2) && (temp_cur_x >= 2) && (temp_cur_y >= 2)){


     //North store
     if ((temp_dir == 0) || (temp_dir == 1)){

       for (int p = temp_cur_y; p < cur_y + 1; ++p){

         path << p << " ";
         path << cur_x << '\n';

       }

       cur_x = temp_cur_x;
       cur_y = temp_cur_y;

     }

     //East store
     else if ((temp_dir == 2) || (temp_dir == 3) || (temp_dir == 4)){

       for (int p = cur_x; p < temp_cur_x + 1; ++p){

         path << cur_y << " ";
         path << p << '\n';

       }

       cur_x = temp_cur_x;
       cur_y = temp_cur_y;


     }

     //South store
     else if ((temp_dir == 5) || (temp_dir == 6)){

       for (int p = cur_y; p < temp_cur_y + 1; ++p){

         path << p << " ";
         path << cur_x << '\n';

       }

       cur_x = temp_cur_x;
       cur_y = temp_cur_y;


     }

     //West store
     else if ((temp_dir == 7) || (temp_dir == 8)){

       for (int p = temp_cur_x; p < cur_x + 1; ++p){

         path << cur_y << " ";
         path << p << '\n';

       }

       cur_x = temp_cur_x;
       cur_y = temp_cur_y;


     }


   }

 }



 //do East for the following

 for (int p = cur_x; p < SIZE_X - 2 + 1; ++p){

   path << cur_y << " ";
   path << p << '\n';

 }



 path.close();

 //player start from (2,2)
 //player 1 initial chess stays at (0,0),(0,1),(1,0),(1,1)
 //player 2 initial chess stays at (SIZE,SIZE), (SIZE,SIZE-1), (SIZE-1,SIZE),(SIZE-1,SIZE-1)

 //avalible limit : 2 to SIZE - 2, meaning = rand() % (SIZE - 3 ) + 2

}

void initial_path( int map[][100]){

  const int SIZE_X = 100;
  const int SIZE_Y = 25;


  //read file
  ifstream path;
  path.open("path.txt");


  //drawing the path

  int index_x, index_y;  //storing x and y
  int temp_x, temp_y;

  while(path >> index_y){

    temp_y = index_y;

    path >> index_x;
    temp_x = index_x;

    map[temp_y][temp_x] = 1;

  }


  //border making x = 0 to 1 and x = SIZE-1 to SIZE
  //same for y

  //for upper border

  for (int y = 0; y < 2; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 2;

    }

  }


  //for left border

  for (int x = 0; x < 1 + 1; ++x){

    for (int y = 0; y < SIZE_Y; ++y){

      map[y][x] = 2;

    }

  }


  //for lower border

  for (int y = SIZE_Y - 2; y < SIZE_Y; ++y){

    for (int x = 0; x < SIZE_X; ++x){

      map[y][x] = 2;

    }

  }


  //for right border

  for (int x = SIZE_X - 2; x < SIZE_X; ++x){

    for (int y = 0; y < SIZE_Y; ++y){

      map[y][x] = 2;

    }

  }

  //put chess into place (inital state)

  //player 1

  map[0][0] = 3;
  map[0][1] = 3;
  map[1][0] = 3;
  map[1][1] = 3;

  //player 2

  map[SIZE_Y - 2][SIZE_X - 2] = 4;
  map[SIZE_Y - 2][SIZE_X - 1] = 4;
  map[SIZE_Y - 1][SIZE_X - 2] = 4;
  map[SIZE_Y - 1][SIZE_X - 1] = 4;


}

void print_map( int map[][100]) {

  const int SIZE_X = 100;
  const int SIZE_Y = 25;


  // print map
  for (int y = 0; y < SIZE_Y; ++y){

    for (int x = 0; x < SIZE_X; ++x){


      switch(map[y][x]){

        case 0:
          cout << " ";
          break;

        case 1:
          cout << PATH;
          break;

        case 2:
          cout << BORDER;
          break;

        case 3:
          cout << P1_COVERED;
          break;

        case 4:
          cout << P2_COVERED;
          break;

        //player 1
        case 5:
          cout <<  EMPEROR;
          break;

        case 6:
          cout <<  KNIGHT;
          break;

        case 7:
          cout <<  SOLDIER;
          break;

        case 8:
          cout <<  ASSASSIN;
          break;

        case 9:
          cout << TELEPORT;
          break;

        //player 2
        case 10:
          cout <<  EMPEROR;
          break;

        case 11:
          cout <<  KNIGHT;
          break;

        case 12:
          cout <<  SOLDIER;
          break;

        case 13:
          cout <<  ASSASSIN;
          break;

      }


    }

    cout << '\n';

  }


}
