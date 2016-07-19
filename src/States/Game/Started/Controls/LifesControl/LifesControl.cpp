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

#include "LifesControl.h"

LifesControl::LifesControl(int defaultLifes,
                           unsigned charSize,
                           const sf::Vector2f& position,
                           const sf::Font& font)
    : lifes(defaultLifes),
      defaultLifes(defaultLifes),
      remainLifes(true),
      graph("00000", font, charSize)
{
    graph.setPosition(position);
    updateGraph();
}

void LifesControl::reset()
{
    lifes = defaultLifes;
    remainLifes = true;
    updateGraph();
}

const sf::Text& LifesControl::getGraph() const
{
    return graph;
}

void LifesControl::increment(int increment)
{
    lifes += increment;
    updateGraph();
}

void LifesControl::decrement(int decrement)
{
    if (lifes - decrement > 0)
    {
        lifes -= decrement;
    }
    else
    {
        lifes = 0;
        remainLifes = false;
    }

    updateGraph();
}

bool LifesControl::remain() const
{
    return remainLifes;
}

void LifesControl::updateGraph()
{
    std::string s;
    s += (lifes < 10000)? "0": "";
    s += (lifes < 1000)? "0": "";
    s += (lifes < 100)? "0": "";
    s += (lifes < 10)? "0": "";
    s += std::to_string(lifes);

    graph.setString(s);
}
