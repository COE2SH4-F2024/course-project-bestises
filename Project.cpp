#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
char game [9][18];
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
objPos snake = objPos(0,0,'@');


int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
    

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
    
    game[0][0]= snake.getSymbol();
    MacUILib_clearScreen();
    MacUILib_printf("####################       Press P to increase speed, L to decrease. SPACE to exit, Control with WASD\n");
    
    for (i=0;i<9;i++){
        MacUILib_printf("#%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#\n",game[i][0],game[i][1],game[i][2],game[i][3],game[i][4],game[i][5],game[i][6],game[i][7],game[i][8],game[i][9],game[i][10],game[i][11],game[i][12],game[i][13],game[i][14],game[i][15],game[i][16],game[i][17]);
    }

    MacUILib_printf("####################       ");
    
  
     
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
