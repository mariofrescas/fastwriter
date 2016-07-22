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

#ifndef CLEANERSCONTROL_H
#define CLEANERSCONTROL_H

#include <list>
#include <memory>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de limpiadores
///
////////////////////////////////////////////////////////////
class CleanersControl
{
public:
    using Ptr = std::unique_ptr<CleanersControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de limpiadores
    /// \param defaultCleaners Numero por defecto de limpiadores
    /// \param maxCleaners Numero maximo de limpiadores
    /// \param addInterval Tiemponecesario para agregar un limpiador
    /// \param position Posicion del primer limpiador
    /// \param gameTexture Textura donde se encuentra la rep. grafica
    /// \param location Rectangulo donde se encuentra la rep. grafica
    ///
    ////////////////////////////////////////////////////////////
    CleanersControl(int defaultCleaners,
                    int maxCleaners,
                    const sf::Time& addInterval,
                    const sf::Vector2f& position,
                    const sf::Texture& gameTexture,
                    const sf::IntRect& location);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la representacion grafica
    /// \return Referencia hacia la lista de limpiadores
    ///
    ////////////////////////////////////////////////////////////
    const std::list<sf::Sprite>& getGraph() const;


    ////////////////////////////////////////////////////////////
    /// \brief Acumula el tiempo para agregar el limpiador
    /// \param dt Cantidad de tiempo
    ///
    ////////////////////////////////////////////////////////////
    void addTime(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief Ejecuta el limpiador
    ///
    ////////////////////////////////////////////////////////////
    void clean();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la representacion grafica
    /// \return True = Es posible activar un limpiador
    ///
    ////////////////////////////////////////////////////////////
    bool canClean() const;

private:
    int                defaultCleaners; ///< Numero por defecto de limpiadores
    int                maxCleaners;     ///< Numero maximo de limpiadores
    int                cleaners;        ///< Numero actual de limpiadores
    sf::Time           elapsed;         ///< Tiempo acumulado
    sf::Time           addInterval;     ///< Tiempo necesario
    sf::Vector2f       position;        ///< Posicion de la rep. grafica
    const sf::Texture& texture;         ///< Textura donde esta la rep. grafica
    sf::IntRect        location;        ///< Localizacion en la textura de la rep. grafica
    std::list<sf::Sprite> graph;        ///< Representacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Crea las rep. graficas por defecto de los limpiadores
    ///
    ////////////////////////////////////////////////////////////
    void addDefaultCleaners();
};

#endif // CLEANERSCONTROL_H
