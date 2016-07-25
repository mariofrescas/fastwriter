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
    /// \brief Reconfigura las propiedades del control de limpiadores
    /// \param defaultCleaners Numero por defecto de limpiadores
    /// \param maxCleaners Numero maximo de limpiadores
    /// \param addInterval Tiemponecesario para agregar un limpiador
    ///
    ////////////////////////////////////////////////////////////
    void reconfigure(int defaultCleaners,
                     int maxCleaners,
                     const sf::Time& addInterval);

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
    /// \brief Comprueba si el control puede activar un limpiador
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
