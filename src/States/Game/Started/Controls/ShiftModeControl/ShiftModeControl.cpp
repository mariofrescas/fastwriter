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
                                   const sf::Vector2f& position,
                                   const sf::IntRect& start,
                                   const sf::IntRect& middle,
                                   const sf::IntRect& end,
                                   const sf::IntRect& total,
                                   const sf::Texture& texture)
    : duration(duration),
      necessary(necessary),
      canActiveShift(true),
      isShiftActive(false),
      defWidth((total.width - start.width) - start.width),
      graph(position, start, middle, end, total, texture)
{
    graph.fillFull();
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
    graph.fillFull();
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

const TextureBar::Graph& ShiftModeControl::getGraph() const
{
    return graph.getGraph();
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

    graph.adjustMiddle(as);
}
