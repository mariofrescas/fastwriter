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

#ifndef POINTSCONTROL_H
#define POINTSCONTROL_H

#include <array>
#include <memory>
#include "TextureNumber.h"

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de puntos
///
////////////////////////////////////////////////////////////
class PointsControl : public sf::Drawable, public sf::Transformable
{
public:
    using Ptr = std::unique_ptr<PointsControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de puntos
    /// \param position Posicion del control en la escena
    /// \param rects Rects de las rep. graf. en la textura
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    PointsControl(const sf::Vector2f& position,
                  const std::array<sf::IntRect, 10>& rects,
                  const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa los puntos
    /// \param increment Incremento en los puntos
    ///
    ////////////////////////////////////////////////////////////
    void increment(int increment);

    ////////////////////////////////////////////////////////////
    /// \brief Decrementa los puntos
    /// \param decrement Decremento en los puntos
    ///
    ////////////////////////////////////////////////////////////
    void decrement(int decrement);

private:
    int              points; ///< Puntos
    TextureNumber<5> graph;  ///< Rep. graf. de vidas

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    void updateGraph();

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget &target,
                      sf::RenderStates states) const override;
};

#endif // POINTSCONTROL_H
