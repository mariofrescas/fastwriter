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

#ifndef TIMECONTROL_H
#define TIMECONTROL_H

#include <array>
#include <memory>
#include "TextureNumber.h"
#include <SFML/System/Time.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de un reloj (hh:mm:ss)
///
////////////////////////////////////////////////////////////
class TimeControl : public sf::Drawable, public sf::Transformable
{
public:
    using Ptr = std::unique_ptr<TimeControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de reloj (hh:mm:ss)
    /// \param position Posicion del control en la escena
    /// \param rects Rects de las rep. graf. en la textura
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    TimeControl(const sf::Vector2f& position,
                const std::array<sf::IntRect, 11>& rects,
                const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa el tiempo transcurrido
    /// \param dt Intervalo de tiempo transcurrido
    ///
    ////////////////////////////////////////////////////////////
    void tick(const sf::Time& dt);

private:
    sf::Time         elapsed;    ///< Tiempo transcurrido
    TextureNumber<2> hours;      ///< Rep. graf. de las horas
    sf::Sprite       separator1; ///< Separador : de horas-minutos
    TextureNumber<2> minutes;    ///< Rep. graf. de los minutos
    sf::Sprite       separator2; ///< Separador : de minutos-segundos
    TextureNumber<2> seconds;    ///< Rep. graf. de los segundos

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget &target,
                      sf::RenderStates states) const override;
};

#endif // TIMECONTROL_H
