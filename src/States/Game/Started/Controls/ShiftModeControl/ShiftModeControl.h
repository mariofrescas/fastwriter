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

#ifndef SHIFTMODECONTROL_H
#define SHIFTMODECONTROL_H

#include <memory>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

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
    /// \brief Reconfigura las propiedades del control del modo Shift
    /// \param duration Duracion del modo
    /// \param necessary Tiempo de recarga
    ///
    ////////////////////////////////////////////////////////////
    void reconfigure(const sf::Time& duration,
                     const sf::Time& necessary);

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
