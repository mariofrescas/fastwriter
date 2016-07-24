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

#include "HardConf.h"

int HardConf::getDropTime() const
{
    return random(500, 800);
}

int HardConf::getWordLength() const
{
    return random(1, 5);
}

float HardConf::getDropVelocity() const
{
    return random(10, 50);
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
    return 1;
}

int HardConf::getLifesIncrement() const
{
    return 1;
}

int HardConf::getLifesDecrement() const
{
    return 1;
}

int HardConf::getWantPoints() const
{
    return 10;
}

int HardConf::getShiftModeDuration() const
{
    return 5000;
}

int HardConf::getShiftModeNecessaryTime() const
{
    return 10000;
}

int HardConf::getDefaultCleaners() const
{
    return 2;
}

int HardConf::getMaxCleaners() const
{
    return 4;
}

int HardConf::getAddInterval() const
{
    return 5000;
}
