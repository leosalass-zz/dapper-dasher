#include "raylib.h"

const int windowWidth{1280};
const int windowHeigth{720};
const Color backgroundColor{WHITE};
const int targetFPS{60};

int main()
{

    InitWindow(windowWidth, windowHeigth, "Dapper Dasher");
    SetTargetFPS(targetFPS);

    while( !WindowShouldClose() ){
        BeginDrawing();
        ClearBackground(backgroundColor);
        EndDrawing();
    }
    
    CloseWindow();
}