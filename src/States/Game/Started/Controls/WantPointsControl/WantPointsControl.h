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
#include <SFML/Graphics/RectangleShape.hpp>

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
    /// \param color Color de la representacion grafica
    /// \param rect Posicion y dimension de la rep. grafica
    ///
    ////////////////////////////////////////////////////////////
    WantPointsControl(int wantPoints,
                      const sf::Color& color,
                      const sf::FloatRect& rect);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la representacion grafica
    /// \return Referencia hacia el texto grafico
    ///
    ////////////////////////////////////////////////////////////
    const sf::RectangleShape& getGraph() const;

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
    sf::RectangleShape graph; ///< Representacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la representacion grafica
    ///
    ////////////////////////////////////////////////////////////
    void updateGraph();
};

#endif // WANTPOINTSCONTROL_H
