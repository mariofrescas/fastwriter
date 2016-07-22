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

#include "CountDownControl.h"

CountDownControl::CountDownControl(const sf::Time& start,
                                   unsigned charSize,
                                   const sf::Vector2f& position,
                                   const sf::Font& font)
    : start(start),
      elapsed(start),
      graph(std::to_string(static_cast<int>(elapsed.asSeconds())), font, charSize)
{
    graph.setPosition(position);
}

bool CountDownControl::finished(const sf::Time& dt)
{
    elapsed -= dt;
    bool ret = false;

    if (elapsed <= sf::Time::Zero)
    {
        ret = true;
        elapsed = sf::Time::Zero;
    }

    graph.setString(std::to_string(static_cast<int>(elapsed.asSeconds())));

    return ret;
}

void CountDownControl::reset()
{
    elapsed = start;
    graph.setString(std::to_string(static_cast<int>(elapsed.asSeconds())));
}

const sf::Text& CountDownControl::getGraph() const
{
    return graph;
}
