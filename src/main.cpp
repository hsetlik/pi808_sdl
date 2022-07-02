#include <iostream>
#include <SDL2/SDL.h>
#include "AppWindow.h"

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 480



void sdlLoop()
{

}

int main()
{

  SDL_Window* window = nullptr;

  SDL_Surface* screenSurface = nullptr;
  if (SDL_Init(SDL_INIT_VIDEO) > 0)
  {
    std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }
  window = SDL_CreateWindow("Pi808", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH, DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
  if (window != nullptr)
  {
    screenSurface = SDL_GetWindowSurface(window);

    auto eRect = SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
    if (eRect != 0)
    {
      auto err = SDL_GetError();
      std::cout << err;
    } else 
    {
      std::cout << "Rectangle filled\n";
    }  
    //Update the surface
    if (SDL_UpdateWindowSurface( window ) != 0)
    {
      auto err = SDL_GetError();
      std::cout << "Window surface not updated: " << err << std::endl;
    } else
      std::cout << "Window updated\n";

    SDL_Delay(2000);
  }

  SDL_DestroyWindow(window);

  SDL_Quit();

 return 0;
}