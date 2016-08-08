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

#include "LifesControl.h"

LifesControl::LifesControl(int defaultLifes,
                           const sf::Vector2f& position,
                           const std::array<sf::IntRect, 10>& rects,
                           const sf::Texture& texture)
 :
    lifes(defaultLifes),
    defaultLifes(defaultLifes),
    remainLifes(true),
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

void LifesControl::reconfigure(int defaultLifes)
{
    this->defaultLifes = defaultLifes;
}

void LifesControl::reset()
{
    lifes = defaultLifes;
    remainLifes = true;
    updateGraph();
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
    s.append((lifes < 10000)? "0" : "");
    s.append((lifes < 1000)? "0" : "");
    s.append((lifes < 100)? "0" : "");
    s.append((lifes < 10)? "0" : "");
    s.append(std::to_string(lifes));

    graph.setNumber(s);
}

void LifesControl::draw(sf::RenderTarget& target,
                        sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(graph, states);
}
