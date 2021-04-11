#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#define PATH "\u2591"
#define BORDER "\u2588"
#define P1_COVERED "\u25CF"
#define P2_COVERED "\u25CB"

#define EMPEROR "\u2654"
#define KNIGHT "\u2658"
#define SOLDIER "\u2659"
#define ASSASSIN "\u2657"



using namespace std;
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



      }


    }

    cout << '\n';

  }






}
