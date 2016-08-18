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

#include "Transition.h"

#include "StateManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

Transition::Transition(StateManager& stateManager,
                       sf::Shader& shader)
    : State(stateManager, nullptr),
      shader(shader),
      progress(0)
{
    if (!sf::Shader::isAvailable())
    {
        throw std::runtime_error("Error: Shaders not available");
    }
}

void Transition::handleInput(const sf::Event&)
{
}

void Transition::update(const sf::Time& dt)
{
    progress += 1 * (dt.asSeconds() / effectDuration.asSeconds());
    shader.setUniform("progress", progress);

    if (progress >= 1)
    {
        progress = 0;
        getStateManager().setCurrentState(nextState);
    }
}

void Transition::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;
    window.draw(handler, &shader);
}

const sf::Texture* Transition::getSnapShotTexture()
{
    return nullptr;
}

void Transition::reset()
{
}
