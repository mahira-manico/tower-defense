#include "MenuView.hpp"
#include <iostream>
#include "raylib.h"

MenuView::MenuView(){
    menuBackgroundTexture =LoadTexture("assets/backgrounds/menuBg.jpg");
    buttonFont =LoadFont("assets/fonts/aldotheapache.ttf");
    playButtonRect    = {540.0f, 250.0f, 200.0f, 50.0f};
    optionsButtonRect = {540.0f, 320.0f, 200.0f, 50.0f};
    creditsButtonRect = {540.0f, 390.0f, 200.0f, 50.0f};
    quitButtonRect    = {540.0f, 460.0f, 200.0f, 50.0f};
    volumeSliderRect  = {540.0f, 350.0f, 200.0f, 20.0f};

    
}

MenuView::~MenuView() {
     UnloadTexture(menuBackgroundTexture);
     UnloadFont(buttonFont);
}

void MenuView::drawMainMenu(WindowContext& context){

    ClearBackground(DARKGRAY);

    DrawTexture(menuBackgroundTexture, 0,0, WHITE);

    DrawText("TOWER DEFENSE", 450, 120, 40, WHITE);

    DrawRectangleRec(playButtonRect, BLUE);
    DrawText("PLAY", playButtonRect.x + 65, playButtonRect.y + 15, 20, WHITE);

    DrawRectangleRec(optionsButtonRect, GRAY);
    DrawText("OPTIONS", optionsButtonRect.x + 55, optionsButtonRect.y + 15, 20, WHITE);

    DrawRectangleRec(creditsButtonRect, LIGHTGRAY);
    DrawText("CREDITS", creditsButtonRect.x + 55, creditsButtonRect.y + 15, 20, DARKGRAY);

    DrawRectangleRec(quitButtonRect, RED);
    DrawText("QUIT", quitButtonRect.x + 55, quitButtonRect.y + 15, 20, WHITE);

}

void MenuView::drawOptionsPanel(WindowContext& context, const int currentVolume){
    ClearBackground(GRAY);
    DrawText("OPTIONS - AUDIO", 480, 150, 30, WHITE);
    DrawRectangleRec(volumeSliderRect, LIGHTGRAY); 
    
    float volumeVisualWidth = (volumeSliderRect.width * currentVolume) / 100.0f;
    DrawRectangle(volumeSliderRect.x, volumeSliderRect.y, volumeVisualWidth, volumeSliderRect.height, GREEN);

    DrawText("Volume :", volumeSliderRect.x - 100, volumeSliderRect.y, 20, WHITE);
    DrawText(TextFormat("%d%%", currentVolume), volumeSliderRect.x + volumeSliderRect.width + 20, volumeSliderRect.y, 20, WHITE);
}

void MenuView::drawCredits(WindowContext& context){
    ClearBackground(GRAY);
    DrawText("DEV CREDITS", 380, 150, 30, WHITE);
    
    DrawText("Developped with love by our team!", 350, 300, 20, LIGHTGRAY);
    DrawText("MAHIRA MANICO", 350, 300, 20, LIGHTGRAY);
    DrawText("ALYA ANNABI", 350, 300, 20, LIGHTGRAY);
    DrawText("MOINA HALIMA ABDOU-DOUKENI", 350, 300, 20, LIGHTGRAY);
    DrawText("ESCAPE to go back to the menu", 420, 500, 16, GRAY);
}