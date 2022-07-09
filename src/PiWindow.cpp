#include "PiWindow.h"

PiWindow::PiWindow(/* args */) : AppWindow("PI808")
{
}

PiWindow::~PiWindow()
{
}

void PiWindow::renderWindow(SDL_Renderer* rend)
{


}

void PiWindow::handleEvent(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_QUIT: // This makes the window close button work
            isRunning = false;
            break;
        default:
            break;
    } 
}

