#include "Food.h"
#include <random>
#include <time.h>
 Food::Food()//int x, int y, char symbol, GameMechs* GMref)
{
    // foodPos.setObjPos(x, y, symbol);
    // mainGameMechsRef = GMref;
    
    foodSymbol = '*';
    eat = false;
    
    x = 5;
    y=5;
    
    first = true;

}

Food::~Food() {
    // No need to delete
}

int Food::getXPos() const {
    // return foodPos;
    return x;
}
 int Food::getYPos() const {
return y;
 }

void Food::eatFood() {
    // Handle food being eaten logic
    // playerRef->grow();
}
 void Food::generateFood(int ymax, int xmax){
    srand(time(0));
    x = rand()%xmax;
    y=rand()%ymax;

 }

 char Food::getFood() const{
    return foodSymbol;
 }

 bool Food::getEatFlag() const{
    return eat;
 }
 void Food::setEatFlagFalse() {
    eat = false;
 }

 void Food::setEatflagTrue(){
    eat = true;
 }
