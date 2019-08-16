#include "resourceManager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
    loadTextures();
}

void ResourceManager::loadTextures()
{
    if (!testTexture.loadFromFile("img/testTexture.png"))
    {
        std::cout << "Texture didn't load" << std::endl;
    }
    textureMap["test"] = testTexture;
    if (!alienTexture.loadFromFile("img/alienTexture.png"))
    {
        std::cout << "Texture didn't load" << std::endl;
    }
    textureMap["alien"] = alienTexture;
    if (!cursorTexture.loadFromFile("img/cursorTexture.png"))
    {
        std::cout << "Texture didn't load" << std::endl;
    }
    textureMap["cursor"] = cursorTexture;
    if (!cursorTextureBig.loadFromFile("img/cursorTextureBig.png"))
    {
        std::cout << "Texture didn't load" << std::endl;
    }
    textureMap["cursorBig"] = cursorTextureBig;
}

sf::Texture &ResourceManager::getTexture(std::string name)
{
    return textureMap[name];
}
