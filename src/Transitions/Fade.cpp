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
    shader.setUniform("from", from);
    shader.setUniform("to", to);
    shader.setUniform("progress", progress);
    shader.setUniform("resolution", sf::Vector2f(from.getSize().x, from.getSize().y));
    shader.setUniform("color", sf::Vector3f(0.95f, 1.0f, 0.85f));
    shader.setUniform("colorPhase", 0.5f);
    handler.setTexture(from);
}
