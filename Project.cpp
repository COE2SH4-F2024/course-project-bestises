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

void DrawScreen(void)
{
    
   int i;
    int j;
    for (i=0;i<9;i++){
        for (j=0;j<18;j++){
            game[i][j]=' ';
        }
    }
    objPos headPos = player.getPlayerPos();
    int playerX = headPos.pos->x;
    int playerY = headPos.pos->y;
    game[playerY][playerX]= snake.getSymbol();
    MacUILib_clearScreen();
    MacUILib_printf("####################       Press P to increase speed, L to decrease. SPACE to exit, Control with WASD\n");
    
    for (i=0;i<9;i++){
        MacUILib_printf("#%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#\n",game[i][0],game[i][1],game[i][2],game[i][3],game[i][4],game[i][5],game[i][6],game[i][7],game[i][8],game[i][9],game[i][10],game[i][11],game[i][12],game[i][13],game[i][14],game[i][15],game[i][16],game[i][17]);
    }

    MacUILib_printf("####################       ");
    MacUILib_printf("board width is %d, height is %d",gMech.getBoardSizeX(),gMech.getBoardSizeY());
    
  
     
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
