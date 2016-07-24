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

#include "Black.h"

#include "StateManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

Black::Black(StateManager& stateManager)
    : State(stateManager)
{
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setFillColor(sf::Color::Black);
    background.setSize(sf::Vector2f(windowSize.x, windowSize.y));

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Black Render Texture");
    }
}

void Black::handleInput(const sf::Event&)
{
}

void Black::update(const sf::Time& dt)
{
    elapsed += dt;
    if (elapsed >= sf::milliseconds(1000))
    {
        getStateManager().setCurrentState
        (
            States::ID::Wellcome,
            Transitions::ID::CircleOpen,
            sf::milliseconds(1000)
        );
    }
}

void Black::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
}

const sf::Texture* Black::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.display();

    return &snapShot.getTexture();
}

void Black::reset()
{
}
