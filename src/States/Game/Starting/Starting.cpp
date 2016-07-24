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

#include "Starting.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

Starting::Starting(StateManager& stateManager, State* parent)
    : State(stateManager, parent)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Starting));
    background.setTextureRect(sf::IntRect(284, 0, 31, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    starting.setTexture(resMngr.getTexture(Textures::ID::Starting));
    starting.setTextureRect(sf::IntRect(0, 0, 283, 272));
    starting.setPosition
    (
        (windowSize.x / 2) - (starting.getGlobalBounds().width / 2),
        (windowSize.y / 2) - (starting.getGlobalBounds().height / 2)
    );

    countDown = std::make_unique<CountDownControl>
    (
        sf::seconds(3),
        sf::Color(162, 162, 162, 255),
        210,
        sf::Vector2f((windowSize.x / 2) - 58, (windowSize.y / 2) - 140),
        resMngr.getFont(Fonts::ID::Default)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create MainMenu Render Texture");
    }
}

void Starting::handleInput(const sf::Event&)
{
}

void Starting::update(const sf::Time& dt)
{
    if (countDown->finished(dt))
    {
        getStateManager().setCurrentState
        (
            States::ID::Started,
            Transitions::ID::CircleOpen,
            sf::milliseconds(1000)
        );

        reset();
    }
}

void Starting::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    window.draw(background);
    window.draw(starting);
    window.draw(countDown->getGraph());
}

const sf::Texture* Starting::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    snapShot.draw(background);
    snapShot.draw(starting);
    snapShot.draw(countDown->getGraph());
    snapShot.display();

    return &snapShot.getTexture();
}

void Starting::reset()
{
    countDown->reset();
}
