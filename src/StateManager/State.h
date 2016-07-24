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

#include <memory>

class StateManager;
namespace sf
{
    class Event;
    class Time;
    class Texture;
}


////////////////////////////////////////////////////////////
/// \brief Define la interfaz basica para estados/escenas
///
////////////////////////////////////////////////////////////
class State
{
public:
    using Ptr = std::unique_ptr<State>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Escena que conoce a su administrador y a su escena padre
    /// \param stateManager Referencia hacia el administrador de la escena
    /// \param parent Puntero hacia la escena padre
    ///
    /// No es necesario que la escena tenga/conozca a su padre.
    ///
    ////////////////////////////////////////////////////////////
    explicit State(StateManager& stateManager, State* parent = nullptr);

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
    /// \brief Obtiene una captura de la escena en forma de textura
    /// \return Puntero hacia la textura
    ///
    ////////////////////////////////////////////////////////////
    virtual const sf::Texture* getSnapShotTexture() = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia la escena a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    virtual void reset() = 0;

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

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la escena padre
    /// \return Referencia a la escena padre
    ///
    ////////////////////////////////////////////////////////////
    State& getParentState() const;

private:
    StateManager& stateManager;  ///< Administrador
    State*        parentState;   ///< Escena padre
};

#endif // STATE_H
