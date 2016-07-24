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

#ifndef EXPERTCONF_H
#define EXPERTCONF_H

#include "GameConf.h"

////////////////////////////////////////////////////////////
/// \brief Describe los valores de configuracion de dificultad Experto
///
////////////////////////////////////////////////////////////
class ExpertConf : public GameConf
{
public:
    virtual int getDropTime() const override;
    virtual int getWordLength() const override;
    virtual float getDropVelocity() const override;
    virtual int getInitLifes() const override;
    virtual int getPointsIncrement() const override;
    virtual int getPointsDecrement() const override;
    virtual int getLifesIncrement() const override;
    virtual int getLifesDecrement() const override;
    virtual int getWantPoints() const override;
    virtual int getShiftModeDuration() const override;
    virtual int getShiftModeNecessaryTime() const override;
    virtual int getDefaultCleaners() const override;
    virtual int getMaxCleaners() const override;
    virtual int getAddInterval() const override;
};

#endif // EXPERTCONF_H
