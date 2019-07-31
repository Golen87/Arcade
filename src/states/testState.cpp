#include "testState.h"
#include "../game.h"
#include <iostream>

TestState::TestState(Game * pGame)
{
    game = pGame;
}

void TestState::input()
{

}
void TestState::update()
{
    std::cout << "HELLO, WORLD!" << std::endl;
}
void TestState::draw()
{

}
