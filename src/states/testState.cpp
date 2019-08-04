#include "testState.h"
#include "../game.h"
#include <iostream>

TestState::TestState(Game * pGame)
{
    game = pGame;
    testEntity = TestEntity(game->resourceManager.testTexture);
    alien = Alien(game->resourceManager.alienTexture);
    alien.sprite.move(50,50);
    alien.idle.setPause(true);
    cursor = Cursor(game->resourceManager.cursorTexture);
    std::cout << "HELLO, WORLD!" << std::endl;
}

void TestState::input()
{

}
void TestState::update()
{
    collisionCheck();
    cursor.update(game->renderWindow);
    testEntity.logic();
    alien.logic();
}
void TestState::draw()
{
    game->renderWindow.draw(testEntity.sprite);
    game->renderWindow.draw(alien.sprite);
    game->renderWindow.draw(cursor.sprite);
}
void TestState::collisionCheck()
{
    //alien is touching cursor
    if (alien.sprite.getGlobalBounds().contains(cursor.getPosition().x,cursor.getPosition().y))
    {
        cursor.finger.animate(cursor.sprite);
        alien.idle.setPause(false);
    }
    else
    {
        cursor.pointer.animate(cursor.sprite);
        alien.idle.setPause(true);
    }
}
