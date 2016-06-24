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

////////////////////////////////////////////////////////////
/// \brief Describe la escena de la bienvenida
///
////////////////////////////////////////////////////////////
class Wellcome : public State
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa la escena de la bienvenida
    ///
    /// Inicializa:
    /// * Sprite del fondo
    /// * Sprite del mensaje de bienvenida
    /// * Posicion del sprite del mensaje de bienvenida
    ///
    ////////////////////////////////////////////////////////////
    explicit Wellcome(StateManager& stateManager);

    ////////////////////////////////////////////////////////////
    /// \brief Cambia la escena actual por la del menu principal
    /// \param event Evento producido por el usuario
    ///
    /// Cambia la escena actual por la del menu principal
    /// al activarse algun click en cualquier parte de la escena.
    ///
    ////////////////////////////////////////////////////////////
    virtual void handleInput(const sf::Event& event) override;

    ////////////////////////////////////////////////////////////
    /// \brief No hace nada
    ///
    /// No hace nada debido a que no es necesario actualizar los
    /// elementos graficos de la escena en base a la logica.
    ///
    ////////////////////////////////////////////////////////////
    virtual void update(const sf::Time& dt) override;

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la escena de la bienvenida
    ///
    /// Dibuja:
    /// * Sprite del fondo
    /// * Sprite del mensaje de bienvenida
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw() override;

private:
    sf::Sprite background; ///< Sprite del fondo
    sf::Sprite wellcome;   ///< Sprite del mensaje de bienvenida
};

#endif // WELLCOME_H
