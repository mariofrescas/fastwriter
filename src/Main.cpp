/*************************************************************************
** Copyright (C) 2016 Sysyfydev <sysyfydev@gmail.com>.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*************************************************************************/

#include <SFML/Graphics.hpp>

#include "StateManager.h"
#include "ResourceManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes().front(), "Fastwriter", sf::Style::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode(600, 500), "States");
    ResourceManager resManager;

    StateManager stateManager(StateManager::SharedContext(window, resManager));
    stateManager.setCurrentState(StateManager::StateType::Wellcome);

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
        }
    }

    return 0;
}
