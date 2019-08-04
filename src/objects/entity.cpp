#include "entity.h"

Entity::Entity()
{
    sprite.setTextureRect(sf::IntRect(0,0,0,0));
}

Entity::Entity(sf::Texture &texture)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,getWidth(),getHeight()));

}

Entity::Entity(sf::Texture &texture, int width, int height):
    Entity(texture)
{
    this->width = width;
    this->height = height;
}


int Entity::getWidth()
{
    return width;
}

int Entity::getHeight()
{
    return height;
}
