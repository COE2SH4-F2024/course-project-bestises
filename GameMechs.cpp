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
    eat = 0;
    winFlag=false;
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

void GameMechs::incrementScore(int x)
{
    score+=x;
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
void GameMechs::checkGameState()
{
    //checks the win/loss of the player
    //note: MUST BE CALLED AFTER THE SNAKE IS ADDED TO GAME

    //check collision
    objPos head = player->getPlayerBody().getElement(0); 
    if (game[head.pos->y][head.pos->x]=='O'){
            loseFlag = true;
            game[head.pos->y][head.pos->x] = 'X'; //show X to indicate dead       
    }

    //check win condiction
    if(score>160){
        winFlag = true; //you win at max score
    }

}

void GameMechs::addSnake()
{   
    //detects collision and adds the snake to game[][]
    //also 
    objPosArrayList body = player->getPlayerBody();
    for (int i = 0; i < body.getSize(); i++) {
        objPos segment = body.getElement(i); //access each segment of snake
        
        if (i == 0){
        //for the first element, add 'G', the head of the snake
            game[segment.pos->y][segment.pos->x]='G';
        }else{
        //add rest of snake
            game[segment.pos->y][segment.pos->x] = segment.getSymbol();
        }
    }

}
bool GameMechs::addBoard()
{   
    eat = 0;
    bool first = true;//draw head as another character
    //objPosArrayList body = player->getPlayerBody();
    
    game[food.getYPos()][food.getXPos()] = food.getFood();
    addSnake();
    checkGameState();
    
    
    if (game[food.getYPos()][food.getXPos()]=='G'){
        // food.generateFood(7,17);
        if (food.getFood()=='*')
            eat= 1;
        if (food.getFood()=='!')
            eat = 2;
        while (game[food.getYPos()][food.getXPos()]!=' '){
            food.generateFood(8,19);
            
            
            
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

void GameMechs::setWinFlag(){
    winFlag=true;
}

bool GameMechs::getWinFlag(){
    return winFlag;
}

// More methods should be added here