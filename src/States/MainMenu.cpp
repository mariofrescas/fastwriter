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

#include "MainMenu.h"

#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

MainMenu::MainMenu(StateManager& stateManager)
    : State(stateManager)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    constexpr int cw = 572;
    constexpr int ch = 624;
    int cx = (windowSize.x / 2) - (cw / 2);
    int cy = (windowSize.y / 2) - (ch / 2);

    constexpr int mc = 104;
    int mx = cx + 70;
    int my = cy + 70;

    background.setTexture(resMngr.getTexture(Textures::ID::MainMenu));
    background.setTextureRect(sf::IntRect(548, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    mainMenu = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuOpen
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::DifftyMenu,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my),
                sf::IntRect(2, 868, 437, 71),
                sf::IntRect(217, 786, 437, 71)
            },
            GraphicMenu::MenuOptionData
            {
                [&] () { },
                sf::Vector2f(mx, my + (mc * 1)),
                sf::IntRect(330, 941, 326, 71),
                sf::IntRect(2, 941, 326, 71)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuOpen
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::Help,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my + (mc  * 2)),
                sf::IntRect(2, 786, 213, 80),
                sf::IntRect(434, 704, 213, 80)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuOpen
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::About,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                },
                sf::Vector2f(mx, my + (mc * 3)),
                sf::IntRect(275, 2, 271, 74),
                sf::IntRect(2, 2, 271, 74)
            },
            GraphicMenu::MenuOptionData
            {
                [&] () { getStateManager().getSharedContext().window.close(); },
                sf::Vector2f(mx, my + (mc * 4)),
                sf::IntRect(218, 704, 214, 73),
                sf::IntRect(2, 704, 214, 73)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(cx, cy),
            sf::IntRect(2, 78, cw, ch)
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
    if (event.type == sf::Event::MouseButtonPressed)
    {
        mainMenu->execCurrentOption(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        reset();
    }
}

void MainMenu::update(const sf::Time&)
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;
    mainMenu->setCurrentOption
    (
        static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))
    );
}

void MainMenu::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(*mainMenu.get());
}

const sf::Texture* MainMenu::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(*mainMenu.get());
    snapShot.display();

    return &snapShot.getTexture();
}

void MainMenu::reset()
{
    mainMenu->setCurrentOption(sf::Vector2f(0, 0));
}
