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

#ifndef WANTPOINTSCONTROL_H
#define WANTPOINTSCONTROL_H

#include <memory>
#include "OneDirectionBar.h"

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de puntos deseados
///
////////////////////////////////////////////////////////////
class WantPointsControl : public sf::Drawable, public sf::Transformable
{
public:
    using Ptr = std::unique_ptr<WantPointsControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control para los puntos deseados
    /// \param wantPoints Puntos deseados
    /// \param position Posicion del control en la escena
    /// \param start Rect de la rep. graf. de la parte inicial en la textura
    /// \param middle Rect de la rep. graf. de la parte mediana en la textura
    /// \param end Rect de la rep. graf. de la parte final en la textura
    /// \param total Rect de la rep. graf. total: start + middle + end
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    WantPointsControl(int wantPoints,
                      const sf::Vector2f& position,
                      const sf::IntRect& start,
                      const sf::IntRect& middle,
                      const sf::IntRect& end,
                      const sf::IntRect& total,
                      const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Aumenta los puntos base
    /// \param increment Incremento en los puntos
    ///
    ////////////////////////////////////////////////////////////
    void addPoints(int increment);

    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si ya se tienen todos los puntos deseados
    /// \return True = Ya se tienen todos los puntos
    ///
    ////////////////////////////////////////////////////////////
    bool isFull() const;

private:
    int   points;           ///< Puntos base
    int   wantPoints;       ///< Puntos deseados
    bool  isWantPointsFull; ///< Ya se tienen todos los puntos deseados
    float defWidth;         ///< Anchura total de la barra
    OneDirectionBar graph;  ///< Rep. graf.

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

#endif // WANTPOINTSCONTROL_H
