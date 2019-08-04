#include "testEntity.h"

TestEntity::TestEntity(sf::Texture &texture):
    Entity(texture)
{
    testAnimation = Animation(50,getWidth(),getHeight(),{{0,0},{1,0},{0,1},{1,0},{0,0}});
}

void TestEntity::logic()
{
    testAnimation.animate(sprite);
}
