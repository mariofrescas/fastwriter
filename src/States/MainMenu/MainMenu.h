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

#ifndef MAINMENU_H
#define MAINMENU_H

////////////////////////////////////////////////////////////
// Cabeceras
//
////////////////////////////////////////////////////////////
#include "State.h"

#include <map>
#include <SFML/Graphics/Sprite.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe la escena del menu principal
///
////////////////////////////////////////////////////////////
class MainMenu : public State
{
private:
    ////////////////////////////////////////////////////////////
    /// \brief Describe las opciones de seleccion para el menu
    ///
    ////////////////////////////////////////////////////////////
    enum class Options
    {
        None,    ///< Ninguna opcion
        NewGame, ///< Juego nuevo
        Scores,  ///< Puntuaciones
        Help,    ///< Ayuda
        About,   ///< Informacion
        Exit     ///< Salir del juego
    };

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

    using RectPair = std::pair<sf::IntRect, sf::IntRect>;

public:

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa la escena del menu principal
    ///
    ////////////////////////////////////////////////////////////
    explicit MainMenu(StateManager& stateManager);

    ////////////////////////////////////////////////////////////
    /// \brief Reacciona al click y al movimiento del cursor
    /// \param event Evento producido por el usuario
    /// \see handleMouseMoved
    /// \see handleMousePressed
    ///
    /// Si la escena termino de mostrarse:
    /// Llama a handelMouseMove en caso de que el cursor se mueva
    /// o llama a handleMousePressed en caso de que se de un click.
    ///
    ////////////////////////////////////////////////////////////
    virtual void handleInput(const sf::Event& event) override;

    ////////////////////////////////////////////////////////////
    /// \brief Oscurece/muestra el menu de una manera progresiva
    ///
    /// Al terminar de ocultar indica a menuOptionPressed que
    /// reaccione a la opcion del menu en la que se dio el click.
    ///
    ////////////////////////////////////////////////////////////
    virtual void update(const sf::Time& dt) override;

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja los elementos graficos
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw() override;

private:
    sf::Sprite                    background;    ///< Sprite de fondo
    std::map<Options, RectPair>   menuRects;     ///< Posiciones de los sprites en la textura
    std::map<Options, sf::Sprite> menuSprites;   ///< Sprites del menu
    Options                       currentOption; ///< Opcion en la que se encuentra el cursor
    Options                       clickedOption; ///< Opcion en la que se dio click

private:

    ////////////////////////////////////////////////////////////
    /// \brief Identfica cual es la opcion del menu en la que se encuentra el cursor
    /// \param x Coordenada en el eje X
    /// \param y Coordenada en el eje Y
    /// \see setCurrentOption
    ///
    /// Indica a setCurrentOption que cambie la opcion seleccionada.
    ///
    ////////////////////////////////////////////////////////////
    void handleMouseMoved(int x, int y);

    ////////////////////////////////////////////////////////////
    /// \brief Cambia la posicion del sprite en la textura de la opcion seleccionada
    /// \param option Opcion del menu en la que se encuentra el cursor
    /// \see handleMouseMoved
    ///
    /// Cambia la posicion del sprite de la opcion proporcionada
    /// dentro de la textura para que tenga una imagen de seleccionada.
    ///
    ////////////////////////////////////////////////////////////
    void setCurrentOption(const Options& option);

    ////////////////////////////////////////////////////////////
    /// \brief Identfica la opcion del menu en la que se dio click
    /// \param x Coordenada en el eje X
    /// \param y Coordenada en el eje Y
    ///
    /// Inicia el proceso de ocultacion del menu y almacena cual
    /// es la opcion del menu en la que se dio el click.
    ///
    ////////////////////////////////////////////////////////////
    void handleMousePressed(int x, int y);

    ////////////////////////////////////////////////////////////
    /// \brief Reacciona al click del usuario en alguna opcion del menu
    /// \param option Opcion del menu en la que se dio click
    /// \see handleMousePressed
    ///
    /// Acciones:
    /// * NewGame: Procede a la escena de juego
    /// * Scores:
    /// * Help:
    /// * About:
    /// * Exit: Termina la aplicacion
    ///
    ////////////////////////////////////////////////////////////
    void menuOptionPressed(const Options& option);

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa las posiciones de los sprites en la textura
    ///
    ////////////////////////////////////////////////////////////
    void initMenuRects();

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa los sprites del menu
    ///
    ////////////////////////////////////////////////////////////
    void initMenuSprites();

    ////////////////////////////////////////////////////////////
    /// \brief Inicializa las posiciones de los sprites del menu
    ///
    ////////////////////////////////////////////////////////////
    void initMenuPositions();
};

#endif // MAINMENU_H
