#include "FoodBin.h"
#include <random>
#include <time.h>

FoodBin::FoodBin()//int x, int y, char symbol, GameMechs* GMref)
{
    // foodPos.setObjPos(x, y, symbol);
   foodSymbol = '*';
   eat = false;
   first = true;

}

FoodBin::~FoodBin() {
    // No need to delete
}

void FoodBin::setPlayerRef(Player* PRef)
{
   //this method sets the player ref and initializes things that require the player ref
   mainPlayerRef = PRef;

   /*
   //since the generate new food function replaces elements in the array list, must first initialize the array list
   objPos placeHolder;
   for (int i = 0; i < 3; i++){
      foodPosList.insertHead(placeHolder);
      generateNewFood()
   }
   */

}

void FoodBin::initializeFoodList(int numFoods){
   //this must be called before food can be generated
   objPos placeHolder;
   for (int i = 0; i < numFoods; i++){
      foodPosList.insertHead(placeHolder);
   }
}

int FoodBin::eatFood(objPos food) {
   // Handle food being eaten logic
   //returns index of food eaten
   switch (food.getSymbol())
   {
   case '*':
      //normal food, grows by one
      mainPlayerRef->grow(1);
      break;
   
   case 's':
      //special food that shorttens by 2 and increases score by 2
      mainPlayerRef->shorten(2);
      break;
   case 'S':
      //super special food that resets the length of the snake and is worth 3 points
      mainPlayerRef->shorten(mainPlayerRef->getsnakesize());
   }

   //find index of food
   for (int i = 0; i < foodPosList.getSize(); i++) {
      objPos foodInList = foodPosList.getElement(i);
      if (food.pos->x == foodInList.pos->x && food.pos->y == foodInList.pos->y) {
         return i; // Found the index of the eaten food
      }
   }
}
void FoodBin::generateNewFood(char game[9][18], int width, int height, int arrayIndex)
{  
   //generates a piece of food in an empty spot
   int foodX,foodY;
   char symbol;
   do{
      foodX = rand()%width;
      foodY = rand()%height;
   }
   while (game[foodY][foodX]!=' '); //keep generating coordinates until [y][x] is a blank space

   //decide on type of food
   int randVal = rand()%10;

   if(randVal < 7){
      symbol = '*'; //common food with 7/10 chance
   }else if (randVal < 9)
   {
      symbol = 's'; //rare food with 2/10 chance
   }else{
      symbol = 'S'; //super rare food with 1/10 chance
   }
   //put into array list of foods
   foodPosList.replaceElement(arrayIndex, objPos(foodX, foodY, symbol));
   
}

objPosArrayList FoodBin::getFoodPosList() const{
   return foodPosList;
}

bool FoodBin::getEatFlag() const{
   return eat;
}
void FoodBin::setEatFlagFalse() {
   eat = false;
}

void FoodBin::setEatflagTrue(){
   eat = true;
}

