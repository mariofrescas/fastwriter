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
class GraphicMenu : public sf::Drawable, public sf::Transformable
{
public:
    using Ptr = std::unique_ptr<GraphicMenu>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Info. acerca de cada una de las opciones del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuOptionData
    {
        std::function<void()> action; ///< Accion de la opcion
        sf::Vector2f pos;             ///< Posicion en la escena
        sf::IntRect normal;           ///< Rect de la rep. graf. "normal" en la textura
        sf::IntRect hover;            ///< Rect de la rep. graf. "sobre" en la textura
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe una opcion logica-grafica de menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuOption
    {
        MenuOptionData data;  ///< Info.
        sf::Sprite     graph; ///< Rep. graf.
    };

    ////////////////////////////////////////////////////////////
    /// \brief Info. acerca del contenedor del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuContainerData
    {
        sf::Vector2f pos;  ///< Posicion en la escena
        sf::IntRect  rect; ///< Rect de la rep. graf. en la textura
    };

    ////////////////////////////////////////////////////////////
    /// \brief Describe el contenedor logico-grafico del menu
    ///
    ////////////////////////////////////////////////////////////
    struct MenuContainer
    {
        MenuContainerData data;  ///< Info.
        sf::Sprite        graph; ///< Rep. graf.
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
    /// \brief Crea un menu logico-grafico
    /// \param menuData Info. acerca de las opciones del menu
    /// \param containerData Info. acerca del contenedor del menu
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    GraphicMenu(const std::list<MenuOptionData>& menuData,
                const MenuContainerData& containerData,
                const sf::Texture& texture);


    ////////////////////////////////////////////////////////////
    /// \brief Cambia la rep. graf. "normal" por "sobre" que se
    ///        encuentra bajo el cursor
    /// \param point Posicion del cursor
    ///
    ////////////////////////////////////////////////////////////
    void setCurrentOption(const sf::Vector2f& point);

    ////////////////////////////////////////////////////////////
    /// \brief Ejecuta la accion del menu que se encuentra bajo el cursor
    /// \param point Posicion del cursor
    ///
    ////////////////////////////////////////////////////////////
    void execCurrentOption(const sf::Vector2f& point);

private:
    Menu menu; ///< Menu grafico

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const override;
};
#endif // GRAPHICSMENU_H
