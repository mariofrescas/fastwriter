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

#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <list>
#include "ResourceManager.h"
#include <SFML/Audio/Sound.hpp>

////////////////////////////////////////////////////////////
/// \brief Administrador de efectos de sonido
///
////////////////////////////////////////////////////////////
class SoundPlayer
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Crea una administrador de efectos de sonidos que
    ///        conoce al administrador de recursos
    ///
    /// Conoce al administrador de recursos con el objetivo de
    /// poder obtener el buffer de sonido cargado del disco duro.
    ///
    ////////////////////////////////////////////////////////////
    SoundPlayer(ResourceManager& resMngr);

    ////////////////////////////////////////////////////////////
    /// \brief Agrega el sonido especificado a la lista y lo reproduce
    /// \param sound Id del sonido a reproducir
    ///
    ////////////////////////////////////////////////////////////
    void play(const Sounds::ID& sound);

    ////////////////////////////////////////////////////////////
    /// \brief Remueve de la lista de sonidos aquellos sonidos
    ///        que hayan finalizados su reproduccion
    ///
    ////////////////////////////////////////////////////////////
    void removeStoppedSounds();

private:
    ResourceManager&     resMngr; ///< Obtiene los Sound
    std::list<sf::Sound> sounds;  ///< Lista de sonidos
};

#endif // SOUNDPLAYER_H
