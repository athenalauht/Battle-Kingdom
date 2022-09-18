# Battle Kingdom

## **Description**

The game is a Player vs Player game.

A 100 x 25 map will be generated. There will be two castles in each of the diagonal corner. Random paths will be created which connects the castle of the first player to that of the second player. Players have to compete with each other to gain full control of the kingdom.

## **Game Rule**
Each player will have 4 chess pieces to deploy. Initially, all pieces will remain inside the player’s castle. Players will take turns to move the pieces. Players are not supposed to look at the screen when another is playing to prevent knowing the opponent's chess identities. In each round, player will choose 1 piece and decide the direction (North, East, South, West) and the number of steps to move. However, the piece can only walk straight within a turn (i.e. the player can only walk horizontally or vertically). The piece is forced to stop when it encounters a crossroad (i.e. if there is a crossroad 3 steps from the piece in the south direction, the maximum steps that the piece can move along the south direction is 3).
After moving the piece, if there is an enemy piece along a vertical path or a horizontal path, the player can choose whether to attack or not.

The four pieces have their own identity, namely, Emperor, Knight, Soldier and Assassin.

The battle Rule is listed as follows:
1.	Emperor channels power from the core of the sun, he can kill Knight and Soldier ruthlessly
2.	Knight is the apprentice of the combat master, he can kill Soldier and Assassin gracefully
3.	Soldier is equipped with night goggles, he can spot and kill Assassin with full effort
4.	Assassin hides in the dark, he can sneak and kill the emperor without a sound

If pieces with same identity are encountered, the attacker wins.\
The identity of player 1’s own pieces will be revealed when in player 1’s turn and hidden when the turn is ended, same case for player 2. Therefore, the identity of the enemy’s pieces are unknown. Players have to make the decision on whether to attack or not as the battle result depends on the piece’s identity.

Furthermore, the path contains 2 teleporters, when any of the pieces step into one of the teleporter, it will be transported to the other end of the teleporter (i.e. when a chess steps into (3,5), it will instantly being transported to (7,4)).

The game will terminate in either situation\
Case 1: All chess pieces are being killed.\
Case 2: Any chess piece of the enemy enters your base.

Players can choose to retrieve previously saved game progress or to start a new game.

## **Features**

**Element 1: Generation of random game sets or events**\
•	The initial path connecting the two castle are randomly generated\
•	The teleporter in the path is randomly generated

**Element 2: Data structures for storing game status**\
•	A int array will store the location of the path, location of the chess, the location of the teleport
•	The struct "Profile" is to store the player’s chess location


**Element 3: Dynamic memory management**\
•	int * current_x and  int * current_y will be used repeatedly to store the position (x,y) of the current moving chess pieces\
•	pointers are used for checking the possibility of movement of the chess


**Element 4: File input/output (e.g., for loading/saving game status)**\
•	Use p1.txt to save the position of the chess of player 1 in each turn\
•	Use p2.txt to save the position of the chess of player 2 in each turn\
•	Use path.txt to store the path\
•	Use count.txt to save the turn of the player\
•	Use teleport.txt to save the position of the teleport\
•	Use functions in retrieve.cpp to retrieve the previous game progress\


**Element 5: Program codes in multiple files**\
•	main.cpp includes the selection of game modes and all the required header files\
•	map.h contains functions for creating random initialization of the map\
•	save.h contains functions for saving the game progress\
•	user_interface.h contains functions to guide player’s action by displaying corresponding information for asking input and coordinate the chess movement\
•	teleport.h contains functions for creating teleporters\
•	retrieve.h contains functions for retrieving previous game data\
•	display.h contains functions for displaying game graphics\
•	battle_result.h contains functions for outputting the winner between the attack chess and defense chess\
•	mystruct.h contains the struct for the player profile
