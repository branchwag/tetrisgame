#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
   
   while(WindowShouldClose() == false) {

        BeginDrawing();

        EndDrawing();
   }

    CloseWindow();
}
