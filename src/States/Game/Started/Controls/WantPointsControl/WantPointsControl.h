/*************************************************************************
** Copyright (C) 2016 Sysyfydev <sysyfydev@gmail.com>.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*************************************************************************/

#ifndef WANTPOINTSCONTROL_H
#define WANTPOINTSCONTROL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

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
