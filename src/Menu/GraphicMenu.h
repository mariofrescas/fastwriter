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

#ifndef GRAPHICSMENU_H
#define GRAPHICSMENU_H

#include <list>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe un menu logico-grafico
///
////////////////////////////////////////////////////////////
class GraphicMenu
{
public:
    using Ptr = std::unique_ptr<GraphicMenu>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Informacion acerca de cada uno de las opciones del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuOptionData
    {
        std::function<void()> action; ///< Acciona cuando se de click
        sf::Vector2f pos;             ///< Posicion
        sf::IntRect normal;           ///< Rect en textura en estado normal
        sf::IntRect hover;            ///< Rect en textura en estado "hover"
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe una opcion de menu logica-grafica
    ///
    ////////////////////////////////////////////////////////////
    struct MenuOption
    {
        MenuOptionData data; ///< Informacion
        sf::Sprite graph;    ///< Rep. grafica
    };

    ////////////////////////////////////////////////////////////
    /// \brief Informacion acerca del contenedor del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuContainerData
    {
        sf::Vector2f pos; ///< Posicion
        sf::IntRect rect; ///< Rect en la textura
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe el contenedor del menu logico-grafico
    ///
    ////////////////////////////////////////////////////////////
    struct MenuContainer
    {
        MenuContainerData data; ///< Informacion
        sf::Sprite graph;       ///< Rep. grafica
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe la union contenedor-opciones
    ///
    ////////////////////////////////////////////////////////////
    struct Menu
    {
        std::list<MenuOption> options; ///< Opciones logica-grafica
        MenuContainer container;       ///< Contenedor logico-grafico
    };

    ////////////////////////////////////////////////////////////
    /// \brief Crea un menu grafico
    /// \param menusData Informacion acerca de las opciones del menu
    /// \param containerData Informacion acerca del contenedor del menu
    /// \param texture Textura donde se encuentran los elementros del menu
    ///
    ////////////////////////////////////////////////////////////
    GraphicMenu(const std::list<MenuOptionData>& menusData,
                const MenuContainerData& containerData,
                const sf::Texture& texture);


    ////////////////////////////////////////////////////////////
    /// \brief Cambia de color el texto si el cursor se encuentra
    ///        en alguna opcion del menu
    /// \param point Posicion del cursor
    ///
    ////////////////////////////////////////////////////////////
    void setCurrentOption(const sf::Vector2f& point);

    ////////////////////////////////////////////////////////////
    /// \brief Ejecuta la "action" del menu que se encuentra en point
    /// \param point Posicion del cursor
    ///
    ////////////////////////////////////////////////////////////
    void execCurrentOption(const sf::Vector2f& point);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene el menu grafico
    /// \return Referencia hacia el menu
    ///
    ////////////////////////////////////////////////////////////
    const Menu& getGraphicMenu() const;

private:
    Menu menu; ///< Menu grafico
};
#endif // GRAPHICSMENU_H
