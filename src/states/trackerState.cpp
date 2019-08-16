#include "trackerState.h"

TrackerState::TrackerState(Game *pGame)
{
    game = pGame;
    game->resourceManager.getTexture("cursor");
    game->renderWindow.setMouseCursorVisible(true); //Doesn't seem to work
    game->renderWindow.setView(sf::View(sf::FloatRect(0,0,256*2,240*2)));//384,360)));

    cursor = Cursor(game->resourceManager.getTexture("cursor"));
}

void TrackerState::input()
{

}
void TrackerState::update()
{
    cursor.update(game->renderWindow);
}
void TrackerState::draw()
{
    game->renderWindow.clear(sf::Color(255,80,0,255));
    //game->renderWindow.draw(cursor.sprite);
}
