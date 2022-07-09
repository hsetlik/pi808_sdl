#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <SDL2/SDL.h>



enum class SizeMode
{
    //Size and position this component based on absolute pixels
    Pixels,
    //Size and position this component based on a fraction of the parent component. All values must be between 0.0 and 1.0.
    Float,
    //Size and position this component based on the block system.
    Block
};

struct FSize
{
    float width;
    float height;
};

struct ISize
{
    Uint32 width;
    Uint32 height;
};

// Base class for all GUI objects
class Component
{
private:
    void resizeFloat();
    void resizePixel();
    void resizeBlock();
protected:
    /* data */
    SDL_Rect bounds;
    Component* const parent;
    std::vector<Component> children;
    SizeMode currentSizeMode;
    FSize lastFloatSize;
    ISize lastPixelSize;
    ISize lastBlockSize;
    // sets the bounds of the children based on the size mode
    void resizeChildren();
public:
    Component(Component* comp=nullptr);
    virtual ~Component();
    //each component needs to define its drawing logic in here
    virtual void render(SDL_Surface* rend)=0;
    uint16_t depth();
    SDL_Rect getBounds() { return bounds; }
    // getters
    Component* getParent() { return parent; }
    std::vector<Component>& getChildren() { return children; }
    // Size / size mode setters
    void setSizeFloat(float w, float h, bool applyToChildren=true);
    

    void setSizePixels(Uint32 w, Uint32 h, bool applyToChildren=true);
    

    void setSizeBlock(Uint32 w, Uint32 h, bool applyToChildren=true);
    

    void setSizeMode (SizeMode mode, bool applyToChildren=true);

};



#endif // !COMPONENT_H