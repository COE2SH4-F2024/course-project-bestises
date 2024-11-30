#ifndef FOOD_H
#define FOOD_H


#include "objPos.h"
#include "Player.h"
//this class corresponds to each individual piece of food

class Food
{
    public:
        Food();//int x, int y, char symbol, GameMechs* GMref);
        ~Food();
        int getXPos() const;
        int getYPos() const;
        char getFood() const;
        bool getEatFlag() const;
        void setEatflagTrue();
        void setEatFlagFalse();
        void eatFood();
        void generateFood(int y, int x);

    private:
        // objPos foodPos;
        // Player* playerRef;
        // GameMechs* mainGameMechsRef;
        
        char* options;
        int x;
        int y;
        char foo;
        bool eat;
        bool first;

};

#endif