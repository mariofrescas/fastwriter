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
