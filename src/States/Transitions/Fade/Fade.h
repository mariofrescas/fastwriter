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

#ifndef FADE_H
#define FADE_H

#include "Transition.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Shader.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el efecto transitorio Fade para escenas
///
////////////////////////////////////////////////////////////
class Fade : public Transition
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Crea un efecto transitorio Fade
    ///
    ////////////////////////////////////////////////////////////
    Fade(StateManager& stateManager);

    virtual void configure(const sf::Time& duration,
                           const States::ID& next,
                           const sf::Texture& from,
                           const sf::Texture& to) override;

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;

private:
    sf::Shader fade;           ///< Shader del efecto
    sf::Sprite handler;        ///< Sprite capa a mostrar
    float      progress;       ///< Progreso del efecto
    sf::Time   effectDuration; ///< Duracion del efecto
    States::ID nextState;      ///< Esena siguiente al terminar el efecto
};
#endif // FADE_H
