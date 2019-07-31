#include "game.h"
#include "state.h"
#include <iostream>

State::State()
{
}

State::State(Game * pGame)
{
    game = pGame;
}

void State::logic()
{
    input();
    update();
    draw();
}

void State::input(){}
void State::update(){}
void State::draw(){}
