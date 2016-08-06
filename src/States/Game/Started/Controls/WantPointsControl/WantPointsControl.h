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
class WantPointsControl
{
public:
    using Ptr = std::unique_ptr<WantPointsControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control para los puntos deseados
    /// \param wantPoints Puntos deseados
    /// \param position Posicion de la barra en la escena
    /// \param start Rect en textura de la rep. grafica inicial
    /// \param middle Rect en textura de la rep. grafica de en medio
    /// \param end Rect en textura de la rep. grafica final
    /// \param total Rect de la rep. grafica total: start + middle + end
    /// \param texture Textura de donde se obtienen los graficos
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
    /// \brief Obtiene la representacion grafica
    /// \return Referencia hacia la rep. grafica
    ///
    ////////////////////////////////////////////////////////////
    const TextureBar::Graph& getGraph() const;

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
    float defWidth;         ///< Ancho total de la rep. grafica
    OneDirectionBar graph;  ///< Representacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la representacion grafica
    ///
    ////////////////////////////////////////////////////////////
    void updateGraph();
};

#endif // WANTPOINTSCONTROL_H
