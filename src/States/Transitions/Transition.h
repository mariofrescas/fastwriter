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

#ifndef TRANSITION_H
#define TRANSITION_H

#include "State.h"

namespace States
{
    enum class ID;
}

////////////////////////////////////////////////////////////
/// \brief Describe la interfaz para los efectos transitorios de escenas
///
////////////////////////////////////////////////////////////
class Transition : public State
{
public:
    using Ptr = std::unique_ptr<Transition>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un efecto transitorio abstracto
    ///
    ////////////////////////////////////////////////////////////
    Transition(StateManager& stateManager);

    ////////////////////////////////////////////////////////////
    /// \brief Configura el efecto transitorio
    /// \param duration Duracion de la transicion
    /// \param next Cuando termine el efecto cambia la escena a "next"
    /// \param from Textura a ocultar
    /// \param to Textura a mostar
    ///
    ////////////////////////////////////////////////////////////
    virtual void configure(const sf::Time& duration,
                           const States::ID& next,
                           const sf::Texture& from,
                           const sf::Texture& to) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la captura de la escena
    /// \return Puntero a la captura de la escena (opcional: nullptr)
    ///
    ////////////////////////////////////////////////////////////
    virtual const sf::Texture* getSnapShotTexture() override;
};

#endif // TRANSITION_H
