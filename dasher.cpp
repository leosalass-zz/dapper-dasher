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
    Texture2D scarfy = LoadTexture("./textures/scarfy.png");
    
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;

    const int groundPos{windowHeigth - scarfyRec.height};

    Vector2 scarfyPos;
    scarfyPos.x = groundPos;
    scarfyPos.y = windowHeigth - scarfyRec.height;

    const int jumpVelocity{10};
    float velocity{0};
    bool isGrounded{scarfyPos.y >= groundPos};
    bool isMultiJumpEnabled{false};
    int jumpCounter{0};
    int jumpsLimit{2};

    SetTargetFPS(targetFPS);
    while( !WindowShouldClose() ){
        // start drawing
        BeginDrawing();
        ClearBackground(backgroundColor);

        // start game logic
        isGrounded = scarfyPos.y >= groundPos;
        if (isGrounded)
        {
            //grounded
            velocity = 0;
            scarfyPos.y = groundPos;
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

        scarfyPos.y += velocity;
        //end game logic

        //printf_s("velocity: %i \n", velocity);
        //printf_s("posY: %i \n", posY);
        //printf_s("groundPos: %i \n", groundPos);

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        //end drawing
        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();
}