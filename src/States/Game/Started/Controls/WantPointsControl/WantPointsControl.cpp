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

#include "WantPointsControl.h"

WantPointsControl::WantPointsControl(int wantPoints,
                                     const sf::Color& color,
                                     const sf::FloatRect& rect)
    : points(0),
      wantPoints(wantPoints),
      isWantPointsFull(false),
      defWidth(rect.width),
      graph(sf::Vector2f(rect.width, rect.height))
{
    graph.setFillColor(color);
    graph.setPosition(rect.left, rect.top);
}

void WantPointsControl::reset()
{
    points = 0;
    updateGraph();
}

const sf::RectangleShape& WantPointsControl::getGraph() const
{
    return graph;
}

void WantPointsControl::addPoints(int increment)
{
    points += increment;
    updateGraph();
}

bool WantPointsControl::isFull() const
{
    return isWantPointsFull;
}

void WantPointsControl::updateGraph()
{
    int tp = wantPoints;
    int ts = defWidth;

    int ap = points;
    int as = (ap * ts) / tp;

    if (ap == tp)
    {
        isWantPointsFull = true;
        points = 0;
    }
    else
    {
        isWantPointsFull = false;
    }

    graph.setSize(sf::Vector2f(as, graph.getSize().y));
}
