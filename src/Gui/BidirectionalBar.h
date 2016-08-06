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

#ifndef BIDIRECTIONALBAR_H
#define BIDIRECTIONALBAR_H

#include "TextureBar.h"

////////////////////////////////////////////////////////////
/// \brief Barra bidireccional (centro - afuera) (afuera - centro)
///
////////////////////////////////////////////////////////////
class BidirectionalBar : public TextureBar
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Crea una barra bidireccional
    /// \param position Posicion de la barra en la escena
    /// \param start Rect en textura de la rep. grafica inicial
    /// \param middle Rect en textura de la rep. grafica de en medio
    /// \param end Rect en textura de la rep. grafica final
    /// \param total Rect de la rep. grafica total: start + middle + end
    /// \param texture Textura de donde se obtienen los graficos
    ///
    ////////////////////////////////////////////////////////////
    BidirectionalBar(const sf::Vector2f& position,
                     const sf::IntRect& start,
                     const sf::IntRect& middle,
                     const sf::IntRect& end,
                     const sf::IntRect& total,
                     const sf::Texture& texture);

protected:
    ////////////////////////////////////////////////////////////
    /// \brief Ajusta la dimencion y la posicion de la barra
    /// \param size Nuevo tamaño de la barra
    ///
    ////////////////////////////////////////////////////////////
    virtual void updateMiddle(float size) override;
};

#endif // BIDIRECTIONALBAR_H
