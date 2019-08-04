#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
    ResourceManager();
    sf::Texture testTexture;
    sf::Texture alienTexture;
    sf::Texture cursorTexture;
private:
    void loadTextures();
};

#endif // RESOURCEMANAGER_H_INCLUDED
