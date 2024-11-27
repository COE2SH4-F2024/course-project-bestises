#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
}

objPos Player::getPlayerPos() const
{
    //mainGameMechsRef->
    return playerPos;
}

void Player::updatePlayerDir(char input)
{
        // PPA3 input processing logic
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;

            case 'w':
                if (myDir != DOWN){
                    myDir = UP;
                }
                break;
            
            case 'a':
                if (myDir !=RIGHT){
                    myDir = LEFT;}
                break;
            
            case 's':
                if (myDir !=UP){
                    myDir = DOWN;
                }
                break;
            case 'd':
                if (myDir != LEFT){
                    myDir = RIGHT;
                }
                break;
            case 'p':
                mainGameMechsRef->increaseSpeed();
                break;
            case 'l':
                mainGameMechsRef->decreaseSpeed();
                break;     
}}}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int height = mainGameMechsRef->getBoardSizeY();
    int width = mainGameMechsRef->getBoardSizeX();
    Pos* pos = playerPos.pos;

    if (myDir == UP){
        pos->y = ((pos->y + height) - 1) % (height); //+height % hright effectively accounts for negative mod
    }

    if (myDir == LEFT){
        pos->x = ((pos->x + width) - 1) % (width);
    }

    if (myDir == DOWN){
        pos->y = (pos->y + 1)% (height);
    }

    if (myDir == RIGHT){
        pos->x = (pos->x + 1)% (width);
    }
    void insertHead(objPos playerPos);//insert the head of snake at the new position
    mainGameMechsRef->incrementScore(); //increment moves
}

// More methods to be added