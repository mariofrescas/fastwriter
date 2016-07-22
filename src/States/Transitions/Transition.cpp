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
    shader.setParameter("progress", progress);

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
