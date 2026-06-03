#include "raylib.h"
#include "MenuView.hpp"

struct WindowContext{

};

int main() {

    InitWindow(1280, 720, "Test en direct de mon Menu");
    SetTargetFPS(60); 

    MenuView menuView;
    WindowContext dummyContext;

    while (!WindowShouldClose()) {
        BeginDrawing();
            menuView.drawMainMenu(dummyContext); 
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}