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

#include "PointsControl.h"

PointsControl::PointsControl(unsigned charSize,
                             const sf::Vector2f& position,
                             const sf::Font& font)
    : points(0),
      graph("00000", font, charSize)
{
    graph.setPosition(position);
}

void PointsControl::reset()
{
    points = 0;
    updateGraph();
}

const sf::Text& PointsControl::getGraph() const
{
    return graph;
}

void PointsControl::increment(int increment)
{
    points += increment;
    updateGraph();
}

void PointsControl::decrement(int decrement)
{
    if (points - decrement > 0)
    {
        points -= decrement;
    }
    else
    {
        points = 0;
    }

    updateGraph();
}

void PointsControl::updateGraph()
{
    std::string s;
    s += (points < 10000)? "0": "";
    s += (points < 1000)? "0": "";
    s += (points < 100)? "0": "";
    s += (points < 10)? "0": "";
    s += std::to_string(points);

    graph.setString(s);
}
