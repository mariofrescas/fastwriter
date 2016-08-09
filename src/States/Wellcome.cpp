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

#include "Wellcome.h"

#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Wellcome::Wellcome(StateManager& stateManager)
    : State(stateManager)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Wellcome));
    background.setTextureRect(sf::IntRect(2, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    wellcome.setTexture(resMngr.getTexture(Textures::ID::Wellcome));
    wellcome.setTextureRect(sf::IntRect(36 + 68, 2, 1366, 332));
    wellcome.setPosition(0, (windowSize.y / 2) - (wellcome.getTextureRect().height / 2));

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Wellcome Render Texture");
    }
}

void Wellcome::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::MenuOpen
        );
        getStateManager().setCurrentState
        (
            States::ID::MainMenu,
            Transitions::ID::Fade,
            sf::milliseconds(1000)
        );
    }
}

void Wellcome::update(const sf::Time&)
{
}

void Wellcome::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(wellcome);
}

const sf::Texture* Wellcome::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(wellcome);
    snapShot.display();

    return &snapShot.getTexture();
}

void Wellcome::reset()
{
}
