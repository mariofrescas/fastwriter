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
