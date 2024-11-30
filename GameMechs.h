#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player;  // Forward declaration

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        Food food;
        Player* player;
        bool eat;
        
        int speed;
        char game[9][18];

    public:
        GameMechs();
        GameMechs(int boardX, int boardY, Player* playerRef);
        ~GameMechs(); // is this one needed at all? Why or why not? no arrays do destroy
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() const;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        
        // More methods should be added here
        void increaseSpeed();//nealy added methods for speed of the game
        void decreaseSpeed();
        void delay();
        void clearBoard();
        bool addBoard();
        void drawScreen();
};

#endif