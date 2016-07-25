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
