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

#ifndef TEXTURENUMBER_H
#define TEXTURENUMBER_H

#include <map>
#include <array>
#include <SFML/Graphics/Sprite.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe una rep. graf. de un grupo de numeros
/// \tparam Number Tamaño del grupo de numeros
///
////////////////////////////////////////////////////////////
template<std::size_t Number>
class TextureNumber : public sf::Drawable, public sf::Transformable
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Crea una rep. graf. de un grupo de numeros
    /// \param position Posicion del grupo en la escena
    /// \param rects Rects de las rep. graf. en la textura
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    TextureNumber(const sf::Vector2f& position,
                  const std::array<sf::IntRect, 10>& rects,
                  const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Cambia el grupo de numeros por uno nuevo
    /// \param number Nuevo grupo de numeros
    ///
    ////////////////////////////////////////////////////////////
    void setNumber(const std::string& number);

private:
    std::array<sf::Sprite, Number> sprites; ///< Rep. graf. del grupo de numeros
    std::map<char, sf::IntRect>    rects;   ///< Rects de las rep. graf. en la textura

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const override;
};

#include "TextureNumber.inl"

#endif // TEXTURENUMBER_H
