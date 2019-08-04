#include "alien.h"

Alien::Alien(sf::Texture &texture):
    Entity(texture,30,30)
{
    idle = Animation(5,getWidth(),getHeight(),{{0,0},{1,0},{2,0},{3,0},{4,0},{5,0}});
}

void Alien::logic()
{
    idle.animate(sprite);
}
