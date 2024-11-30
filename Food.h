#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "Player.h"
//this class corresponds to each individual piece of food

class Food
{
    public:
        Food(int x, int y, char symbol, GameMechs* GMref);
        ~Food();
        objPos getPos() const;
        void eatFood();

    private:
        objPos foodPos;
        Player* playerRef;
        GameMechs* mainGameMechsRef;

};

#endif