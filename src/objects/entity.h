#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string.h>
#include <map>

#include "../animation.h"

class Entity
{
public:
    Entity();
    Entity(sf::Texture &texture);
    Entity(sf::Texture &texture, int width, int height);
    sf::Vector2f position;
    sf::Sprite sprite;
    int getWidth();
    int getHeight();
protected:
    int width = 25;
    int height = 25;
};

#endif // ENTITY_H_INCLUDED
