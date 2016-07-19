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

#include "NormalConf.h"

int NormalConf::getDropTime() const
{
    return random(500, 800);
}

int NormalConf::getWordLength() const
{
    return random(1, 5);
}

float NormalConf::getDropVelocity() const
{
    return random(10, 50);
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
    return 1;
}

int NormalConf::getLifesIncrement() const
{
    return 1;
}

int NormalConf::getLifesDecrement() const
{
    return 1;
}

int NormalConf::getWantPoints() const
{
    return 10;
}

int NormalConf::getShiftModeDuration() const
{
    return 5000;
}

int NormalConf::getShiftModeNecessaryTime() const
{
    return 10000;
}

int NormalConf::getDefaultCleaners() const
{
    return 3;
}

int NormalConf::getMaxCleaners() const
{
    return 4;
}

int NormalConf::getAddInterval() const
{
    return 5000;
}
