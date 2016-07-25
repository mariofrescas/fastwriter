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

#ifndef HARD_H
#define HARD_H

#include "GameConf.h"

////////////////////////////////////////////////////////////
/// \brief Describe los valores de configuracion de dificultad Dificil
///
////////////////////////////////////////////////////////////
class HardConf : public GameConf
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

#endif // HARD_H
