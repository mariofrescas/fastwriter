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

CleanersControl::CleanersControl(int defaultCleaners,
                                 int maxCleaners,
                                 const sf::Time& addInterval,
                                 const sf::Vector2f& position,
                                 const sf::Texture& gameTexture,
                                 const sf::IntRect& location)
    : defaultCleaners(defaultCleaners),
      maxCleaners(maxCleaners),
      cleaners(defaultCleaners),
      addInterval(addInterval),
      position(position),
      texture(gameTexture),
      location(location)

{
    addDefaultCleaners();
}

void CleanersControl::reconfigure(int defaultCleaners,
                                  int maxCleaners,
                                  const sf::Time& addInterval)
{
    this->defaultCleaners = defaultCleaners;
    this->maxCleaners = maxCleaners;
    this->addInterval = addInterval;
}

void CleanersControl::reset()
{
    cleaners = defaultCleaners;
    graph.clear();
    addDefaultCleaners();
}

void CleanersControl::addTime(const sf::Time& dt)
{
    if (cleaners <= maxCleaners)
    {
        elapsed += dt;

        if (elapsed > addInterval)
        {
            elapsed = sf::Time::Zero;
            ++cleaners;
            sf::Sprite sp(texture, location);
            sp.setPosition(position.x + (location.width * graph.size()), position.y);
            graph.push_back(sp);
        }
    }
}

void CleanersControl::clean()
{
    if (cleaners > 0)
    {
        --cleaners;
        graph.pop_back();
    }
}

bool CleanersControl::canClean() const
{
    return cleaners > 0;
}

const std::list<sf::Sprite>& CleanersControl::getGraph() const
{
    return graph;
}

void CleanersControl::addDefaultCleaners()
{
    for (int i = 0; i < defaultCleaners; ++i)
    {
        sf::Sprite sp(texture, location);
        sp.setPosition(position.x + (location.width * i), position.y);
        graph.push_back(sp);
    }
}
