#include "resourceManager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
    loadTextures();
}

ResourceManager::loadTextures()
{
    if (!testTexture.loadFromFile("testTexture.png"))
    {
        std::cout << "testTexture.png failed to load" << std::endl;
    }
}
