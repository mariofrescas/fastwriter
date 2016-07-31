/*************************************************************************
**
** Fastwriter
** Copyright (C) 2016 Sysyfydev (sysyfydev@gmail.com)
**
** This software is provided 'as-is', without any express or implied warranty.
** In no event will the authors be held liable for any damages arising
** from the use of this software.
**
** Permission is granted to anyone to use this software for any purpose,
** including commercial applications, and to alter it and redistribute it freely,
** subject to the following restrictions:
**
** 1. The origin of this software must not be misrepresented;
**    you must not claim that you wrote the original software.
**    If you use this software in a product, an acknowledgment
**    in the product documentation is required.
**
** 2. Altered source versions must be plainly marked as such,
**    and must not be misrepresented as being the original software.
**
** 3. This notice may not be removed or altered from any source distribution.
**
*************************************************************************/

#include "Game.h"

#include <SFML/Window/Event.hpp>

Game::Game(const std::string& resPath)
 :
    resMngr(resPath),
    window
    (
        sf::VideoMode::getDesktopMode(),
        "Fastwriter",
        sf::Style::Fullscreen
    ),
    musicPlayer(resMngr),
    soundPlayer(resMngr),
    stateManager
    (
        StateManager::SharedContext
        (
            window,
            musicPlayer,
            soundPlayer,
            resMngr
        )
    )
{
    musicPlayer.setVolume(50);
    stateManager.setCurrentState(States::ID::Black);
}

int Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();

        handleInput();
        update(dt);
        draw();

        soundPlayer.removeStoppedSounds();
    }

    return 0;
}

void Game::handleInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        stateManager.handleInput(event);
    }
}

void Game::update(const sf::Time& dt)
{
    stateManager.update(dt);
}

void Game::draw()
{
    window.clear();
    stateManager.draw();
    window.display();
}
