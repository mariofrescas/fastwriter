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

#ifndef SCORESCONTROL_H
#define SCORESCONTROL_H

#include <array>
#include <string>
#include <memory>
#include <SFML/Graphics/Text.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control grafico de puntuaciones (matriz)
///
////////////////////////////////////////////////////////////
class ScoresControl : public sf::Drawable, public sf::Transformable
{
public:
    using Ptr = std::unique_ptr<ScoresControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de puntuciones (matriz)
    /// \param filename Ubicacion del archivo
    /// \param font Fuente de la rep. graf.
    /// \param x Posiciones en x de las columnas
    /// \param y Posiciones en y de las filas
    ///
    ////////////////////////////////////////////////////////////
    ScoresControl(const std::string& filename,
                  const sf::Font& font,
                  const std::array<int, 6>& x,
                  const std::array<int, 10>& y);

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza el control con el archivo de puntuaciones
    ///
    ////////////////////////////////////////////////////////////
    void update();

private:
    using ScoresMatrix = std::array<std::array<sf::Text, 10>, 6>; ///< Matriz de puntuaciones

    std::string         filename; ///< Ubicacion del archivo
    const sf::Font&     font;     ///< Fuente de la rep. graf.
    std::array<int, 6>  x;        ///< Posiciones en x de las columnas
    std::array<int, 10> y;        ///< Posiciones en y de las filas
    ScoresMatrix        scores;   ///< Rep. graf.

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja la rep. graf.
    /// \param target Objetivo donde se dibujara
    /// \param states Estados de renderizacion
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget &target,
                      sf::RenderStates states) const override;
};

#endif // SCORESCONTROL_H
