#include "Food.h"

Food::Food(int x, int y, char symbol, GameMechs* GMref)
{
    foodPos.setObjPos(x, y, symbol);
    mainGameMechsRef = GMref;
}

Food::~Food() {
    // No need to delete foodPos since on the stack
}

objPos Food::getPos() const {
    return foodPos;
}

void Food::eatFood() {
    // Handle food being eaten logic
    playerRef->grow();
}