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

#ifndef GAMECONFMANAGER_H
#define GAMECONFMANAGER_H

#include <map>
#include "GameConf.h"

namespace Configs
{
    ////////////////////////////////////////////////////////////
    /// \brief Describe las dificultades posibles
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Normal, ///< Dificultad de juego normal
        Hard,   ///< Dificultad de juego dificil
        Expert  ///< Dificultad de juego experto
    };
}

////////////////////////////////////////////////////////////
/// \brief Describe el administrador de dificultades
///
////////////////////////////////////////////////////////////
class GameConfManager
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Crea un administrador de dificultades
    /// \param defaultConf Dificultad por defecto
    ///
    ////////////////////////////////////////////////////////////
    explicit GameConfManager(const Configs::ID& defaultConf = Configs::ID::Normal);

    ////////////////////////////////////////////////////////////
    /// \brief Cambia la dificultad actual
    /// \param confType Nueva dificultad
    ///
    ////////////////////////////////////////////////////////////
    void setCurrentConf(const Configs::ID& config);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la dificultad actual
    /// \return Referencia hacia la dificultad actual
    ///
    ////////////////////////////////////////////////////////////
    GameConf& getCurrentConf() const;

private:
    GameConf*                            currentConf; ///< Dificultad actual
    std::map<Configs::ID, GameConf::Ptr> confs;       ///< Mapa de dificultades
};

#endif // GAMECONFMANAGER_H
