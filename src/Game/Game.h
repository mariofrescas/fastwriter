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

#ifndef GAME_H
#define GAME_H

#include "MusicPlayer.h"
#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

////////////////////////////////////////////////////////////
/// \brief Encapsulamiento del control de juego
///
////////////////////////////////////////////////////////////
class Game
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa la ventana y los administradores
    ///
    ////////////////////////////////////////////////////////////
    explicit Game(const std::string& resPath);

    ////////////////////////////////////////////////////////////
    /// \brief Bucle de juego clasico
    /// \return 0 = Ok
    ///
    ////////////////////////////////////////////////////////////
    int run();

private:
    ResourceManager  resMngr;      ///< Administrador de recursos
    sf::RenderWindow window;       ///< Ventana
    MusicPlayer      musicPlayer;  ///< Administrador de temas musicales
    SoundPlayer      soundPlayer;  ///< Administrador de sonidos
    StateManager     stateManager; ///< Administrador de estados

    ////////////////////////////////////////////////////////////
    /// \brief Controla las entradas del usuario
    /// \param event Evento producido por el usuario
    ///
    ////////////////////////////////////////////////////////////
    void handleInput();

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza los elementos graficos
    /// \param dt Porcion de tiempo
    ///
    ////////////////////////////////////////////////////////////
    void update(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja los elementos graficos en la ventana
    ///
    ////////////////////////////////////////////////////////////
    void draw();
};

#endif // GAME_H
