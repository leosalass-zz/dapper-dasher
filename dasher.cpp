#include "raylib.h"

const int windowWidth{1280};
const int windowHeigth{720};
const Color backgroundColor{WHITE};
const int targetFPS{60};

int main()
{
    //Initialize the game window
    InitWindow(windowWidth, windowHeigth, "Dapper Dasher");
    
    //character
    const int width{50};
    const int height{80};
    int posY{windowHeigth - height};
    int velocity{0};

    SetTargetFPS(targetFPS);
    while( !WindowShouldClose() ){
        // start drawing
        BeginDrawing();
        ClearBackground(backgroundColor);

        posY += velocity;

        if(IsKeyDown(KEY_SPACE)){
            velocity = -10;
        }
        DrawRectangle((windowWidth / 2) - (width / 2), posY, width, height, BLUE);

        //end drawing
        EndDrawing();
    }
    
    CloseWindow();
}