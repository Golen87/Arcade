
#include "game.h"
Game::Game():
    WINDOW_WIDTH(256*2),
    WINDOW_HEIGHT(240*2)
{
    changeState(new TestState(this));
    renderWindow.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Test");
    sf::View defaultView(sf::FloatRect(0,0,256,240));
    //defaultView.zoom(0.5);
    renderWindow.setView(defaultView);
    //renderWindow.setVerticalSyncEnabled(true);
    renderWindow.setFramerateLimit(60);
    renderWindow.setMouseCursorVisible(false);
}

void Game::mainGameLoop()
{
    // The main loop - ends as soon as the window is closed
    while (renderWindow.isOpen())
    {
       // Event processing
       sf::Event event;
       while (renderWindow.pollEvent(event))
       {
           // "close requested" event: we close the window
            switch (event.type)
            {
                case sf::Event::Closed:
                renderWindow.close();
                break;
            }
       }
        /*
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
       {
            renderWindow.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"",sf::Style::None);
            renderWindow.setPosition(sf::Vector2i(0,0));
            renderWindow.setSize(sf::Vector2u(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height));
       }
       */

       //
       // Clear the whole window before rendering a new frame
       renderWindow.clear(sf::Color(58,180,109,255));


       state->logic();
       //renderWindow.draw(sFade);

       // End the current frame and display its contents on screen
       renderWindow.display();
    }
}

void Game::changeState(State * pState)
{
    state = pState;
}
