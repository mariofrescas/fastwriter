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
                                     const sf::Vector2f& position,
                                     const sf::IntRect& start,
                                     const sf::IntRect& middle,
                                     const sf::IntRect& end,
                                     const sf::IntRect& total,
                                     const sf::Texture& texture)
    : points(0),
      wantPoints(wantPoints),
      isWantPointsFull(false),
      defWidth((total.width - start.width) - start.width),
      graph(position, start, middle, end, total, texture)
{
}

void WantPointsControl::reset()
{
    points = 0;
    updateGraph();
}

const TextureBar::Graph& WantPointsControl::getGraph() const
{
    return graph.getGraph();
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

    graph.adjustMiddle(as);

    if (ap == tp)
    {
        graph.empty();
        isWantPointsFull = true;
        points = 0;
    }
    else
    {
        isWantPointsFull = false;
    }
}
