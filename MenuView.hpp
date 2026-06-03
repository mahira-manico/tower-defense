#include "raylib.h" 

struct WindowContext;

class MenuView{   
    public:
    Texture2D menuBackgroundTexture;
    Font buttonFont;
    Rectangle playButtonRect;
    Rectangle optionsButtonRect;
    Rectangle creditsButtonRect;
    Rectangle quitButtonRect;
    Rectangle volumeSliderRect;

    MenuView();
    ~MenuView();

    void drawMainMenu(WindowContext& context);
    void drawOptionsPanel(WindowContext& context, int currentVolume);
    void drawCredits(WindowContext& context)

};