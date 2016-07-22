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

#include "Fade.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

Fade::Fade(StateManager& stateManager)
    : Transition(stateManager),
      fade
      (
            getStateManager()
           .getSharedContext()
           .resourceManager
           .getShader(Shaders::ID::Fade)
      ),
      progress(0)
{
    if (!sf::Shader::isAvailable())
    {
        throw std::runtime_error("Error: Shaders not available");
    }
}

void Fade::configure(const sf::Time& duration,
                     const States::ID& next,
                     const sf::Texture& from,
                     const sf::Texture& to)
{
    nextState = next;
    effectDuration = duration;
    fade.setParameter("from", from);
    fade.setParameter("to", to);
    fade.setParameter("progress", progress);
    fade.setParameter("resolution", sf::Vector2f(1366.f, 768.f));
    fade.setParameter("color", sf::Vector3f(0.95f, 1.0f, 0.85f));
    fade.setParameter("colorPhase", 0.5f);
    handler.setTexture(from);
}

void Fade::handleInput(const sf::Event&)
{
}

void Fade::update(const sf::Time& dt)
{
    progress += 1 * (dt.asSeconds() / effectDuration.asSeconds());
    fade.setParameter("progress", progress);

    if (progress >= 1)
    {
        progress = 0;
        getStateManager().setCurrentState(nextState);
    }
}

void Fade::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;
    window.draw(handler, &fade);
}
