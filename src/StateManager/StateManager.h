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

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <map>
#include "State.h"
#include "Transition.h"

class MusicPlayer;
class SoundPlayer;
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
        Black,         ///< Escena negra de entrada
        Wellcome,      ///< Bienvenida
        MainMenu,      ///< Menu principal
        About,         ///< Acerca de...
        DifftyMenu,    ///< Menu de seleccion de dificultad
        Starting,      ///< Iniciando el juego
        Started,       ///< Juego iniciado
        Paused,        ///< Juego pausado
        QuitConfirm,   ///< Confirmar quitar el juego
        RestartConfirm ///< Confirmar reiniciar el juego
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
        /// \param musicPlayer Referencia hacia el administrador de temas
        /// \param soundPlayer Referencia hacia el administrador de sonidos
        /// \param resManager Referencia hacia el administrador de recursos
        ///
        ////////////////////////////////////////////////////////////
        SharedContext(sf::RenderWindow& window,
                      MusicPlayer& musicPlayer,
                      SoundPlayer& soundPlayer,
                      ResourceManager& resManager);

        sf::RenderWindow& window;          ///< Ventana donde trabajaran las escenas
        MusicPlayer&      musicPlayer;     ///< Administrador de temas
        SoundPlayer&      soundPlayer;     ///< Administrador de sonidos
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
    /// \brief Obtiene la escena correspondiente
    /// \param state Esena requerida
    /// \return Referencia hacia la escena requerida
    ///
    ////////////////////////////////////////////////////////////
    State& getState(const States::ID& state);

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
