#include "WindowContext.hpp"

// Constructor: initialize default values
WindowContext::WindowContext()
{
    // Raylib manages the window internally
    window = nullptr;

    windowWidth = 1280;
    windowHeight = 720;
}

// Open the game window
void WindowContext::initialize()
{
    InitWindow(windowWidth, windowHeight, "Tower Defense");
    SetTargetFPS(60);
}

// Clear the screen before rendering
void WindowContext::clear()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

// Display the rendered frame
void WindowContext::display()
{
    EndDrawing();
}

// Check if the window is still open
bool WindowContext::isOpen() const
{
    return !WindowShouldClose();
}