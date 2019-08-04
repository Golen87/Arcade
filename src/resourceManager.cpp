#include "resourceManager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
    loadTextures();
}

ResourceManager::loadTextures()
{
    if (!testTexture.loadFromFile("../img/testTexture.png"))
    {
        std::cout << "testTexture.png failed to load" << std::endl;
    }
    if (!alienTexture.loadFromFile("../img/alienTexture.png"))
    {
        std::cout << "alienTexture.png failed to load" << std::endl;
    }
    if (!cursorTexture.loadFromFile("../img/cursorTexture.png"))
    {
        std::cout << "cursorTexture.png failed to load" << std::endl;
    }
}
