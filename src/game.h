#ifndef GAME_H
#define GAME_H
//Game stuff
#include <SFML/Graphics.hpp>
#include "state.h"
#include "states/testState.h"
#include "resourceManager.h"
class Game
{
public:
    Game();
    void mainGameLoop();
    void changeState(State * pState);
    sf::RenderWindow renderWindow;
    ResourceManager resourceManager;
private:
    State * state;
    const int WINDOW_WIDTH;
    const int WINDOW_HEIGHT;
};
#endif
