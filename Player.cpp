#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos = objPos(0,0,'@');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(playerPos);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    //delete mainGameMechsRef;
    //delete playerPosList;
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
            case 'o':
                grow();    
                break; 
}}}

void Player::movePlayer() {
    int height = mainGameMechsRef->getBoardSizeY();
    int width = mainGameMechsRef->getBoardSizeX();

    // Update the head position based on direction
    Pos* headPos = playerPos.pos;
    if (myDir == UP) headPos->y = (headPos->y - 1 + height) % height;
    if (myDir == DOWN) headPos->y = (headPos->y + 1) % height;
    if (myDir == LEFT) headPos->x = (headPos->x - 1 + width) % width;
    if (myDir == RIGHT) headPos->x = (headPos->x + 1) % width;

    // Add updated head position to the list
    playerPos.symbol = '@';
    playerPosList->insertHead(playerPos);

    // Remove the tail to maintain the correct length
    if (playerPosList->getSize() > mainGameMechsRef->getScore() + 1) {
        playerPosList->removeTail();
    }
}




void Player::grow() {
    mainGameMechsRef->incrementScore();
}

int Player::getsnakesize(){
    return playerPosList->getSize();
}

objPosArrayList Player::getPlayerBody(){
    return *playerPosList;
}
// More methods to be added