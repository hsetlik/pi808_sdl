#include <iostream>
#include <SDL2/SDL.h>

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 480

int main()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
  {
    std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }
  auto window = SDL_CreateWindow("Pi808", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH, DISPLAY_HEIGHT,0);


  while (1) ;

  return EXIT_SUCCESS;
}