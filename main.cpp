#include "raylib.h"
#include "MenuView.hpp"

int main() {
    // On ouvre une fenêtre de la taille de ton choix
    InitWindow(1280, 720, "Test en direct de mon Menu");
    SetTargetFPS(60); // 60 images par seconde

    MenuView menuView;

    // Boucle de rendu en direct
    while (!WindowShouldClose()) {
        BeginDrawing();
            
            // C'est ici que ta fonction magique dessine !
            menuView.drawMainMenu(); 
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}