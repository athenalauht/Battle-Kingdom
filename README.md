# COMP2113_Project
##Group 13:\
##Group members: Chan Chi Lok Max, Lau Hiu Tung Athena

The game has 2 game mode. Player vs NPC or player vs Player.

#####**Description**
A 25 x 25 map will be generated. There will be two castles in each of the diagonal corner. Random paths will be created which connects the castle of the first player to that of the second player. Players have to compete with each other to gain full control of the kingdom.

#####**Game Rule**
Each player will have 4 chess pieces to deploy. Initially, all pieces will remain inside the player’s castle. Players will take turns to move the pieces. In each round, player will choose 1 piece and decide the direction (North, East, South, West) and the number of steps (1, 2, 3, 4, 5) to move. However, the piece can only walk straight within a turn (i.e. the player can only walk horizontally or vertically)
However, the piece is forced to stop when it encounters a crossroad (i.e. if there is a crossroad 3 steps from the piece in the south direction, the maximum steps that the piece can move along the south direction is 3).
After moving the piece, if there is an enemy piece along a vertical path or a horizonal path, the player can choose whether to attack or not.

The four pieces have their own identity, namely, Emperor, Knight, Soldier and Assassin.

The battle Rule is listed as follows:
1.	Emperor channels power from the core of the sun, he can kill Knight and Soldier ruthlessly
2.	Knight is the apprentice of the combat master, he can kill Soldier and Assassin gracefully
3.	Soldier is equipped with night goggles, he can spot and kill Assassin with full effort
4.	Assassin hides in the dark, he can sneak and kill the emperor without a sound

If pieces with same status are encountered, the attacker wins.
The identity of player 1’s own pieces will be revealed when in player 1’s turn and return to unknown when the turn is ended, same case for player 2. Therefore, the identity of the enemy’s pieces are unknown. Players have to make the decision on whether to attack or not as the battle result depends on the piece’s identity.

Furthermore, the path contains 2 hidden teleporters, when any of the pieces step into one of the teleporter, it will be transported to the other end of the teleporter (i.e. when a chess steps into (3,5) and instantly being transported to (7,4), both player should realize the actual location of the two teleporters). If the other end of the teleporter is occupied by a piece, the chess will not be teleported when it steps into the teleporter. The location of the two teleporters will change after being used for 3 times.

The game will terminate in either situation
Case 1: All chess pieces are being killed. When a chess piece is being killed, the screen
        display “player i’s Emperor is killed”
Case 2: Any chess piece of the enemy enters your base

Players can choose to retrieve previously saved game progress or to start a new game.

#####**Features**

Element 1: Generation of random game sets or events
•	The initial path connecting the two castle are randomly generated
•	The teleporter in the path is randomly generated

Element 2: Data structures for storing game status
•	The map will be saved by a char array which stores the path and the location of the chess, with * indicating the path.
•	Use int array to record the lives of each of the chess pieces
•	string p1_name is to store the player’s name


Element 3: Dynamic memory management
•	Use int tel_usage to record the number of usage of the teleporter ( i = i+1, when the teleporter is being steped on). Resets when i = 3.
•	int pos_p1_e_x  and  int pos_p1_e_y will be used repeatedly to store the position (x,y) of emperor of player 1, same case for the other chess pieces
•	int tele_x and int tele_y will be used to store the current position of the teleporter

Element 4: File input/output (e.g., for loading/saving game status)
•	Use pos_p1_e_x.txt to store the position of emperor of player one in each turn
•	Use map.txt to store the map
•	Use tele.txt to store the position of the teleport in previous turns to prevent same teleporter position being generated on consecutive turns
•	The input are to be saved for users to retrieve the previous game progress


Element 5: Program codes in multiple files
•	main.cpp includes the selection of game modes and all the required header files
•	map_init.h contains functions for creating random initialization of the map
•	player_status.h contains functions for storing the path and location of the chess
•	progress.h contains functions to guide player’s action by displaying corresponding information for asking input in each round
