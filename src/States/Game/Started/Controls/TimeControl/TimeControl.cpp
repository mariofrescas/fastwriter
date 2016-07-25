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
