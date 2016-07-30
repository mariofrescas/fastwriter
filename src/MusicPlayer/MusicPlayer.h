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

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <SFML/Audio/Music.hpp>

namespace Music
{
    enum class ID;
}
class ResourceManager;

////////////////////////////////////////////////////////////
/// \brief Describe el reproductor de temas
///
////////////////////////////////////////////////////////////
class MusicPlayer
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Crea un reproductor de temas
    /// \param resMngr Obtiene las rutas de los temas musicales
    ///
    ////////////////////////////////////////////////////////////
    MusicPlayer(const ResourceManager& resMngr);

    ////////////////////////////////////////////////////////////
    /// \brief Reproduce el tema especificado
    /// \param theme Tema a reproducir
    ///
    ////////////////////////////////////////////////////////////
    void play(const Music::ID& theme);

    ////////////////////////////////////////////////////////////
    /// \brief Pausa o continua la reproduccion
    /// \param pause True = Pausa la rep. False = Continua la rep.
    ///
    ////////////////////////////////////////////////////////////
    void pause(bool pause);

    ////////////////////////////////////////////////////////////
    /// \brief Detiene en su totalidad la reproduccion
    ///
    ////////////////////////////////////////////////////////////
    void stop();

    ////////////////////////////////////////////////////////////
    /// \brief Cambia el volumen del reproductor
    /// \param volume Nuevo volumen
    ///
    ////////////////////////////////////////////////////////////
    void setVolume(float volume);

private:
    sf::Music              music;   ///< Reproductor intern
    const ResourceManager& resMngr; ///< Administrador de recursos
};

#endif // MUSICPLAYER_H
