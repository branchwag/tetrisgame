#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

using namespace std;

int main () {

    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    // grid.grid[0][0] = 1;
    // grid.grid[3][5] = 4;
    // grid.grid[17][8] = 7;
    grid.Print();

    //LBlock block = LBlock(); 
    TBlock block = TBlock(); 
   
   while(WindowShouldClose() == false) {

        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();

        EndDrawing();
   }

    CloseWindow();
}
