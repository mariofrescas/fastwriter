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

#ifndef ABOUT_H
#define ABOUT_H

#include "State.h"

#include "GraphicMenu.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe la escena de informacion "acerca de..."
///
////////////////////////////////////////////////////////////
class About : public State
{
public:
    explicit About(StateManager& stateManager);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
    virtual const sf::Texture* getSnapShotTexture() override;

private:
    sf::Sprite        background; ///< Sprite de fondo
    sf::Sprite        about;      ///< Sprite de mensaje de bienvenida
    GraphicMenu::Ptr  button;     ///< Boton para regresar el menu principal
    sf::RenderTexture snapShot;   ///< Captura de la escena
};

#endif // ABOUT_H
