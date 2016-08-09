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

#include "PointsControl.h"

PointsControl::PointsControl(const sf::Vector2f& position,
                             const std::array<sf::IntRect, 10>& rects,
                             const sf::Texture& texture)
 :
    points(0),
    graph
    (
        sf::Vector2f(0, 0),
        rects,
        texture
    )
{
    setPosition(position);
    updateGraph();
}

void PointsControl::reset()
{
    points = 0;
    updateGraph();
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
    s.append((points < 10000)? "0" : "");
    s.append((points < 1000)? "0" : "");
    s.append((points < 100)? "0" : "");
    s.append((points < 10)? "0" : "");
    s.append(std::to_string(points));

    graph.setNumber(s);
}

void PointsControl::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(graph, states);
}
