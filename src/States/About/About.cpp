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
