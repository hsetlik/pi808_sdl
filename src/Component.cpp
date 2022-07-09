#include "Component.h"

Component::Component(Component *comp) : parent(comp)
{
    if (parent == nullptr) //If this is the top level component, let it fill the whole display
    {
        SDL_GetDisplayBounds(0, &bounds);
    }
    else
    {
        bounds = parent->getBounds();
    }
}

Component::~Component()
{
}

uint16_t Component::depth()
{
    Component *par = parent;
    uint16_t d = 0;
    while (par != nullptr)
    {
        ++d;
        par = par->getParent();
    }
    return d;
}

void Component::setSizeFloat(float w, float h, bool applyToChildren)
{
    setSizeMode(SizeMode::Float);
    lastFloatSize = {w, h};
}

void Component::setSizePixels(Uint32 w, Uint32 h, bool applyToChildren)
{
    setSizeMode(SizeMode::Pixels);
    lastPixelSize = {w, h};
}

void Component::setSizeBlock(Uint32 w, Uint32 h, bool applyToChildren)
{
    setSizeMode(SizeMode::Block);
    lastBlockSize = {w, h};
}

void Component::setSizeMode(SizeMode mode, bool applyToChildren)
{
    currentSizeMode = mode;
    for (auto &child : children)
    {
        child.setSizeMode(mode);
    }
}

void Component::resizeChildren()
{
    switch (currentSizeMode)
    {
        case SizeMode::Block:
            resizeBlock();
            break;
        case SizeMode::Float:
            resizeFloat();
            break;
        case SizeMode::Pixels:
            resizePixel();
            break;
        default:
            break;
    }
}

void Component::resizeBlock()
{
    // 
}

void Component::resizeFloat()
{

}

void Component::resizePixel()
{

}