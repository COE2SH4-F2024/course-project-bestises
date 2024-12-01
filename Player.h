#ifndef PLAYER_H
#define PLAYER_H

#include "objPos.h"
#include "objPosArrayList.h"

class GameMechs; //avoid circular dependency

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state        
        Player();
        ~Player();
        objPosArrayList getPlayerBody();
        objPos getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir(char input);
        void movePlayer();
        void grow(int amount);
        void shorten(int amount);
        int getsnakesize();
        void setGmech(GameMechs* thisGMRef);

        // More methods to be added here

    private:
        objPosArrayList* playerPosList;
        objPos playerPos; // Upgrade this in iteration 3.       
        enum Dir myDir;
        char snakeBodySymbol;
        int currentSnakeLength; //this keeps track of how long the snake should be

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        
};

#endif