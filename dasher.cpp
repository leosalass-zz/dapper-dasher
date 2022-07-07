#include "raylib.h"
#include <string>
using namespace std;

const int windowWidth{1280};
const int windowHeigth{720};
const Color backgroundColor{WHITE};
const int targetFPS{60};
const float gravityFroce{25}; // 9.8(m/s)/s
const float gravityFrameUpdate{gravityFroce / targetFPS};

int main()
{
    //Initialize the game window
    InitWindow(windowWidth, windowHeigth, "Dapper Dasher");
    
    //character
    const int width{50};
    const int height{80};
    const int groundPos{windowHeigth - height};
    const int jumpVelocity{10};

    float posY{groundPos};
    float velocity{0};
    bool isGrounded{posY >= groundPos};
    bool isMultiJumpEnabled{false};
    int jumpCounter{0};
    int jumpsLimit{3};

    SetTargetFPS(targetFPS);
    while( !WindowShouldClose() ){
        // start drawing
        BeginDrawing();
        ClearBackground(backgroundColor);

        // start game logic
        isGrounded = posY >= groundPos;
        if (isGrounded)
        {
            //grounded
            velocity = 0;
            posY = groundPos;
            jumpCounter = 0;
        }            
        else
        {
            //on air
            velocity += gravityFrameUpdate;
            isMultiJumpEnabled = (jumpCounter < jumpsLimit);
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            if (isGrounded || isMultiJumpEnabled)
            {
                jumpCounter += 1;
                velocity = -jumpVelocity;
                printf_s("jumpCounter: %i \n", jumpCounter);
            }
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