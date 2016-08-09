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

#include "ExpertConf.h"

int ExpertConf::getDropTime() const
{
    return random(500, 800);
}

int ExpertConf::getWordLength() const
{
    return random(1, 5);
}

float ExpertConf::getDropVelocity() const
{
    return random(10, 50);
}

int ExpertConf::getInitLifes() const
{
    return 10;
}

int ExpertConf::getPointsIncrement() const
{
    return 1;
}

int ExpertConf::getPointsDecrement() const
{
    return 1;
}

int ExpertConf::getLifesIncrement() const
{
    return 1;
}

int ExpertConf::getLifesDecrement() const
{
    return 1;
}

int ExpertConf::getWantPoints() const
{
    return 10;
}

int ExpertConf::getShiftModeDuration() const
{
    return 5000;
}

int ExpertConf::getShiftModeNecessaryTime() const
{
    return 10000;
}

int ExpertConf::getDefaultCleaners() const
{
    return 1;
}

int ExpertConf::getMaxCleaners() const
{
    return 4;
}

int ExpertConf::getAddInterval() const
{
    return 5000;
}
