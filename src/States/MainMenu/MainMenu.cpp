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

#include "MainMenu.h"

// WARNING: Uncomment to disable assertions
// #define NDEBUG
#include <cassert>

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

MainMenu::MainMenu(StateManager& stateManager)
    : State(stateManager)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    constexpr float cw = 572.296;
    constexpr float ch = 624.038;
    float cx = (windowSize.x / 2) - (cw / 2);
    float cy = (windowSize.y / 2) - (ch / 2);

    constexpr float mc = 104;
    float mx = cx + 70;
    float my = cy + 70;

    background.setTexture(resMngr.getTexture(Textures::ID::Background));
    mainMenu = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().setCurrentState
                    (
                        States::ID::Started,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my),
                sf::IntRect(590.028, 169.658, 437.384, 73),
                sf::IntRect(590.028, 91.426, 437.384, 73)
            },
            GraphicMenu::MenuOptionData
            {
                [&] () { },
                sf::Vector2f(mx, my + (mc * 1)),
                sf::IntRect(590.028, 247.89, 326, 71),
                sf::IntRect(927.338, 247.89, 326, 71)
            },
            GraphicMenu::MenuOptionData
            {
                [&] () { },
                sf::Vector2f(mx, my + (mc  * 2)),
                sf::IntRect(590.028, 326.173, 218, 80),
                sf::IntRect(927.338, 326.173, 218, 80)
            },
            GraphicMenu::MenuOptionData
            {
                [&] () { },
                sf::Vector2f(mx, my + (mc * 3)),
                sf::IntRect(590.028, 413.489, 272, 74),
                sf::IntRect(927.338, 413.489, 272, 74)
            },
            GraphicMenu::MenuOptionData
            {
                [&] () { getStateManager().getSharedContext().window.close(); },
                sf::Vector2f(mx, my + (mc * 4)),
                sf::IntRect(590.028, 494.804, 214, 74),
                sf::IntRect(927.338, 494.804, 214, 74)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(cx, cy),
            sf::IntRect(0, 10.962, cw, ch)
        },
        resMngr.getTexture(Textures::ID::MainMenu)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create MainMenu Render Texture");
    }
}

void MainMenu::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        mainMenu->setCurrentOption(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        mainMenu->execCurrentOption(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
    }
}

void MainMenu::update(const sf::Time&)
{
}

void MainMenu::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(mainMenu->getGraphicMenu().container.graph);

    for (const auto& opt : mainMenu->getGraphicMenu().options)
    {
        window.draw(opt.graph);
    }
}

const sf::Texture* MainMenu::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(mainMenu->getGraphicMenu().container.graph);

    for (const auto& opt : mainMenu->getGraphicMenu().options)
    {
        snapShot.draw(opt.graph);
    }
    snapShot.display();

    return &snapShot.getTexture();
}
