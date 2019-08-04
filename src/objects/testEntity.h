#ifndef TESTENTITY_H_INCLUDED
#define TESTENTITY_H_INCLUDED
#include "../resourceManager.h"
#include "entity.h"

class TestEntity: public Entity
{
public:
    TestEntity(){};
    TestEntity(sf::Texture &texture);
    Animation testAnimation;
public:
    void logic();
};

#endif // TESTENTITY_H_INCLUDED
