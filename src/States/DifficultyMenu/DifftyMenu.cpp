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

#include "DifftyMenu.h"

#include "Started.h"
#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

DifftyMenu::DifftyMenu(StateManager& stateManager)
    : State(stateManager)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    constexpr float cw = 556.784;
    constexpr float ch = 507.288;
    float cx = (windowSize.x / 2) - (cw / 2);
    float cy = (windowSize.y / 2) - (ch / 2);

    constexpr float mc = 104;
    float mx = cx + 62;
    float my = cy + 62;

    background.setTexture(resMngr.getTexture(Textures::ID::Background));
    difftyMenu = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    static_cast<Started&>
                    (
                        getStateManager().getState
                        (
                            States::ID::Started
                        )
                    ).setGameDifficulty(Configs::ID::Normal);
                    getStateManager().getState(States::ID::Started).reset();
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuOpen
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::Starting,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my),
                sf::IntRect(569.098, 62.381, 323.576, 73),
                sf::IntRect(909.098, 62.381, 323.576, 73)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    static_cast<Started&>
                    (
                        getStateManager().getState
                        (
                            States::ID::Started
                        )
                    ).setGameDifficulty(Configs::ID::Hard);
                    getStateManager().getState(States::ID::Started).reset();
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuOpen
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::Starting,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my + (mc * 1)),
                sf::IntRect(569.098, 164.973, 212, 74),
                sf::IntRect(909.098, 164.973, 212, 74)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    static_cast<Started&>
                    (
                        getStateManager().getState
                        (
                            States::ID::Started
                        )
                    ).setGameDifficulty(Configs::ID::Expert);
                    getStateManager().getState(States::ID::Started).reset();
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuOpen
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::Starting,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my + (mc  * 2)),
                sf::IntRect(569.098, 268.559, 326, 79),
                sf::IntRect(909.098, 268.559, 326, 79)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuClose
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::MainMenu,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my + (mc * 3)),
                sf::IntRect(569.098, 377.083, 213.148, 74),
                sf::IntRect(909.098, 377.083, 213.148, 74)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(cx, cy),
            sf::IntRect(0, 0, cw, ch)
        },
        resMngr.getTexture(Textures::ID::DifftyMenu)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create MainMenu Render Texture");
    }
}

void DifftyMenu::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        difftyMenu->setCurrentOption
        (
            sf::Vector2f(event.mouseMove.x, event.mouseMove.y)
        );
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        difftyMenu->execCurrentOption
        (
            sf::Vector2f(event.mouseButton.x, event.mouseButton.y)
        );
        reset();
    }
}

void DifftyMenu::update(const sf::Time&)
{
}

void DifftyMenu::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(difftyMenu->getGraphicMenu().container.graph);

    for (const auto& opt : difftyMenu->getGraphicMenu().options)
    {
        window.draw(opt.graph);
    }
}

const sf::Texture* DifftyMenu::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(difftyMenu->getGraphicMenu().container.graph);

    for (const auto& opt : difftyMenu->getGraphicMenu().options)
    {
        snapShot.draw(opt.graph);
    }
    snapShot.display();

    return &snapShot.getTexture();
}

void DifftyMenu::reset()
{
    difftyMenu->setCurrentOption(sf::Vector2f(0, 0));
}
