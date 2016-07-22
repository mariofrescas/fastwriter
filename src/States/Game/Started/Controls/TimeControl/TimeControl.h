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