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

#ifndef SHIFTMODECONTROL_H
#define SHIFTMODECONTROL_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico del modo Shift
///
////////////////////////////////////////////////////////////
class ShiftModeControl
{
public:
    using Ptr = std::unique_ptr<ShiftModeControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control para el modo Shift
    /// \param duration Duracion del modo
    /// \param necessary Tiempo de recarga
    /// \param color Color de la representacion grafica
    /// \param rect Posicion y dimension de la rep. grafica
    ///
    ////////////////////////////////////////////////////////////
    ShiftModeControl(const sf::Time& duration,
                     const sf::Time& necessary,
                     const sf::Color& color,
                     const sf::FloatRect rect);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza el control
    /// \param dt Intervalo de tiempo
    ///
    ////////////////////////////////////////////////////////////
    void update(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la representacion grafica
    /// \return Referencia hacia el rectangulo grafico
    ///
    ////////////////////////////////////////////////////////////
    const sf::RectangleShape& getGraph() const;

    ////////////////////////////////////////////////////////////
    /// \brief Activa el modo Shift
    ///
    ////////////////////////////////////////////////////////////
    void active();

    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si se puede activar el modo
    /// \return True = Es posible activar el modo
    ///
    ////////////////////////////////////////////////////////////
    bool canActive() const;

    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si esta activado el modo
    /// \return True = Activo
    ///
    ////////////////////////////////////////////////////////////
    bool isActive() const;

private:
    sf::Time elapsed;         ///< Tiempo transcurrido
    sf::Time duration;        ///< Duracion del modo
    sf::Time necessary;       ///< Tiempo de recarga
    bool     canActiveShift;  ///< Es posible activar el modo
    bool     isShiftActive;   ///< Esta activado el modo
    float    defXpos;         ///< Posicion por defecto del graph
    float    defWidth;        ///< Anchura por defecto dle graph
    sf::RectangleShape graph; ///< Representacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la representacion grafica
    /// \param isGrowing Identifica si el control esta creciendo
    ///
    ////////////////////////////////////////////////////////////
    void updateGraph(bool isGrowing);
};

#endif // SHIFTMODECONTROL_H
