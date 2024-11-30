#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include <random>


GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    loseFlag = false;
    exitFlag = false;
    boardSizeX = 0;
    boardSizeY = 0;
}

GameMechs::GameMechs(int boardX, int boardY, Player* playerRef)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    input = 0;
    score = 0;
    speed = 1;
    loseFlag = false;
    exitFlag = false;
    player = playerRef; //assign member variable player to the argument playerRef
    //Food food = Food();
    eat = false;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
return input;
}

int GameMechs::getScore() const
{
return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag=true;
}

void GameMechs::setInput(char this_input)
{
input = this_input;
}

void GameMechs::clearInput()
{
input = 0;
}

void GameMechs::increaseSpeed()
{
    if (speed < 5){
        speed++;
    }
}

void GameMechs::decreaseSpeed()
{
    if (speed > 1){
        speed--;
    }
}

void GameMechs::delay()
{
    //calculate the delay, which is a negative quadratic based on speed
    //this helps make the changes in speed feel more impactful
    MacUILib_Delay(300000 - speed*speed*10000);
}

void GameMechs::clearBoard()
{
    for (int i = 0; i < boardSizeY; i++) {
        for (int j = 0; j < boardSizeX; j++) {
            game[i][j] = ' '; // Clear all positions
        }
    }
}
bool GameMechs::addBoard()
{   
    eat = false;
    bool first = true;//draw head as another character
    objPosArrayList body = player->getPlayerBody();
    
    game[food.getYPos()][food.getXPos()] = food.getFood();
    for (int i = 0; i < body.getSize(); i++) {
        objPos segment = body.getElement(i);
        if (game[segment.pos->y][segment.pos->x]=='G'){
            setLoseFlag();
            game[segment.pos->y][segment.pos->x] = 'X';
            
            
        }
        else if (first){

            game[segment.pos->y][segment.pos->x]='G';
            first=false;
        }
    else{
        game[segment.pos->y][segment.pos->x] = segment.getSymbol();}
    }
    
    if (game[food.getYPos()][food.getXPos()]=='G'){
        // food.generateFood(7,17);
        while (game[food.getYPos()][food.getXPos()]!=' '){
            food.generateFood(8,18);
            eat = true;
            
            //game[food.getYPos()][food.getXPos()] = food.getFood();
        }
    }
    return eat;
}

void GameMechs::drawScreen()
{
    MacUILib_printf("####################       Press P to increase speed, L to decrease. SPACE to exit, Control with WASD\n");
    for (int i = 0; i < boardSizeY; i++) {
        MacUILib_printf("#");
        for (int j = 0; j < boardSizeX; j++) {
            MacUILib_printf("%c", game[i][j]);
        }
        MacUILib_printf("#\n");
    }
    MacUILib_printf("####################\n");

    MacUILib_printf("Speed: %d, Score: %d\n", speed, score);
}

// More methods should be added here