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

#include <SFML/Graphics.hpp>

#include "MusicPlayer.h"
#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes().front(), "Fastwriter", sf::Style::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode(600, 500), "States");
    ResourceManager resManager;
    MusicPlayer musicPlayer(resManager);
    musicPlayer.setVolume(50);
    SoundPlayer soundPlayer(resManager);

    StateManager stateManager
    (
        StateManager::SharedContext
        (
            window,
            musicPlayer,
            soundPlayer,
            resManager
        )
    );
    stateManager.setCurrentState(States::ID::Black);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            stateManager.handleInput(event);
        }

        if (window.isOpen())
        {
            stateManager.update(deltaTime);

            window.clear();
            stateManager.draw();
            window.display();

            soundPlayer.removeStoppedSounds();
        }
    }

    return 0;
}
