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
    /// \param color Color del texto
    /// \param charSize Tamaño del texto grafico
    /// \param position Posicion del texto grafico
    /// \param font Fuente del texto grafico
    ///
    ////////////////////////////////////////////////////////////
    CountDownControl(const sf::Time& start,
                     const sf::Color& color,
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
