#include "Player.h"
#include "GameMechs.h"


Player::Player()
{
    myDir = STOP;
    playerPos = objPos(0,0,'O');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(playerPos);
    snakeBodySymbol = 'O';
    // more actions to be included
}

void Player::setGmech(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
}

Player::~Player()
{
    // delete any heap members here
    //delete mainGameMechsRef; is this nessesary? is mainGameMechsRef not on stack?
    delete playerPosList;
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
                grow(1);    
                break; 
        }
    }
}

void Player::movePlayer() {
    
    int height = mainGameMechsRef->getBoardSizeY();
    int width = mainGameMechsRef->getBoardSizeX();

    // Update the head position based on direction
    Pos* headPos = playerPos.pos;
    if (myDir == UP) headPos->y = (headPos->y - 1 + height) % height;
    if (myDir == DOWN) headPos->y = (headPos->y + 1) % height;
    if (myDir == LEFT) headPos->x = (headPos->x - 1 + width) % width;
    if (myDir == RIGHT) headPos->x = (headPos->x + 1) % width;

    // Add updated head position to the playerPos list

    //note: the head of the snake being a special symbol is handled in gameMech
    //the player object is only designed to modify and keep track of the position of the body of the snake
    playerPos.symbol = snakeBodySymbol;
    playerPosList->insertHead(playerPos);

    // Remove the tail to maintain the correct length
    if (playerPosList->getSize() > mainGameMechsRef->getScore() + 1) {
        playerPosList->removeTail();
    }
}




void Player::grow(int x) {
    mainGameMechsRef->incrementScore(x);
}

int Player::getsnakesize(){
    return playerPosList->getSize();
}

objPosArrayList Player::getPlayerBody(){
    return *playerPosList;
}
// More methods to be added