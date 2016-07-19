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
