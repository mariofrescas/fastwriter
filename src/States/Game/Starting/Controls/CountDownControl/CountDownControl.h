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

#ifndef COUNTDOWNCONTROL_H
#define COUNTDOWNCONTROL_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico para la cuenta regresiva
///
////////////////////////////////////////////////////////////
class CountDownControl
{
public:
    using Ptr = std::unique_ptr<CountDownControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de cuenta regresiva
    /// \param start Duracion de la cuenta
    /// \param charSize Tamaño del texto grafico
    /// \param position Posicion del texto grafico
    /// \param font Fuente del texto grafico
    ///
    ////////////////////////////////////////////////////////////
    CountDownControl(const sf::Time& start,
                     unsigned charSize,
                     const sf::Vector2f& position,
                     const sf::Font& font);

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

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la representacion grafica
    /// \return Referencia hacia el texto grafico
    ///
    ////////////////////////////////////////////////////////////
    const sf::Text& getGraph() const;

private:
    sf::Time start;   ///< Duracion de la cuenta
    sf::Time elapsed; ///< Tiempo transcurrido
    sf::Text graph;   ///< Representacion grafica
};

#endif // COUNTDOWNCONTROL_H
