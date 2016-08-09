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
#include "BidirectionalBar.h"
#include <SFML/System/Time.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico del modo Shift
///
////////////////////////////////////////////////////////////
class ShiftModeControl : public sf::Drawable, public sf::Transformable
{
public:
    using Ptr = std::unique_ptr<ShiftModeControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control para el modo Shift
    /// \param duration Duracion del modo
    /// \param necessary Tiempo de recarga
    /// \param position Posicion del control en la escena
    /// \param start Rect de la rep. graf. de la parte inicial en la textura
    /// \param middle Rect de la rep. graf. de la parte mediana en la textura
    /// \param end Rect de la rep. graf. de la parte final en la textura
    /// \param total Rect de la rep. graf. total: start + middle + end
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    ShiftModeControl(const sf::Time& duration,
                     const sf::Time& necessary,
                     const sf::Vector2f& position,
                     const sf::IntRect& start,
                     const sf::IntRect& middle,
                     const sf::IntRect& end,
                     const sf::IntRect& total,
                     const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Reconfigura las propiedades del control
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
    float    defWidth;        ///< Anchura total de la barra
    BidirectionalBar graph;   ///< Rep. graf.

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    void updateGraph(bool isGrowing);

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget &target,
                      sf::RenderStates states) const override;
};

#endif // SHIFTMODECONTROL_H
