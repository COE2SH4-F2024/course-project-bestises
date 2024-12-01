#ifndef FOODBIN_H
#define FOODBIN_H


#include "objPos.h"
#include "Player.h"
//this class manages all the foods available

class FoodBin
{
    public:
        FoodBin();//int x, int y, char symbol, GameMechs* GMref);
        ~FoodBin();
        objPosArrayList getFoodPosList() const;
        bool getEatFlag() const;
        void setPlayerRef(Player* PRef);
        void initializeFoodList(int numFoods);
        void setEatflagTrue();
        void setEatFlagFalse();
        int eatFood(objPos food);
        void generateNewFood(char game[9][18], int width, int height, int arrayIndex);

    private:
        // objPos foodPos;
        Player* mainPlayerRef;
        GameMechs* mainGameMechsRef;
        
        char foodSymbol;
        bool eat;
        bool first;

        objPosArrayList foodPosList;

};

#endif