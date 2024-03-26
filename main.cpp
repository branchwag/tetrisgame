#include <iostream>
#include <raylib.h>
// #include "grid.h"
// #include "blocks.cpp"
#include "game.h"
#include "colors.h"

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

    //Color darkBlue = {44, 44, 127, 255};
    //InitWindow(300, 600, "Tetris");
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

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
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver){
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 +(170-textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();

        EndDrawing();
   }

    CloseWindow();
}
