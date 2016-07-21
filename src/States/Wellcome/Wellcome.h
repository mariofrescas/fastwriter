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

#ifndef WELLCOME_H
#define WELLCOME_H

#include "State.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe la escena de bienvenida
///
////////////////////////////////////////////////////////////
class Wellcome : public State
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa la escena
    /// \param stateManager Administrador de la escena
    ///
    ////////////////////////////////////////////////////////////
    explicit Wellcome(StateManager& stateManager);

    ////////////////////////////////////////////////////////////
    /// \brief Controla las entradas del usuario
    /// \param event Evento producido por el usuario
    ///
    ////////////////////////////////////////////////////////////
    virtual void handleInput(const sf::Event& event) override;

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza los elementos graficos
    /// \param dt Porcion de tiempo
    ///
    ////////////////////////////////////////////////////////////
    virtual void update(const sf::Time& dt) override;

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja los elementos graficos
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw() override;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una captura de la escena en forma de textura
    /// \return Puntero hacia la textura
    ///
    ////////////////////////////////////////////////////////////
    virtual const sf::Texture* getSnapShotTexture() override;

private:
    sf::Sprite        background; ///< Sprite de fondo
    sf::Sprite        wellcome;   ///< Sprite de mensaje de bienvenida
    sf::RenderTexture snapShot;   ///< Captura de la escena
};

#endif // WELLCOME_H
