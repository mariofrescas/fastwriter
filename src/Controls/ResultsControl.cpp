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

#include "ResultsControl.h"

ResultsControl::ResultsControl()
    : points(0),
      fails(0),
      fpoints(0),
      lifes(0),
      cleaners(0),
      shifts(0)
{
    for (auto& r : results)
    {
        r = "0";
    }
}

void ResultsControl::reset()
{
    elapsed = sf::Time::Zero;
    points = 0;
    fails = 0;
    fpoints = 0;
    lifes = 0;
    cleaners = 0;
    shifts = 0;

    for (std::size_t i = 1; i < results.size(); ++i)
    {
        results[i] = "0";
    }
}

void ResultsControl::setDiffty(const Configs::ID& diffty)
{
    switch (diffty)
    {
    case Configs::ID::Normal:
        results[0] = "Normal";
        break;
    case Configs::ID::Hard:
        results[0] = "Hard";
        break;
    case Configs::ID::Expert:
        results[0] = "Expert";
        break;
    }
}

void ResultsControl::addElapsed(const sf::Time& dt)
{
    elapsed += dt;

    int h = elapsed / sf::seconds(3600);
    int m = (elapsed / sf::seconds(60)) - (h * 60);
    int s = (elapsed - sf::seconds(h * 3600) - sf::seconds(m * 60)).asSeconds();

    std::string time = "";
    time.append
    (
        (h < 10)?
            std::string("0").append(std::to_string(h))
        :
            std::to_string(h)
    );
    time.append(":");
    time.append
    (
        (m < 10)?
            std::string("0").append(std::to_string(m))
        :
            std::to_string(m)
    );
    time.append(":");
    time.append
    (
        (s < 10)?
            std::string("0").append(std::to_string(s))
        :
            std::to_string(s)
    );

    results[1] = time;
}

void ResultsControl::incPoints(int increment)
{
    points += increment;
    results[2] = std::to_string(points);
}

void ResultsControl::decPoints(int decrement)
{
    if (points - decrement < 0)
    {
        fpoints += points;
        points = 0;
    }
    else
    {
        fpoints += decrement;
        points -= decrement;
    }

    results[2] = std::to_string(points);
    results[4] = std::to_string(fpoints);
}

void ResultsControl::incFails()
{
    ++fails;
    results[3] = std::to_string(fails);
}

void ResultsControl::incLifes(int increment)
{
    lifes += increment;
    results[5] = std::to_string(lifes);
}

void ResultsControl::incCleaners()
{
    ++cleaners;
    results[6] = std::to_string(cleaners);
}

void ResultsControl::incShifts()
{
    ++shifts;
    results[7] = std::to_string(shifts);
}

const std::array<std::string, 8>& ResultsControl::get() const
{
    return results;
}
