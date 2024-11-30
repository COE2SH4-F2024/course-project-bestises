#include "Food.h"
#include <random>
#include <time.h>
 Food::Food()//int x, int y, char symbol, GameMechs* GMref)
{
    // foodPos.setObjPos(x, y, symbol);
    // mainGameMechsRef = GMref;

    options = new char[50];
    for (int i = 0; i<45;i++){
        options[i] = '*';
    }
    for (int i = 45; i<50;i++){
        options[i] = '!';
    }
    
    foo = '*';
    eat = false;
    
    x = 5;
    y=5;
    
    first = true;

}

Food::~Food() {
    // No need to delete foodPos since on the stack
    delete[] options;
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
    foo = options[rand()%50];

 }

 char Food::getFood() const{
    return foo;
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
