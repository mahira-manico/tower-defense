#ifndef WINDOWCONTEXT_HPP
#define WINDOWCONTEXT_HPP

#include "raylib.h"

class WindowContext
{
private:
    // Main application window
    void* window;

    // Screen dimensions
    int windowWidth;
    int windowHeight;

public:
    // Constructor
    WindowContext();

    // Open the game window
    void initialize();

    // Clear the screen before drawing
    void clear();

    // Display the rendered frame
    void display();

    // Check if the window is still active
    bool isOpen() const;
};

#endif