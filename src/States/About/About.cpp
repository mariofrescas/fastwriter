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

#include "About.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

About::About(StateManager& stateManager)
    : State(stateManager)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Background));

    constexpr float acw = 572.296;
    constexpr float ach = 624.038;
    float acx = (windowSize.x / 2) - (acw / 2);
    float acy = (windowSize.y / 2) - (ach / 2);

    about.setTexture(resMngr.getTexture(Textures::ID::About));
    about.setTextureRect(sf::IntRect(0, 0, acw, ach));
    about.setPosition(acx, acy);

    button = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().setCurrentState
                    (
                        States::ID::MainMenu,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(acx + 341, acy + 527),
                sf::IntRect(581.338, 34, 81.015, 28),
                sf::IntRect(581.338, 0, 81.015, 28)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(0, 0),
            sf::IntRect(0, 0, 0, 0)
        },
        resMngr.getTexture(Textures::ID::About)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Wellcome Render Texture");
    }
}

void About::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        button->setCurrentOption(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        button->execCurrentOption(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        reset();
    }
}

void About::update(const sf::Time&)
{
}

void About::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(about);
    window.draw(button->getGraphicMenu().options.front().graph);
}

const sf::Texture* About::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(about);
    snapShot.draw(button->getGraphicMenu().options.front().graph);
    snapShot.display();

    return &snapShot.getTexture();
}

void About::reset()
{
    button->setCurrentOption(sf::Vector2f(0, 0));
}
