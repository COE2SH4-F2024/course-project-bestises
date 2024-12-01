#include "GameMechs.h"
#include "Player.h"
#include "FoodBin.h"
#include <random>

GameMechs::GameMechs(int boardX, int boardY, Player* playerRef)
{
    srand(time(0));
    boardSizeX = boardX;
    boardSizeY = boardY;
    input = 0;
    score = 0;
    numFoods = 3;
    speed = 1;
    loseFlag = false;
    exitFlag = false;
    player = playerRef; //assign member variable player to the argument playerRef
    clearBoard(); //initialize game
    foodBin.setPlayerRef(playerRef);//provide player ref to foodbin so it can change length of snake
    foodBin.setGMechRef(this);
    foodBin.initializeFoodList(numFoods);

    for (int i = 0; i < numFoods; i++){
        foodBin.generateNewFood(game, boardSizeX,boardSizeY,i);
    }
    foodBin.generateNewFood(game, boardSizeX,boardSizeY,0);
    foodBin.generateNewFood(game, boardSizeX,boardSizeY,2);
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
void GameMechs::checkCollision()
{
    //checks the win/loss of the player
    //note: MUST BE CALLED AFTER THE SNAKE IS ADDED TO GAME

    //check collision with self
    objPos head = player->getPlayerBody().getElement(0);
    int x = head.pos->x;
    int y = head.pos->y;
    char symbol = game[y][x];
    if (symbol=='O'){
        loseFlag = true;
        symbol = 'X'; //show X to indicate dead       
    }
    else if (symbol!=' '&&symbol!='G'){ //if not the head and not an empty space, must be food!!
        int index = foodBin.eatFood(objPos(x, y, symbol));
        foodBin.generateNewFood(game, boardSizeX,boardSizeY,index);
        game[y][x] = 'G';
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
void GameMechs::addFood()
{   
    objPosArrayList foodArrayList = foodBin.getFoodPosList();

    for (int i = 0; i < foodArrayList.getSize();i++){
        objPos food = foodArrayList.getElement(i);
        game[food.pos->y][food.pos->x] = food.getSymbol();
    }
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
    /*
    for (int i = 0; i < foodBin.getFoodPosList().getSize(); i++) {
        objPos food = foodBin.getFoodPosList().getElement(i);
        printf("x=%d, y=%d, symbol = %c\n", food.pos->x, food.pos->y, food.getSymbol());
    }
    */
}

void GameMechs::setWinFlag(){
    winFlag=true;
}

bool GameMechs::getWinFlag(){
    return winFlag;
}

// More methods should be added here