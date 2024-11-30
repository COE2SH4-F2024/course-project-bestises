#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include <random>
#include <time.h>

using namespace std;

#define DELAY_CONST 100000

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
objPos snake = objPos();
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
    player.movePlayer();
}

void DrawScreen(void) {
    int eat = 0;
    gMech.clearBoard();
    eat = gMech.addBoard();
    if (eat==1){
        player.grow(1);
    }
    if (eat==2){
        player.grow(2);
        
    }
    if(gMech.getScore()==161)
    gMech.setWinFlag();
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
    MacUILib_printf("you lose loser");
    if (gMech.getWinFlag())
    MacUILib_printf("you win Winner %d Your Score is: ",gMech.getScore());
    //MacUILib_clearScreen();    
   // free(game);
    MacUILib_uninit();
}
