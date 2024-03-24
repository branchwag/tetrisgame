#include <iostream>
#include <raylib.h>
// #include "grid.h"
// #include "blocks.cpp"
#include "game.h"

using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main () {

    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    //Grid grid = Grid();
    // grid.grid[0][0] = 1;
    // grid.grid[3][5] = 4;
    // grid.grid[17][8] = 7;
    //grid.Print();

    //LBlock block = LBlock(); 
    //TBlock block = TBlock();
    //block.Move(4,3); 
   
   while(WindowShouldClose() == false) {

        game.HandleInput();
        if (EventTriggered(0.4)){
            game.MoveBlockDown();
        }
        //game.MoveBlockDown();
        BeginDrawing();
        ClearBackground(darkBlue);
        //grid.Draw();
        //block.Draw();
        game.Draw();

        EndDrawing();
   }

    CloseWindow();
}
