#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include <random>
#include <time.h>

using namespace std;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
Player player = Player();
GameMechs gMech = GameMechs(18,9,&player);


int main(void)
{

    Initialize();

    while(!gMech.getExitFlagStatus()&&!gMech.getLoseFlagStatus()&&!gMech.getWinFlag())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    
    MacUILib_clearScreen();

    player.setGmech(&gMech);
    srand(time(0));
    

}

void GetInput(void)
{
    if (MacUILib_hasChar() != 0){
        char input = MacUILib_getChar();
        player.updatePlayerDir(input);
    }
}

void RunLogic(void)
{ 
    player.updatePlayer();
}

void DrawScreen(void) {
    
    gMech.clearBoard();
    gMech.addSnake();
    gMech.addFood();
    gMech.checkCollision();
    MacUILib_clearScreen();
    gMech.drawScreen();
}


void LoopDelay(void)
{
    gMech.delay();
}


void CleanUp(void)
{
    if (gMech.getLoseFlagStatus())
        MacUILib_printf("You lose loser");
    if (gMech.getWinFlag())
        MacUILib_printf("You win Winner. Your Score is: %d",gMech.getScore());
    MacUILib_uninit();
}
