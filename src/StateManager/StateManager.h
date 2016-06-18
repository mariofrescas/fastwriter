#ifndef STATEMANAGER_H
#define STATEMANAGER_H

////////////////////////////////////////////////////////////
/// \brief Inclusiones internas
///
////////////////////////////////////////////////////////////
#include <map>
#include <stack>
#include <memory>

#include "State.h"

////////////////////////////////////////////////////////////
/// \brief Declaraciones fordward
///
////////////////////////////////////////////////////////////
class ResourceManager;

namespace sf
{
    class RenderWindow;
}

////////////////////////////////////////////////////////////
/// \brief Define la administracion de las escenas
///
/// @note Escena Actual: Hace referencia a la escena que tiene
/// la posicion mas alta en la pila de escenas.
///
////////////////////////////////////////////////////////////
class StateManager
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Define los tipos de escenas existentes
    ///
    ////////////////////////////////////////////////////////////
    enum class StateType
    {
        ConcreteState1, ///< Ejemplo 1 de implementacion de escena
        ConcreteState2  ///< Ejemplo 2 de implementacion de escena
    };

    ////////////////////////////////////////////////////////////
    /// \brief Define la informacion compartida por las escenas
    ///
    ////////////////////////////////////////////////////////////
    struct SharedContext
    {
        ////////////////////////////////////////////////////////////
        /// \brief Almacena referencias hacia la informacion compartida
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
    /// Crea un objeto SharedContext y copia los valores del parametro shareContext
    /// de esta menera el administrador es independiente al objeto parametro.
    ///
    ////////////////////////////////////////////////////////////
    explicit StateManager(const SharedContext& sharedContex);

    ////////////////////////////////////////////////////////////
    /// \brief Agrega la escena en lo mas alto de la pila
    /// \param state Llave que identifica la escena dentro del mapa de escenas
    ///
    /// Del mapa de escenas selecciona el que tiene una llave con un valor
    /// igual al del parametro state y lo agrega a la pilia de escenas.
    ///
    ////////////////////////////////////////////////////////////
    void pushState(const StateType& state);

    ////////////////////////////////////////////////////////////
    /// \brief Quita la ultima escena agregada de lo mas alto de la pila
    ///
    ////////////////////////////////////////////////////////////
    void popState();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la informacion compartida por las escenas
    /// \return Referencia a la informacion compartida
    ///
    ////////////////////////////////////////////////////////////
    SharedContext& getSharedContext() const;

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la logica de la escena actual
    /// \param event Evento producido por el usuario
    ///
    ////////////////////////////////////////////////////////////
    void handleInput(const sf::Event& event);

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza los EG de la escena actual en base a la logica
    /// \param dt Tiempo transcurrido desde la ultima ejecucion del update
    ///
    /// \note EG: Elementos Graficos
    ///
    ////////////////////////////////////////////////////////////
    void update(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja los elementos graficos de la escena actual
    ///
    ////////////////////////////////////////////////////////////
    void draw();

private:
    std::unique_ptr<SharedContext>  shdContex;  ///< Informacion compartida por las escenas
    std::stack<State*>              stateStack; ///< Flujo de las escenas existentes
    std::map<StateType, State::Ptr> states;     ///< Todas las escenas existentes
};

#endif // STATEMANAGER_H
