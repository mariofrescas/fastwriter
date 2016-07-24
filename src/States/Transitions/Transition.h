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

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Shader.hpp>

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
    Transition(StateManager& stateManager, sf::Shader& shader);

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

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
    virtual const sf::Texture* getSnapShotTexture() override;
    virtual void reset() override;

protected:
    sf::Shader& shader;         ///< Shader del efecto
    sf::Sprite  handler;        ///< Sprite envoltorio de shader a mostrar
    float       progress;       ///< Progreso del efecto
    sf::Time    effectDuration; ///< Duracion del efecto
    States::ID  nextState;      ///< Esena siguiente al terminar el efecto
};

#endif // TRANSITION_H
