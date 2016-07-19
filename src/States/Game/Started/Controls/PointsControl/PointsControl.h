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

#ifndef POINTSCONTROL_H
#define POINTSCONTROL_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de puntos
///
////////////////////////////////////////////////////////////
class PointsControl
{
public:
    using Ptr = std::unique_ptr<PointsControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de puntos
    /// \param charSize Tamaño del texto grafico
    /// \param position Posicion del texto grafico
    /// \param font Fuente del texto grafico
    ///
    ////////////////////////////////////////////////////////////
    PointsControl(unsigned charSize,
                  const sf::Vector2f& position,
                  const sf::Font& font);

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
    const sf::Text& getGraph() const;

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa los puntos en el control
    /// \param increment Incremento en los puntos
    ///
    ////////////////////////////////////////////////////////////
    void increment(int increment);

    ////////////////////////////////////////////////////////////
    /// \brief Decrementa los puntos en el control
    /// \param decrement Decremento en los puntos
    ///
    ////////////////////////////////////////////////////////////
    void decrement(int decrement);

private:
    int      points; ///< Puntos
    sf::Text graph;  ///< Representacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la representacion grafica
    ///
    ////////////////////////////////////////////////////////////
    void updateGraph();
};

#endif // POINTSCONTROL_H
