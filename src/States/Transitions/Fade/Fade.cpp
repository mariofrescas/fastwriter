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
#include <SFML/Graphics/Texture.hpp>

Fade::Fade(StateManager& stateManager)
    : Transition
      (
           stateManager,
           stateManager
           .getSharedContext()
           .resourceManager
           .getShader(Shaders::ID::Fade)
      )
{
}

void Fade::configure(const sf::Time& duration,
                     const States::ID& next,
                     const sf::Texture& from,
                     const sf::Texture& to)
{
    nextState = next;
    effectDuration = duration;
    shader.setParameter("from", from);
    shader.setParameter("to", to);
    shader.setParameter("progress", progress);
    shader.setParameter("resolution", sf::Vector2f(from.getSize().x, from.getSize().y));
    shader.setParameter("color", sf::Vector3f(0.95f, 1.0f, 0.85f));
    shader.setParameter("colorPhase", 0.5f);
    handler.setTexture(from);
}
