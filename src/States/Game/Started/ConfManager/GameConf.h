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

#ifndef GAMECONF_H
#define GAMECONF_H

#include <memory>

////////////////////////////////////////////////////////////
/// \brief Describe los valores de configuracion de dificultad
///
////////////////////////////////////////////////////////////
class GameConf
{
public:
    using Ptr = std::unique_ptr<GameConf>;

    virtual int getDropTime() const = 0;
    virtual int getWordLength() const = 0;
    virtual float getDropVelocity() const = 0;
    virtual int getInitLifes() const = 0;
    virtual int getPointsIncrement() const = 0;
    virtual int getPointsDecrement() const = 0;
    virtual int getLifesIncrement() const = 0;
    virtual int getLifesDecrement() const = 0;
    virtual int getWantPoints() const = 0;
    virtual int getShiftModeDuration() const = 0;
    virtual int getShiftModeNecessaryTime() const = 0;
    virtual int getDefaultCleaners() const = 0;
    virtual int getMaxCleaners() const = 0;
    virtual int getAddInterval() const = 0;

protected:
    int random(int min, int max) const;
};

#endif // GAMECONF_H
