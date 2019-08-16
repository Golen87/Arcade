#ifndef TESTSTATE_H_INCLUDED
#define TESTSTATE_H_INCLUDED
#include "../state.h"
#include "../objects/testEntity.h"
#include "../objects/alien.h"
#include "../objects/cursor.h"
class TestState: public State
{
public:
    TestState(Game * pGame);
    TestEntity testEntity;
    Alien alien;
    Cursor cursor;
private:
    void input();
    void update();
    void draw();
    void collisionCheck();
    bool grabAlien = false;
};
#endif // TESTSTATE_H_INCLUDED
