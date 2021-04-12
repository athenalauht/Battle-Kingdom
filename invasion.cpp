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

 using namespace std;


 const int SIZE_X = 100;
 const int SIZE_Y = 25;

 void invasion(int map[][100]){
   for (int i = 0; i < SIZE_Y; ++i){

     if ((map[i][2] <= 13) && (map[i][2] >= 10)){
       return 2;
     }
   }

   for (int i = 0; i < SIZE_Y; ++i){

     if ((map[i][SIZE_X - 3] <= 9) && (map[i][SIZE_X - 3] >= 5)){
       return 1;
     }
   }

   return 0;
 }
