#include "testState.h"
#include "../game.h"
#include <iostream>

TestState::TestState(Game * pGame)
{
    game = pGame;
    testEntity = TestEntity(game->resourceManager.getTexture("test"));
    alien = Alien(game->resourceManager.getTexture("alien"));
    alien.sprite.move(50,50);
    alien.idle.setPause(true);
    cursor = Cursor(game->resourceManager.getTexture("cursor"));
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
        if (cursor.isLeftClick())
            grabAlien = true;
            //alien.sprite.setPosition(cursor.sprite.getPosition()-sf::Vector2f(10,10));
        else
            grabAlien = false;
    }
    else
    {
        cursor.pointer.animate(cursor.sprite);
        alien.idle.setPause(true);
    }

    if (grabAlien)
    {
        alien.sprite.setPosition(cursor.sprite.getPosition()-sf::Vector2f(10,10));
    }
}
