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

#ifndef TEXTUREBAR_H
#define TEXTUREBAR_H

#include <SFML/Graphics/RectangleShape.hpp>

namespace sf
{
    class Time;
}

////////////////////////////////////////////////////////////
/// \brief Describe una rep. graf. de una barra redimensionable
///
////////////////////////////////////////////////////////////
class TextureBar : public sf::Drawable, public sf::Transformable
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Crea una rep. graf. de una barra redimensionable
    /// \param position Posicion de la barra en la escena
    /// \param start Rect de la rep. graf. de la parte inicial en la textura
    /// \param middle Rect de la rep. graf. de la parte mediana en la textura
    /// \param end Rect de la rep. graf. de la parte final en la textura
    /// \param total Rect de la rep. graf. total: start + middle + end
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    TextureBar(const sf::Vector2f& position,
               const sf::IntRect& start,
               const sf::IntRect& middle,
               const sf::IntRect& end,
               const sf::IntRect& total,
               const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Llena la barra completamente
    ///
    ////////////////////////////////////////////////////////////
    void fillFull();

    ////////////////////////////////////////////////////////////
    /// \brief Vacia la barra a un minimo aceptable start.w + 1 + end.w
    ///
    ////////////////////////////////////////////////////////////
    void empty();

    ////////////////////////////////////////////////////////////
    /// \brief Ajusta el tamaño de la barra
    /// \param size Nuevo tamaño de la barra
    ///
    ////////////////////////////////////////////////////////////
    void adjustMiddle(float size);

    ////////////////////////////////////////////////////////////
    /// \brief Destructor virtual!
    ///
    ////////////////////////////////////////////////////////////
    virtual ~TextureBar();

protected:
    sf::RectangleShape middle; ///< Rep. graf. mediana

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza las propiedades de la rep. graf. mediana
    /// \param size Nuevo tamaño de la barra
    ///
    ////////////////////////////////////////////////////////////
    virtual void updateMiddle(float size) = 0;

private:
    float              defX;  ///< Posicion inicial de la rep. mediana
    sf::IntRect        total; ///< Rect de la rep. total
    sf::RectangleShape start; ///< Rep. grafica de inicio
    sf::RectangleShape end;   ///< Rep. grafica final

    ////////////////////////////////////////////////////////////
    /// \brief Ajusta las posiciones de las rep. graf. de inicio y final
    ///        con respecto a la rep. graf. mediana (start - middle - final)
    ///
    ////////////////////////////////////////////////////////////
    void updateEdges();


    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si la barra esta llena
    /// \return True = Completamente llena
    ///
    ////////////////////////////////////////////////////////////
    bool checkIsFullGrown();

    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si la barra esta vacia con minimo aceptable
    /// \return True = Completamente vacia
    ///
    ////////////////////////////////////////////////////////////
    bool checkIsFullShrank();

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const override;
};

#endif // TEXTUREBAR_H
