#include "cursor.h"
#include <iostream>

Cursor::Cursor(sf::Texture &texture):
    Entity(texture,15,15)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,getWidth(),getHeight()));
    pointer = Animation(1,getWidth(),getHeight(),{{0,0}});
    finger = Animation(1,getWidth(),getHeight(),{{1,0}});
    finger.animate(sprite);
}

sf::Vector2i Cursor::getPosition()
{
    return sf::Vector2i(sprite.getPosition().x,sprite.getPosition().y);
}

void Cursor::update(sf::RenderWindow &renderWindow)
{
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(renderWindow);
    // convert it to world coordinates
    sf::Vector2f worldPos = renderWindow.mapPixelToCoords(pixelPos);
    sprite.setPosition(worldPos);
}

bool Cursor::isLeftClick()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

