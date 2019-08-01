#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED
#include <SFML/Graphics.hpp>
class ResourceManager
{
public:
    ResourceManager();
private:
    sf::Texture testTexture;
    loadTextures();
};

#endif // RESOURCEMANAGER_H_INCLUDED
