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

#include "TimeControl.h"

TimeControl::TimeControl(unsigned charSize,
                         const sf::Vector2f& position,
                         const sf::Font& font)
    : graph("00:00:00", font, charSize)
{
    graph.setPosition(position);
}

void TimeControl::reset()
{
    elapsed = sf::Time::Zero;
    update(sf::Time::Zero);
}

void TimeControl::update(const sf::Time& dt)
{
    elapsed += dt;

    int h = elapsed / sf::seconds(3600);
    int m = (elapsed / sf::seconds(60)) - (h * 60);
    int s = (elapsed - sf::seconds(h * 3600) - sf::seconds(m * 60)).asSeconds();

    std::string time;
    time.reserve(8);
    time.append((h < 10)? std::string("0").append(std::to_string(h)) : std::to_string(h));
    time.append(":");
    time.append((m < 10)? std::string("0").append(std::to_string(m)) : std::to_string(m));
    time.append(":");
    time.append((s < 10)? std::string("0").append(std::to_string(s)) : std::to_string(s));

    graph.setString(time);
}

const sf::Text& TimeControl::getGraph() const
{
    return graph;
}
