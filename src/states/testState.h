#ifndef TESTSTATE_H_INCLUDED
#define TESTSTATE_H_INCLUDED
#include "../state.h"
class TestState: public State
{
public:
    TestState(Game * pGame);
private:
    void input();
    void update();
    void draw();
};
#endif // TESTSTATE_H_INCLUDED
