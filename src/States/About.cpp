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

#include "About.h"

#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

About::About(StateManager& stateManager)
    : State(stateManager)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::About));
    background.setTextureRect(sf::IntRect(878, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr float acw = 572;
    constexpr float ach = 624;
    float acx = (windowSize.x / 2) - (acw / 2);
    float acy = (windowSize.y / 2) - (ach / 2);

    constexpr float msgYoff = 200;
    constexpr float msgXoff = 63;
    container.setTexture(resMngr.getTexture(Textures::ID::About));
    container.setTextureRect(sf::IntRect(433, 316, acw, ach));
    container.setPosition(acx, acy);

    about.setTexture(resMngr.getTexture(Textures::ID::About));
    about.setTextureRect(sf::IntRect(2, 36, 430, 189));
    about.setPosition(acx + msgXoff, acy + msgYoff);
    currentMsg = &about;

    license.setTexture(resMngr.getTexture(Textures::ID::About));
    license.setTextureRect(sf::IntRect(434, 36, 452, 278));
    license.setPosition(acx + msgXoff, acy + msgYoff);

    acknowled.setTexture(resMngr.getTexture(Textures::ID::About));
    acknowled.setTextureRect(sf::IntRect(2, 316, 429, 288));
    acknowled.setPosition(acx + msgXoff, acy + msgYoff);

    options = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::TabChange
                    );
                    currentMsg = &about;
                },
                sf::Vector2f(acx + 63, acy + 160),
                sf::IntRect(457, 2, 73, 20),
                sf::IntRect(532, 2, 73, 20)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::TabChange
                    );
                    currentMsg = &license;
                },
                sf::Vector2f(acx + 200, acy + 160),
                sf::IntRect(607, 2, 103, 20),
                sf::IntRect(2, 2, 103, 20)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::TabChange
                    );
                    currentMsg = &acknowled;
                },
                sf::Vector2f(acx + 338, acy + 164),
                sf::IntRect(107, 2, 173, 20),
                sf::IntRect(282, 2, 173, 20)
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
                    reset();
                },
                sf::Vector2f(acx + 341, acy + 527),
                sf::IntRect(712, 2, 81, 28),
                sf::IntRect(795, 2, 81, 28)
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
        throw std::runtime_error("Can not create About Render Texture");
    }
}

void About::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        options->execCurrentOption(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
    }
}

void About::update(const sf::Time&)
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;
    options->setCurrentOption
    (
        static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))
    );
}

void About::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(container);
    window.draw(*currentMsg);
    window.draw(*options.get());
}

const sf::Texture* About::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(container);
    snapShot.draw(*currentMsg);
    snapShot.draw(*options.get());
    snapShot.display();

    return &snapShot.getTexture();
}

void About::reset()
{
    currentMsg = &about;
    options->setCurrentOption(sf::Vector2f(0, 0));
}
