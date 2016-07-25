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

#include "ShiftModeControl.h"

ShiftModeControl::ShiftModeControl(const sf::Time& duration,
                                   const sf::Time& necessary,
                                   const sf::Color& color,
                                   const sf::FloatRect rect)
    : duration(duration),
      necessary(necessary),
      canActiveShift(true),
      isShiftActive(false),
      defXpos(rect.left),
      defWidth(rect.width),
      graph(sf::Vector2f(rect.width, rect.height))
{
    graph.setFillColor(color);
    graph.setPosition(rect.left, rect.top);
}

void ShiftModeControl::reconfigure(const sf::Time& duration,
                                   const sf::Time& necessary)
{
    this->duration = duration;
    this->necessary = necessary;
}

void ShiftModeControl::reset()
{
    elapsed = sf::Time::Zero;
    canActiveShift = true;
    isShiftActive = false;
    graph.setPosition(defXpos, graph.getPosition().y);
    graph.setSize(sf::Vector2f(defWidth, graph.getSize().y));
}

void ShiftModeControl::update(const sf::Time& dt)
{
    if (!canActiveShift)
    {
        elapsed += dt;
        if (isShiftActive)
        {
            updateGraph(false);

            if (elapsed >= duration)
            {
                isShiftActive = false;
                elapsed = sf::Time::Zero;
            }
        }
        else
        {
            updateGraph(true);

            if (elapsed >= necessary)
            {
                canActiveShift = true;
                elapsed = sf::Time::Zero;
            }
        }
    }
}

const sf::RectangleShape& ShiftModeControl::getGraph() const
{
    return graph;
}

void ShiftModeControl::active()
{
    isShiftActive = true;
    canActiveShift = false;
}

bool ShiftModeControl::canActive() const
{
    return canActiveShift;
}

bool ShiftModeControl::isActive() const
{
    return isShiftActive;
}

void ShiftModeControl::updateGraph(bool isGrowing)
{
    int tt = (isGrowing)? necessary.asMilliseconds() : duration.asMilliseconds();
    int ts = defWidth;

    int at = (isGrowing)? elapsed.asMilliseconds() : tt - elapsed.asMilliseconds();
    int as = (at * ts) / tt;

    graph.setSize(sf::Vector2f(as, graph.getSize().y));
    graph.setPosition((defXpos + (defWidth / 2)) - (as / 2), graph.getPosition().y);
}
