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

#include "Paused.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Paused::Paused(StateManager& stateManager, State* parent)
    : State(stateManager, parent)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Paused));
    background.setTextureRect(sf::IntRect(1398, 0, 31, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr float cw = 556.062;
    constexpr float ch = 394.947;
    float cx = (windowSize.x / 2) - (cw / 2);
    float cy = (windowSize.y / 2) - (ch / 2);

    constexpr float mc = 110;
    float mx = cx + 52;
    float my = cy + 47;

    pausedMenu = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().setCurrentState
                    (
                        States::ID::Starting,
                        Transitions::ID::CircleOpen,
                        sf::milliseconds(500)
                    );
                },
                sf::Vector2f(mx, my),
                sf::IntRect(582, 31, 401, 73),
                sf::IntRect(994, 31, 401, 73)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().setCurrentState
                    (
                        States::ID::RestartConfirm,
                        Transitions::ID::CircleClose,
                        sf::milliseconds(500)
                    );
                },
                sf::Vector2f(mx, my + (mc * 1)),
                sf::IntRect(582, 135, 402, 79),
                sf::IntRect(994, 135, 402, 79)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().setCurrentState
                    (
                        States::ID::QuitConfirm,
                        Transitions::ID::CircleClose,
                        sf::milliseconds(500)
                    );
                },
                sf::Vector2f(mx, my + (mc  * 2)),
                sf::IntRect(582, 241, 226, 89),
                sf::IntRect(994, 241, 226, 89)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(cx, cy),
            sf::IntRect(0, 0, cw, ch)
        },
        resMngr.getTexture(Textures::ID::Paused)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create MainMenu Render Texture");
    }
}

void Paused::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        pausedMenu->setCurrentOption
        (
            sf::Vector2f(event.mouseMove.x, event.mouseMove.y)
        );
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        pausedMenu->execCurrentOption
        (
            sf::Vector2f(event.mouseButton.x, event.mouseButton.y)
        );
        reset();
    }
}

void Paused::update(const sf::Time&)
{
}

void Paused::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    window.draw(background);

    window.draw(pausedMenu->getGraphicMenu().container.graph);

    for (const auto& opt : pausedMenu->getGraphicMenu().options)
    {
        window.draw(opt.graph);
    }
}

const sf::Texture* Paused::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    snapShot.draw(background);

    snapShot.draw(pausedMenu->getGraphicMenu().container.graph);

    for (const auto& opt : pausedMenu->getGraphicMenu().options)
    {
        snapShot.draw(opt.graph);
    }
    snapShot.display();

    return &snapShot.getTexture();
}

void Paused::reset()
{
    pausedMenu->setCurrentOption(sf::Vector2f(0, 0));
}

