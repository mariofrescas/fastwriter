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

#ifndef STATE_H
#define STATE_H

////////////////////////////////////////////////////////////
// Cabeceras
//
////////////////////////////////////////////////////////////
#include <memory>

////////////////////////////////////////////////////////////
// Declaraciones fordward
//
////////////////////////////////////////////////////////////
class StateManager;

namespace sf
{
    class Event;
    class Time;
}

////////////////////////////////////////////////////////////
/// \brief Define la interfaz basica para estados/escenas
///
////////////////////////////////////////////////////////////
class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    ////////////////////////////////////////////////////////////
    /// \brief Crea una escena que conoce a su administrador
    /// \param stateManager Referencia hacia el administrador de la escena
    ///
    ////////////////////////////////////////////////////////////
    explicit State(StateManager& stateManager);

    ////////////////////////////////////////////////////////////
    /// \brief Controla las entradas del usuario
    /// \param event Evento producido por el usuario
    ///
    ////////////////////////////////////////////////////////////
    virtual void handleInput(const sf::Event& event) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza los elementos graficos
    /// \param dt Porcion de tiempo
    ///
    ////////////////////////////////////////////////////////////
    virtual void update(const sf::Time& dt) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja los elementos graficos
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw() = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Destructor virtual
    ///
    ////////////////////////////////////////////////////////////
    virtual ~State() = default;

protected:
    ////////////////////////////////////////////////////////////
    /// \brief Obtiene el administrador de la escena
    /// \return Referencia al administrador
    ///
    ////////////////////////////////////////////////////////////
    StateManager& getStateManager() const;

private:
    StateManager& mStateManager; ///< Administrador
};

#endif // STATE_H
