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

#include "CleanersControl.h"

#include <SFML/Graphics/RenderTarget.hpp>

CleanersControl::CleanersControl(int defaultCleaners,
                                 int maxCleaners,
                                 const sf::Time& necessary,
                                 const sf::Vector2f& position,
                                 const sf::IntRect& rect,
                                 const sf::Texture& texture)
 :
    defaultCleaners(defaultCleaners),
    maxCleaners(maxCleaners),
    necessary(necessary),
    rect(rect),
    texture(texture)
{
    setPosition(position);
    addDefaultCleaners();
}

void CleanersControl::reconfigure(int defaultCleaners,
                                  int maxCleaners,
                                  const sf::Time& necessary)
{
    this->defaultCleaners = defaultCleaners;
    this->maxCleaners = maxCleaners;
    this->necessary = necessary;
}

void CleanersControl::reset()
{
    graph.clear();
    addDefaultCleaners();
}

void CleanersControl::addTime(const sf::Time& dt)
{
    if (graph.size() <= maxCleaners)
    {
        elapsed += dt;

        if (elapsed >= necessary)
        {
            elapsed = sf::Time::Zero;
            sf::Sprite sp(texture, rect);
            sp.setPosition(0 + (rect.width * graph.size()), 0);
            graph.push_back(sp);
        }
    }
}

void CleanersControl::clean()
{
    if (!graph.empty())
    {
        graph.pop_back();
    }
}

bool CleanersControl::canClean() const
{
    return !graph.empty();
}

void CleanersControl::addDefaultCleaners()
{
    for (int i = 0; i < defaultCleaners; ++i)
    {
        sf::Sprite sp(texture, rect);
        sp.setPosition(0 + (rect.width * i), 0);
        graph.push_back(sp);
    }
}

void CleanersControl::draw(sf::RenderTarget& target,
                           sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (auto& s : graph)
    {
        target.draw(s, states);
    }
}
