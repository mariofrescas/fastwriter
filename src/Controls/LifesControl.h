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

#ifndef LIFESCONTROL_H
#define LIFESCONTROL_H

#include <array>
#include <memory>
#include "TextureNumber.h"

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de vidas
///
////////////////////////////////////////////////////////////
class LifesControl : public sf::Drawable, public sf::Transformable
{
public:
    typedef std::unique_ptr<LifesControl> Ptr; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de vidas
    /// \param defaultLifes Numero inicial de vidas
    /// \param position Posicion del control en la escena
    /// \param rects Rect de la rep. graf. en la textura
    /// \param texture Textura de las rep. graf.
    ///
    ////////////////////////////////////////////////////////////
    LifesControl(int defaultLifes,
                 const sf::Vector2f& position,
                 const std::array<sf::IntRect, 10>& rects,
                 const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Reconfigura las propiedades del control
    /// \param defaultLifes Vidas por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reconfigure(int defaultLifes);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa los puntos de vida
    /// \param increment Incremento en la vida
    ///
    ////////////////////////////////////////////////////////////
    void increment(int increment);

    ////////////////////////////////////////////////////////////
    /// \brief Decrementa los puntos de vida
    /// \param decrement Decremento en la vida
    ///
    ////////////////////////////////////////////////////////////
    void decrement(int decrement);

    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si aun quedan vidas
    /// \return True = Aun quedan vidas
    ///
    ////////////////////////////////////////////////////////////
    bool remain() const;

private:
    int              lifes;        ///< Numero de vidas
    int              defaultLifes; ///< Vidas por defecto
    bool             remainLifes;  ///< Aun quedan vidas
    TextureNumber<5> graph;        ///< Rep. graf. de vidas

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

#endif // LIFESCONTROL_H
