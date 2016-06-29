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

////////////////////////////////////////////////////////////
// Cabeceras
//
////////////////////////////////////////////////////////////
#include "State.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe la escena de bienvenida
///
////////////////////////////////////////////////////////////
class Wellcome : public State
{
private:

    ////////////////////////////////////////////////////////////
    /// \brief Describe los estados de la escena
    ///
    ////////////////////////////////////////////////////////////
    enum VisualStates
    {
        None,    ///< Termino de mostrarse
        Showing, ///< Mostrandose (fade in)
        Hiding   ///< Ocultandose (fade out)
    };

public:

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa la escena
    ///
    ////////////////////////////////////////////////////////////
    explicit Wellcome(StateManager& stateManager);

    ////////////////////////////////////////////////////////////
    /// \brief En caso de click la escena debe empezar a ocultarse
    /// \param event Evento producido por el usuario (Click)
    ///
    ////////////////////////////////////////////////////////////
    virtual void handleInput(const sf::Event& event) override;

    ////////////////////////////////////////////////////////////
    /// \brief Oscurece/muestra la escena de una manera progresiva
    ///
    /// Una vez ocultada la escena, procede al menu principal.
    ///
    ////////////////////////////////////////////////////////////
    virtual void update(const sf::Time& dt) override;

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja los elementos graficos
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw() override;

private:
    sf::Sprite   background;  ///< Sprite de fondo
    sf::Sprite   wellcome;    ///< Sprite de mensaje de bienvenida
    sf::Time     elapsed;     ///< Tiempo transcurrido para empezar a mostrar la escena
    VisualStates visualState; ///< Estado visual de la escena
    float        alpha;       ///< Increment/Decremento de transparencia
};

////////////////////////////////////////////////////////////
/// \class Wellcome
///
/// Inicia la escena con una pantalla negra, muestra progresivamente
/// el fondo y el mensaje de bienvenida hasta que estan completamente visibles.
///
/// La escena tarda un poco para empezar a mostrarse, no lo hace
/// directamente. De esta manera se logra un efecto mas realista.
///
/// Una vez que la escena esta completamente visible se puede hacer
/// click sobre ella para proceder al menu principal.
///
/// Una vez que se da click la escena se desvanece para dar paso
/// al menu principal.
///
/// La escena cuenta con tres estados None, Showing y Hiding.
/// - Showing: La escena se esta mostrando
/// - Hiding: La escena se esta ocultando
/// - None: La escena se termino de mostrar
///
/// El termino mostrando y ocultando quieren decir que la
/// escena se muestra/oculta de manera progresiva y no en un instante.
///
////////////////////////////////////////////////////////////

#endif // WELLCOME_H
