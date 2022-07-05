#include "raylib.h"

int windowWidth{1280};
int windowHeigth{720};
Color backgroundColor{WHITE};

int main()
{

    InitWindow(windowWidth, windowHeigth, "Dapper Dasher");
    SetTargetFPS(60);

    while( !WindowShouldClose() ){
        BeginDrawing();
        ClearBackground(backgroundColor);
        EndDrawing();
    }
    
    CloseWindow();
}