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

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <map>
#include "State.h"
#include "Transition.h"

class ResourceManager;
namespace sf
{
    class RenderWindow;
}

namespace States
{
    ////////////////////////////////////////////////////////////
    /// \brief Define los tipos de escenas existentes
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Wellcome,   ///< Bienvenida
        MainMenu,   ///< Menu principal
        About,      ///< Acerca de...
        DifftyMenu, ///< Menu de seleccion de dificultad
        Starting,   ///< Iniciando el juego
        Started,    ///< Juego iniciado
        Paused,     ///< Juego pausado
        QuitConfirm ///< Confirmar quitar el juego
    };
}

namespace Transitions
{
    ////////////////////////////////////////////////////////////
    /// \brief Define los tipos de transiciones para las escenas existentes
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Fade,       ///< Transicion que se muestra progresivamente
        CircleOpen, ///< Transicion que se abre en forma de circulo
        CircleClose ///< Transicion que se cierra en forma de circulo
    };
}

////////////////////////////////////////////////////////////
/// \brief Define la administracion de las escenas
///
////////////////////////////////////////////////////////////
class StateManager
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Define la informacion compartida por las escenas
    ///
    ////////////////////////////////////////////////////////////
    struct SharedContext
    {
        ////////////////////////////////////////////////////////////
        /// \brief Almacena la informacion compartida
        /// \param window Referencia hacia la ventana donde se trabajara
        /// \param resManager Referencia hacia el administrador de recursos
        ///
        ////////////////////////////////////////////////////////////
        SharedContext(sf::RenderWindow& window, ResourceManager& resManager);

        sf::RenderWindow& window;          ///< Ventana donde trabajaran las escenas
        ResourceManager&  resourceManager; ///< Administrador de recursos
    };

    ////////////////////////////////////////////////////////////
    /// \brief Crea un administrador de escenas
    /// \param sharedContext Objeto que contiene la informacion compartida
    ///
    /// SharedContex = Copiado internamente.
    ///
    ////////////////////////////////////////////////////////////
    explicit StateManager(const SharedContext& sharedContex);

    ////////////////////////////////////////////////////////////
    /// \brief Cambia la escena actual
    /// \param state Llave que identifica la escena
    ///
    /// Del mapa de escenas selecciona el que tiene una llave con un valor
    /// igual al del parametro state y lo establece como la escena actual.
    ///
    ////////////////////////////////////////////////////////////
    void setCurrentState(const States::ID& state);

    ////////////////////////////////////////////////////////////
    /// \brief Cambia la escena actual con un efecto transitorio
    /// \param state Llave que identifica la escena
    /// \param transition Efecto transitorio
    /// \param duration Duracion de la transicion
    ///
    /// Obtiene el efecto transitorio seleccionado y lo establece
    /// como escena actual. Cuando el efecto transitorio termine
    /// este se encarga de poner como escena actual la escena
    /// seleccionada mediante el llamado a: setCurrentState(state).
    ///
    /// \see setCurrentState
    ///
    ////////////////////////////////////////////////////////////
    void setCurrentState(const States::ID& state,
                         const Transitions::ID& transition,
                         const sf::Time& duration);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la escena actual
    /// \return Referencia hacia el estado actual
    ///
    ////////////////////////////////////////////////////////////
    State& getCurrentState() const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la informacion compartida por las escenas
    /// \return Referencia a la informacion compartida
    ///
    ////////////////////////////////////////////////////////////
    SharedContext& getSharedContext() const;

    ////////////////////////////////////////////////////////////
    /// \brief Delega el control a la escena actual
    /// \param event Evento producido por el usuario
    ///
    ////////////////////////////////////////////////////////////
    void handleInput(const sf::Event& event);

    ////////////////////////////////////////////////////////////
    /// \brief Delega el control a la escena actual
    /// \param dt Porcion de tiempo
    ///
    ////////////////////////////////////////////////////////////
    void update(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief Delega el control a la escena actual
    ///
    ////////////////////////////////////////////////////////////
    void draw();

private:
    std::unique_ptr<SharedContext>   shdContex;    ///< Informacion compartida
    State*                           currentState; ///< Escena actual
    std::map<States::ID, State::Ptr> states;       ///< Todas las escenas existentes
    std::map<Transitions::ID, Transition::Ptr> transitions; /// Efectos transitorios
};

#endif // STATEMANAGER_H
