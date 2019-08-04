#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include "entity.h"

class Alien: public Entity
{
public:
    Alien(){};
    Alien(sf::Texture &texture);
    Animation idle;

    void logic();
};

#endif // ALIEN_H_INCLUDED
