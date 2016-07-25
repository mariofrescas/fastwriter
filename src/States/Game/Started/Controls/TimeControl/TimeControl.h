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

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico del tiempo
///
////////////////////////////////////////////////////////////
class TimeControl
{
public:
    using Ptr = std::unique_ptr<TimeControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de tiempo
    /// \param charSize Tamaño del texto grafico
    /// \param position Posicion del texto grafico
    /// \param font Fuente del texto grafico
    ///
    ////////////////////////////////////////////////////////////
    TimeControl(unsigned charSize,
                const sf::Vector2f& position,
                const sf::Font& font);

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
    /// \return Referencia hacia el texto grafico
    ///
    ////////////////////////////////////////////////////////////
    const sf::Text& getGraph() const;

private:
    sf::Time elapsed; ///< Tiempo transcurrido
    sf::Text graph;   ///< Representacion grafica
};

#endif // TIMECONTROL_H
