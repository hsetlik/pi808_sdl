#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <SDL2/SDL.h>

// Base class for all GUI objects
class Component
{
private:
    /* data */
    SDL_Rect bounds;
public:
    Component(/* args */);
    virtual ~Component();
    //each component needs to define its drawing logic in here
    virtual void render(SDL_Renderer* rend)=0;
    SDL_Rect getBounds();
    void setBounds(SDLRect rect);
};

Component::Component(/* args */)
{
}

Component::~Component()
{
}


#endif // !COMPONENT_H