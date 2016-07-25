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

#include "Black.h"

#include "SoundPlayer.h"
#include "StateManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

Black::Black(StateManager& stateManager)
    : State(stateManager)
{
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setFillColor(sf::Color::Black);
    background.setSize(sf::Vector2f(windowSize.x, windowSize.y));

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Black Render Texture");
    }
}

void Black::handleInput(const sf::Event&)
{
}

void Black::update(const sf::Time& dt)
{
    elapsed += dt;
    if (elapsed >= sf::milliseconds(1000))
    {
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::MenuClosed
        );
        getStateManager().setCurrentState
        (
            States::ID::Wellcome,
            Transitions::ID::CircleOpen,
            sf::milliseconds(1000)
        );
    }
}

void Black::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
}

const sf::Texture* Black::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.display();

    return &snapShot.getTexture();
}

void Black::reset()
{
}
