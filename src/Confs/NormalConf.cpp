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

#include "NormalConf.h"

int NormalConf::getDropTime() const
{
    return random(300, 1000);
}

int NormalConf::getWordLength() const
{
    return random(1, 3);
}

float NormalConf::getDropVelocity() const
{
    return 100;
}

int NormalConf::getInitLifes() const
{
    return 10;
}

int NormalConf::getPointsIncrement() const
{
    return 1;
}

int NormalConf::getPointsDecrement() const
{
    return 25;
}

int NormalConf::getLifesIncrement() const
{
    return 5;
}

int NormalConf::getLifesDecrement() const
{
    return 4;
}

int NormalConf::getWantPoints() const
{
    return 100;
}

int NormalConf::getShiftModeDuration() const
{
    return 5000;
}

int NormalConf::getShiftModeNecessaryTime() const
{
    return 15000;
}

int NormalConf::getDefaultCleaners() const
{
    return 5;
}

int NormalConf::getMaxCleaners() const
{
    return 5;
}

int NormalConf::getAddInterval() const
{
    return 300000;
}
