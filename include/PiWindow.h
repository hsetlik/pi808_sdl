#ifndef PIWINDOW_H
#define PIWINDOW_H
#include "AppWindow.h"

class PiWindow : public AppWindow
{
private:
    /* data */
public:
    PiWindow(/* args */);
    ~PiWindow();
    void renderWindow(SDL_Renderer* rend) override;
    void handleEvent(SDL_Event* event) override;
    
};


#endif // !PIWINDOW_H