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
    /// \param defaultType Dificultad por defecto
    ///
    ////////////////////////////////////////////////////////////
    explicit GameConfManager(const Configs::ID& defaultConf = Configs::ID::Normal);

    ////////////////////////////////////////////////////////////
    /// \brief Cambia la dificultad actual
    /// \param confType Nueva dificultad
    ///
    ////////////////////////////////////////////////////////////
    void setCurrentConf(const Configs::ID& confType);

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
