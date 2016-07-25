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
