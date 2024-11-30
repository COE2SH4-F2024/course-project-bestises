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

    while(!gMech.getExitFlagStatus()&&!gMech.getLoseFlagStatus())  
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
    bool eat = false;
    gMech.clearBoard();
    eat = gMech.addBoard();
    if (eat){
        player.grow();
    }
    MacUILib_clearScreen();
    gMech.drawScreen();

    /*
    // Step 1: Clear the board
    for (int i = 0; i < gMech.getBoardSizeY(); i++) {
        for (int j = 0; j < gMech.getBoardSizeX(); j++) {
            game[i][j] = ' '; // Clear all positions
        }
    }

    // Step 2: Draw the snake
    bool first = true;//draw head as another character
    objPosArrayList body = player.getPlayerBody();
    for (int i = 0; i < body.getSize(); i++) {
        objPos segment = body.getElement(i);
        if (game[segment.pos->y][segment.pos->x]=='G'){
            gMech.setLoseFlag();
            game[segment.pos->y][segment.pos->x] = 'X';
            
            
        }
        else if (first){
            game[segment.pos->y][segment.pos->x]='G';
            first=false;
        }
    else{
        game[segment.pos->y][segment.pos->x] = segment.getSymbol();}
    }

    // Step 3: Render the board
    MacUILib_clearScreen();
    
    MacUILib_printf("####################       Press P to increase speed, L to decrease. SPACE to exit, Control with WASD %d\n",body.getSize());
    for (int i = 0; i < gMech.getBoardSizeY(); i++) {
        MacUILib_printf("#");
        for (int j = 0; j < gMech.getBoardSizeX(); j++) {
            MacUILib_printf("%c", game[i][j]);
        }
        MacUILib_printf("#\n");
    }
    MacUILib_printf("####################\n");

    MacUILib_printf("Score: %d\n", gMech.getScore());
    */
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    if (gMech.getLoseFlagStatus())
    MacUILib_printf("you lose loser");
    //MacUILib_clearScreen();    
   // free(game);
    MacUILib_uninit();
}
