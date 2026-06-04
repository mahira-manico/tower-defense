#include "MenuView.hpp"
#include <iostream>
#include "raylib.h"

static Vector2 getTextPos(Rectangle rect, const char* text, Font font, float fontSize, float spacing){
    Vector2 textSize = MeasureTextEx(font, text, fontSize, spacing);
    return {
    rect.x + (rect.width - textSize.x) / 2.0f,
    rect.y + (rect.height - textSize.y) / 2.0f};

};
MenuView::MenuView(){   //constructor for MenuView
    menuBackgroundTexture = LoadTexture("assets/backgrounds/menuBg.png");
    if(menuBackgroundTexture.id==0){   //Security if it doesn't load
        std::cerr << "Error: unable to load assets/backgrounds/menuBg.png";
    }

    buttonFont = LoadFont("assets/fonts/aldotheapache.ttf");
    if (buttonFont.texture.id == 0) {  //Security if it doesn't load
        std::cerr << "Error: unable to load assets/fonts/aldotheapache.ttf";
    }

    playButtonRect    = {540.0f, 250.0f, 200.0f, 50.0f};   //Buttons placements
    optionsButtonRect = {540.0f, 320.0f, 200.0f, 50.0f}; 
    creditsButtonRect = {540.0f, 390.0f, 200.0f, 50.0f};
    quitButtonRect    = {540.0f, 460.0f, 200.0f, 50.0f};
    volumeSliderRect  = {540.0f, 350.0f, 200.0f, 20.0f};
}

MenuView::~MenuView() {   //Deconstructor to empty the memory
     UnloadTexture(menuBackgroundTexture);
     UnloadFont(buttonFont);
}

void MenuView::drawMainMenu(WindowContext& context){

    ClearBackground(DARKGRAY);

     Rectangle srcRect={  //get the source
        0.0f,0.0f, (float)menuBackgroundTexture.width, (float)menuBackgroundTexture.height
    };

    Rectangle destRect={ //get the destination
        0.0f,0.0f, (float)GetScreenWidth(),(float)GetScreenHeight()
    };
 
    if (menuBackgroundTexture.id != 0) {
        DrawTexturePro(menuBackgroundTexture, srcRect, destRect, {0.0f, 0.0f}, 0.0f, WHITE);
    }
    Vector2 titleSize = MeasureTextEx(buttonFont, "TOWER DEFENSE", 100.0f, 1.0f);
    Vector2 titlePos = { (GetScreenWidth() - titleSize.x) / 2.0f, 120.0f }; 
    DrawTextEx(buttonFont, "TOWER DEFENSE", titlePos, 100.0f, 1.0f, BLACK);

    DrawRectangleRec(playButtonRect, BLUE);
    Vector2 playTextPos=getTextPos(playButtonRect, "PLAY", buttonFont, 20.0f, 1.0f);
    DrawTextEx(buttonFont,"PLAY", playTextPos, 20.0f, 1.0f, BLACK);

    DrawRectangleRec(optionsButtonRect, BLUE);
    Vector2 optionTextPos=getTextPos(optionsButtonRect, "OPTIONS", buttonFont, 20.0f, 1.0f);
    DrawTextEx(buttonFont, "OPTIONS", optionTextPos, 20.0f, 1.0f, BLACK);

    DrawRectangleRec(creditsButtonRect, BLUE);
    Vector2 creditsTextPos=getTextPos(creditsButtonRect, "CREDITS", buttonFont, 20.0f, 1.0f);
    DrawTextEx(buttonFont, "CREDITS", creditsTextPos, 20.0f, 1.0f, BLACK);

    DrawRectangleRec(quitButtonRect, RED);
    Vector2 quitTextPos=getTextPos(quitButtonRect, "QUIT", buttonFont, 20.0f, 10.f);
    DrawTextEx(buttonFont, "QUIT", quitTextPos, 20.0f, 1.0f, BLACK);

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