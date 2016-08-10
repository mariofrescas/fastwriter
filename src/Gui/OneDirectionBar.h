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

#ifndef ONEDIRECTIONBAR_H
#define ONEDIRECTIONBAR_H

#include "TextureBar.h"

////////////////////////////////////////////////////////////
/// \brief Barra de una sola direccion (derecha - izquierda)
///
////////////////////////////////////////////////////////////
class OneDirectionBar : public TextureBar
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Crea una barra de una sola direccion
    /// \param position Posicion de la barra en la escena
    /// \param start Rect de la rep. graf. de la parte inicial en la textura
    /// \param middle Rect de la rep. graf. de la parte mediana en la textura
    /// \param end Rect de la rep. graf. de la parte final en la textura
    /// \param total Rect de la rep. graf. total: start + middle + end
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    OneDirectionBar(const sf::Vector2f& position,
                    const sf::IntRect& start,
                    const sf::IntRect& middle,
                    const sf::IntRect& end,
                    const sf::IntRect& total,
                    const sf::Texture& texture);

protected:
    ////////////////////////////////////////////////////////////
    /// \brief Actualiza las propiedades de la rep. graf. mediana
    /// \param size Nuevo tamaño de la barra
    ///
    ////////////////////////////////////////////////////////////
    virtual void updateMiddle(float size) override;
};

#endif // ONEDIRECTIONBAR_H
