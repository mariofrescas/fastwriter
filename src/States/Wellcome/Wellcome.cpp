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

#include "Wellcome.h"

#include "StateManager.h"
#include "ResourceManager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Wellcome::Wellcome(StateManager& stateManager)
    : State(stateManager)
{
    using Textures = ResourceManager::Textures;
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::Background));
    background.setColor(sf::Color(255, 255, 255, 0));

    wellcome.setTexture(resMngr.getTexture(Textures::Wellcome));
    wellcome.setPosition(0, (windowSize.y / 2) - (wellcome.getTextureRect().height / 2));
    wellcome.setColor(sf::Color(255, 255, 255, 0));

    visualState = VisualStates::Showing;
    alpha = 0;
}

void Wellcome::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed
     && visualState == VisualStates::None)
    {
        visualState = VisualStates::Hiding;
    }
}

void Wellcome::update(const sf::Time& dt)
{
    if (visualState == VisualStates::Showing)
    {
        elapsed += dt;

        if (elapsed >= sf::milliseconds(1000))
        {
            alpha += 255 * (dt.asSeconds() * 1.5);

            if (alpha >= 255)
            {
                visualState = VisualStates::None;
                alpha = 255;
            }

            background.setColor(sf::Color(255, 255, 255, alpha));
            wellcome.setColor(sf::Color(255, 255, 255, alpha));
        }
    }
    else if (visualState == VisualStates::Hiding)
    {
        alpha -= 255.0f * (dt.asSeconds() * 1.5);

        if (alpha <= 0)
        {
            visualState = VisualStates::Showing;
            alpha = 0;
            getStateManager().pushState(StateManager::StateType::MainMenu);
        }

        wellcome.setColor(sf::Color(255, 255, 255, alpha));
    }
}

void Wellcome::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(wellcome);
}
