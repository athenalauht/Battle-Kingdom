#include <iostream>
#include <cctype>
using namespace std;
int main() {

  //map size of 75*75

  const int SIZE = 75;

  //random generate paths connecting (2,2) and (SIZE-2, SIZE-2)
  //first path start from (2,2)
  //random generate the direction by taking:
  // 0 as North, 1 as East, 2 as South, 3 as West

  //prevent unnesssary looping of a path
  //if 0 is generated in x-1, x cannot be 2
  //if 1 is generated in x-1, x cannot be 3
  //if 2 is generated in x-1, x cannot be 0
  //if 3 is generated in x-1, x cannot be 1

  int cur_x = 2, cur_y = 2;



  //player start from (2,2)
  //player 1 initial chess stays at (0,0),(0,1),(1,0),(1,1)
  //player 2 initial chess stays at (SIZE,SIZE), (SIZE,SIZE-1), (SIZE-1,SIZE),(SIZE-1,SIZE-1)





}
