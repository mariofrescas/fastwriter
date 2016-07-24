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

#ifndef STARTING_H
#define STARTING_H

#include "State.h"

#include "CountDownControl.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe la escena de juego iniciado
///
////////////////////////////////////////////////////////////
class Starting : public State
{
public:
    Starting(StateManager& stateManager, State* parent);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
    virtual const sf::Texture* getSnapShotTexture() override;
    virtual void reset() override;

private:
    sf::Sprite            background; ///< Fondo negro semi-transparente
    sf::Sprite            starting;   ///< Contenedor de conteo
    CountDownControl::Ptr countDown;  ///< Control de conteo
    sf::RenderTexture     snapShot;   ///< Captura de la escena
};

#endif // STARTING_H
