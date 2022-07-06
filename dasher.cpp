#include "raylib.h"
#include <string>
using namespace std;

const int windowWidth{1280};
const int windowHeigth{720};
const Color backgroundColor{WHITE};
const int targetFPS{60};
const float gravityFroce{20}; // 9.8(m/s)/s
const float gravityFrameUpdate{gravityFroce / targetFPS};

int main()
{
    //Initialize the game window
    InitWindow(windowWidth, windowHeigth, "Dapper Dasher");
    
    //character
    const int width{50};
    const int height{80};
    const int groundPos{windowHeigth - height};
    const int jumpForce{10};

    float posY{groundPos};
    float velocity{0};

    SetTargetFPS(targetFPS);
    while( !WindowShouldClose() ){
        // start drawing
        BeginDrawing();
        ClearBackground(backgroundColor);
        
        // start game logic
        if (posY >= groundPos)
        {
            //grounded
            velocity = 0;
        }                
        else
        {
            //on air
            velocity += gravityFrameUpdate;
        }

        if (IsKeyDown(KEY_SPACE))
        {
            velocity = -jumpForce;
        }

        posY += velocity;
        //end game logic

        //printf_s("velocity: %i \n", velocity);
        //printf_s("posY: %i \n", posY);
        //printf_s("groundPos: %i \n", groundPos);

        DrawRectangle((windowWidth / 2) - (width / 2), posY, width, height, BLUE);

        //end drawing
        EndDrawing();
    }
    
    CloseWindow();
}