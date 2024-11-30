#include "GameMechs.h"
#include "Player.h"

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
    loseFlag = false;
    exitFlag = false;
    player = playerRef; // Correctly assign to the member variable
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
    speed++;
}

void GameMechs::decreaseSpeed()
{
    speed--;
}

void GameMechs::clearBoard()
{
    for (int i = 0; i < boardSizeY; i++) {
        for (int j = 0; j < boardSizeX; j++) {
            game[i][j] = ' '; // Clear all positions
        }
    }
}
void GameMechs::addSnake()
{
    bool first = true;//draw head as another character
    objPosArrayList body = player->getPlayerBody();
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
}

void GameMechs::drawScreen()
{
    MacUILib_printf("####################       Press P to increase speed, L to decrease. SPACE to exit, Control with WASD %d\n",player->getPlayerBody().getSize());
    for (int i = 0; i < boardSizeY; i++) {
        MacUILib_printf("#");
        for (int j = 0; j < boardSizeX; j++) {
            MacUILib_printf("%c", game[i][j]);
        }
        MacUILib_printf("#\n");
    }
    MacUILib_printf("####################\n");

    MacUILib_printf("Score: %d\n", score);
}

// More methods should be added here