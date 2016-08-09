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

TimeControl::TimeControl(const sf::Vector2f& position,
                         const std::array<sf::IntRect, 11>& rects,
                         const sf::Texture& texture)
 :
    hours
    (
        sf::Vector2f(0, 0),
        std::array<sf::IntRect, 10>
        {
            rects[0], rects[1], rects[2], rects[3], rects[4],
            rects[5], rects[6], rects[7], rects[8], rects[9],
        },
        texture
    ),
    separator1(texture),
    minutes
    (
        sf::Vector2f(0, 0),
        std::array<sf::IntRect, 10>
        {
            rects[0], rects[1], rects[2], rects[3], rects[4],
            rects[5], rects[6], rects[7], rects[8], rects[9],
        },
        texture
    ),
    separator2(texture),
    seconds
    (
        sf::Vector2f(0, 0),
        std::array<sf::IntRect, 10>
        {
            rects[0], rects[1], rects[2], rects[3], rects[4],
            rects[5], rects[6], rects[7], rects[8], rects[9],
        },
        texture
    )
{
    setPosition(position);

    separator1.setTextureRect(rects[10]);
    separator1.setPosition
    (
        hours.getPosition().x + (rects[0].width * 2),
        (rects[0].height / 2) - (rects[10].height / 2)
    );

    minutes.setPosition(separator1.getPosition().x + rects[10].width, 0);

    separator2.setTextureRect(rects[10]);
    separator2.setPosition
    (
        minutes.getPosition().x + (rects[0].width * 2),
        (rects[0].height / 2) - (rects[10].height / 2)
    );

    seconds.setPosition(separator2.getPosition().x + rects[10].width, 0);
}

void TimeControl::reset()
{
    elapsed = sf::Time::Zero;
    tick(sf::Time::Zero);
}

void TimeControl::tick(const sf::Time& dt)
{
    elapsed += dt;

    int h = elapsed / sf::seconds(3600);
    int m = (elapsed / sf::seconds(60)) - (h * 60);
    int s = (elapsed - sf::seconds(h * 3600) - sf::seconds(m * 60)).asSeconds();

    hours.setNumber
    (
        (h < 10)?
            std::string("0").append(std::to_string(h))
        :
            std::to_string(h)
    );
    minutes.setNumber
    (
        (m < 10)?
            std::string("0").append(std::to_string(m))
        :
            std::to_string(m)
    );
    seconds.setNumber
    (
        (s < 10)?
            std::string("0").append(std::to_string(s))
        :
            std::to_string(s)
    );
}

void TimeControl::draw(sf::RenderTarget& target,
                       sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(hours, states);
    target.draw(separator1, states);
    target.draw(minutes, states);
    target.draw(separator2, states);
    target.draw(seconds, states);
}
