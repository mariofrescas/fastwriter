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

#include "Help.h"

#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Help::Help(StateManager &stateManager)
    : State(stateManager)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Help));
    background.setTextureRect(sf::IntRect(168, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr int acw = 915;
    constexpr int ach = 641;
    int acx = (windowSize.x / 2) - (acw / 2);
    int acy = (windowSize.y / 2) - (ach / 2);

    help.setTexture(resMngr.getTexture(Textures::ID::Help));
    help.setTextureRect(sf::IntRect(2, 36, acw, ach));
    help.setPosition(acx, acy);

    back = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
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
                    reset();
                },
                sf::Vector2f(acx + 672, acy + 536),
                sf::IntRect(85, 2, 81, 28),
                sf::IntRect(2, 2, 81, 28)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(0, 0),
            sf::IntRect(0, 0, 0, 0)
        },
        resMngr.getTexture(Textures::ID::Help)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Help Render Texture");
    }
}

void Help::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        back->execCurrentOption(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
    }
}

void Help::update(const sf::Time&)
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;
    back->setCurrentOption
    (
        static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))
    );
}

void Help::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(help);
    window.draw(*back.get());
}

const sf::Texture* Help::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(help);
    snapShot.draw(*back.get());
    snapShot.display();

    return &snapShot.getTexture();
}

void Help::reset()
{
    back->setCurrentOption(sf::Vector2f(0, 0));
}
