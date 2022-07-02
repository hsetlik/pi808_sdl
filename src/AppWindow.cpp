#include "AppWindow.h"

AppWindow::AppWindow(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) : isRunning(false),
                                                                                                      window(nullptr),
                                                                                                      renderer(nullptr),
                                                                                                      windowName(title),
                                                                                                      xPos(xpos),
                                                                                                      yPos(ypos),
                                                                                                      windowWidth(width),
                                                                                                      windowHeight(height),
                                                                                                      isFullscreen(fullscreen),
                                                                                                      lastFrameStart(0)
{
    int flags = 0;
    if (isFullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        printf("SDL Initialized\n");
        window = SDL_CreateWindow(title, xPos, yPos, windowWidth, windowHeight, flags);
        if (window)
        {
            // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            printf("Window Created\n");
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            printf("Renderer Created\n");
        }
        isRunning = true;
    }
}

AppWindow::~AppWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}



void AppWindow::pollEvents()
{
    static SDL_Event event;
    if (SDL_PollEvent(&event))
        handleEvent(&event);
}

void AppWindow::render()
{
    SDL_RenderClear(renderer);
    renderWindow(renderer);
    SDL_RenderPresent(renderer);
}


void AppWindow::run()
{
    static ulong now = 0;
    while (isRunning)
    {
        pollEvents();
        now = SDL_GetTicks64();
        auto diff = now - lastFrameStart;
        // check if it's time for a new frame
        if (diff > (1000 / MAX_FPS))
        {
            render();
            lastFrameStart = now;
        }
    }
    return;
}

