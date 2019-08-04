#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED
#include "entity.h"
#include "../animation.h"

class Cursor: public Entity
{
public:
    Cursor(){};
    Cursor(sf::Texture &texture);
    sf::Vector2i getPosition();
    void update(sf::RenderWindow &renderWindow);
    Animation pointer;
    Animation finger;
};

#endif // CURSOR_H_INCLUDED
