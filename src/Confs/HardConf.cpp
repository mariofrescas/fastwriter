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

#include "HardConf.h"

int HardConf::getDropTime() const
{
    return random(800, 1300);
}

int HardConf::getWordLength() const
{
    return random(1, 10);
}

float HardConf::getDropVelocity() const
{
    return 50;
}

int HardConf::getInitLifes() const
{
    return 10;
}

int HardConf::getPointsIncrement() const
{
    return 1;
}

int HardConf::getPointsDecrement() const
{
    return 40;
}

int HardConf::getLifesIncrement() const
{
    return 3;
}

int HardConf::getLifesDecrement() const
{
    return 1;
}

int HardConf::getWantPoints() const
{
    return 100;
}

int HardConf::getShiftModeDuration() const
{
    return 5000;
}

int HardConf::getShiftModeNecessaryTime() const
{
    return 15000;
}

int HardConf::getDefaultCleaners() const
{
    return 3;
}

int HardConf::getMaxCleaners() const
{
    return 5;
}

int HardConf::getAddInterval() const
{
    return 300000;
}
