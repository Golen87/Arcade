#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <map>

class ResourceManager
{
public:
    ResourceManager();
    sf::Texture &getTexture(std::string name);
private:
    sf::Texture testTexture;
    sf::Texture alienTexture;
    sf::Texture cursorTexture;
    sf::Texture cursorTextureBig;
    void loadTextures();
    std::map<std::string,sf::Texture> textureMap;
};

#endif // RESOURCEMANAGER_H_INCLUDED
