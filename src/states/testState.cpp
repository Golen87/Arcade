#include "testState.h"
#include "../game.h"
#include <iostream>

TestState::TestState(Game * pGame)
{
    game = pGame;
    testEntity = TestEntity(game->resourceManager.testTexture);
    alien = Alien(game->resourceManager.alienTexture);
    alien.sprite.move(50,50);
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
    if (alien.sprite.getGlobalBounds().contains(cursor.getPosition().x,cursor.getPosition().y))
    {
        cursor.finger.setFrame(0);
        cursor.finger.animate(cursor.sprite);
    }
    else
    {
        cursor.pointer.setFrame(0);
        cursor.pointer.animate(cursor.sprite);
    }
}
