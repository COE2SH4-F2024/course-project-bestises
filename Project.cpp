#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

char game [9][18];
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
objPos snake = objPos(0,0,'@');
GameMechs gMech = GameMechs(18,9);
Player player = Player(&gMech);


int main(void)
{

    Initialize();

    while(gMech.getExitFlagStatus() == false)  
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
    // Step 1: Clear the board
    for (int i = 0; i < gMech.getBoardSizeY(); i++) {
        for (int j = 0; j < gMech.getBoardSizeX(); j++) {
            game[i][j] = ' '; // Clear all positions
        }
    }

    // Step 2: Draw the snake
    objPosArrayList body = player.getPlayerBody();
    for (int i = 0; i < body.getSize(); i++) {
        objPos segment = body.getElement(i);
        game[segment.pos->y][segment.pos->x] = segment.getSymbol();
    }

    // Step 3: Render the board
    MacUILib_clearScreen();
    MacUILib_printf("####################       Press P to increase speed, L to decrease. SPACE to exit, Control with WASD\n");
    for (int i = 0; i < gMech.getBoardSizeY(); i++) {
        MacUILib_printf("#");
        for (int j = 0; j < gMech.getBoardSizeX(); j++) {
            MacUILib_printf("%c", game[i][j]);
        }
        MacUILib_printf("#\n");
    }
    MacUILib_printf("####################\n");
    MacUILib_printf("Score: %d   Speed: %d\n", gMech.getScore(), gMech.getBoardSizeX());
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    

    MacUILib_uninit();
}
