#ifndef APPWINDOW_H
#define APPWINDOW_H

//#include <string>
#include <SDL2/SDL.h>

// Redefine these or pass width and height arguments to AppWindow constructor
#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 480
#define MAX_FPS 60

typedef unsigned long ulong;

class AppWindow
{
protected:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char* windowName;
    int xPos;
    int yPos;
    int windowWidth;
    int windowHeight;
    bool isFullscreen;
    ulong lastFrameStart;
    // checks for an SDL event to pass to the 
    void pollEvents();
    //pure virtual for doing the window drawing
    virtual void renderWindow(SDL_Renderer* rend)=0;
public:
    AppWindow(const char *title = "App Window", int xpos = 0, int ypos = 0, int width = DISPLAY_WIDTH, int height = DISPLAY_HEIGHT, bool fullscreen = false);
    virtual ~AppWindow();
    //control/outside access stuff
    bool running() {return isRunning; }
    //pure virtual function to handle a given event
    virtual void handleEvent(SDL_Event* event)=0;
    virtual void render();
    //The main entry point to the app. Call this in main.cpp
    void run();

};


#endif // !APPWINDOW_H