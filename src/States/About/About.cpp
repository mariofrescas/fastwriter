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
    background.setTextureRect(sf::IntRect(582, 195, 31, 31));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr float acw = 572.296;
    constexpr float ach = 624.038;
    float acx = (windowSize.x / 2) - (acw / 2);
    float acy = (windowSize.y / 2) - (ach / 2);

    constexpr float msgYoff = 200;
    constexpr float msgXoff = 63;
    container.setTexture(resMngr.getTexture(Textures::ID::About));
    container.setTextureRect(sf::IntRect(0, 0, acw, ach));
    container.setPosition(acx, acy);

    about.setTexture(resMngr.getTexture(Textures::ID::About));
    about.setTextureRect(sf::IntRect(787, 0, 431, 200));
    about.setPosition(acx + msgXoff, acy + msgYoff);
    currentMsg = &about;

    license.setTexture(resMngr.getTexture(Textures::ID::About));
    license.setTextureRect(sf::IntRect(581, 233, 452, 278));
    license.setPosition(acx + msgXoff, acy + msgYoff);

    acknowled.setTexture(resMngr.getTexture(Textures::ID::About));
    acknowled.setTextureRect(sf::IntRect(1040, 200, 430, 290));
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
                sf::IntRect(581, 86, 73, 20),
                sf::IntRect(581, 65, 73, 20)
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
                sf::IntRect(581, 129, 103, 20),
                sf::IntRect(581, 107, 103, 20)
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
                sf::IntRect(581, 170, 173, 20),
                sf::IntRect(581, 150, 173, 20)
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
        options->setCurrentOption(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        options->execCurrentOption(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
    }
}

void About::update(const sf::Time&)
{
}

void About::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(container);
    window.draw(*currentMsg);
    for (const auto& opt : options->getGraphicMenu().options)
    {
        window.draw(opt.graph);
    }
}

const sf::Texture* About::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(container);
    snapShot.draw(*currentMsg);
    for (const auto& opt : options->getGraphicMenu().options)
    {
        snapShot.draw(opt.graph);
    }
    snapShot.display();

    return &snapShot.getTexture();
}

void About::reset()
{
    currentMsg = &about;
    options->setCurrentOption(sf::Vector2f(0, 0));
}
