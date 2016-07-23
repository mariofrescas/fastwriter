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

#include "RestartConfirm.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

RestartConfirm::RestartConfirm(StateManager& stateManager, State* parent)
    : State(stateManager, parent)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::RestartConfirm));
    background.setTextureRect(sf::IntRect(0, 395, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr float cw = 1069.727;
    constexpr float ch = 191.313;
    float cx = (windowSize.x / 2) - (cw / 2);
    float cy = (windowSize.y / 2) - (ch / 2);

    constexpr float mc = 500;
    float mx = cx + 55;
    float my = cy + 55;

    restartConfirmMenu = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().setCurrentState
                    (
                        States::ID::Paused,
                        Transitions::ID::CircleOpen,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my),
                sf::IntRect(56, 208, 339, 79),
                sf::IntRect(56, 298, 339, 79)
            },
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
                sf::Vector2f(mx + (mc * 1), my),
                sf::IntRect(554, 203, 445, 80),
                sf::IntRect(554, 293, 445, 80)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(cx, cy),
            sf::IntRect(0, 0, cw, ch)
        },
        resMngr.getTexture(Textures::ID::RestartConfirm)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create MainMenu Render Texture");
    }
}

void RestartConfirm::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        restartConfirmMenu->setCurrentOption
        (
            sf::Vector2f(event.mouseMove.x, event.mouseMove.y)
        );
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        restartConfirmMenu->execCurrentOption
        (
            sf::Vector2f(event.mouseButton.x, event.mouseButton.y)
        );
    }
}

void RestartConfirm::update(const sf::Time&)
{
}

void RestartConfirm::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    window.draw(background);

    window.draw(restartConfirmMenu->getGraphicMenu().container.graph);

    for (const auto& opt : restartConfirmMenu->getGraphicMenu().options)
    {
        window.draw(opt.graph);
    }
}

const sf::Texture* RestartConfirm::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    snapShot.draw(background);

    snapShot.draw(restartConfirmMenu->getGraphicMenu().container.graph);

    for (const auto& opt : restartConfirmMenu->getGraphicMenu().options)
    {
        snapShot.draw(opt.graph);
    }
    snapShot.display();

    return &snapShot.getTexture();
}

