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
