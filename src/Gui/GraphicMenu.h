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
    /// \brief Informacion acerca de cada una de las opciones del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuOptionData
    {
        std::function<void()> action; ///< Accion cuando se de click
        sf::Vector2f pos;             ///< Posicion
        sf::IntRect normal;           ///< Rect en textura en estado normal
        sf::IntRect hover;            ///< Rect en textura en estado "hover"
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe una opcion logica-grafica de menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuOption
    {
        MenuOptionData data;  ///< Informacion
        sf::Sprite     graph; ///< Rep. grafica
    };

    ////////////////////////////////////////////////////////////
    /// \brief Informacion acerca del contenedor del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuContainerData
    {
        sf::Vector2f pos;  ///< Posicion
        sf::IntRect  rect; ///< Rect en la textura
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe el contenedor logico-grafico del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuContainer
    {
        MenuContainerData data;  ///< Informacion
        sf::Sprite        graph; ///< Rep. grafica
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe la union contenedor-opciones
    ///
    ////////////////////////////////////////////////////////////
    struct Menu
    {
        std::list<MenuOption> options;   ///< Opciones logico-grafico
        MenuContainer         container; ///< Contenedor logico-grafico
    };

    ////////////////////////////////////////////////////////////
    /// \brief Crea un menu grafico
    /// \param menusData Informacion acerca de las opciones del menu
    /// \param containerData Informacion acerca del contenedor del menu
    /// \param texture Textura donde se encuentran los elementros del menu
    ///
    ////////////////////////////////////////////////////////////
    GraphicMenu(const std::list<MenuOptionData>& menuData,
                const MenuContainerData& containerData,
                const sf::Texture& texture);


    ////////////////////////////////////////////////////////////
    /// \brief Cambia de color el texto si el cursor se encuentra
    ///        sobre alguna opcion del menu
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
