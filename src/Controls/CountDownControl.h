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

#ifndef COUNTDOWNCONTROL_H
#define COUNTDOWNCONTROL_H

#include <memory>
#include "TextureNumber.h"
#include <SFML/System/Time.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de cuenta regresiva
///
////////////////////////////////////////////////////////////
class CountDownControl : public sf::Drawable, public sf::Transformable
{
public:
    using Ptr = std::unique_ptr<CountDownControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de cuenta regresiva
    /// \param start Duracion de la cuenta
    /// \param position Posicion del control en la escena
    /// \param rects Rects de las rep. graf. en la textura
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    CountDownControl(const sf::Time& start,
                     const sf::Vector2f& position,
                     const std::array<sf::IntRect, 10>& rects,
                     const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Agregra el tiempo dt y comprueba si la cuenta ya termino
    /// \param dt Intervalo de tiempo a agregar
    /// \return True = La cuenta ya termino
    ///
    ////////////////////////////////////////////////////////////
    bool finished(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

private:
    sf::Time         start;   ///< Duracion de la cuenta
    sf::Time         elapsed; ///< Tiempo transcurrido
    TextureNumber<1> graph;   ///< Representacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget &target,
                      sf::RenderStates states) const override;
};

#endif // COUNTDOWNCONTROL_H
