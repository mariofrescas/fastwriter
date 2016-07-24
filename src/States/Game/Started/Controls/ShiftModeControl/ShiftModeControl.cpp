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
