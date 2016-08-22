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

#ifndef RESULTSCONTROL_H
#define RESULTSCONTROL_H

#include <array>
#include <string>
#include "GameConfManager.h"
#include <SFML/System/Time.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico de calculo de resultados
///
////////////////////////////////////////////////////////////
class ResultsControl
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de calculo de resultados
    ///
    ////////////////////////////////////////////////////////////
    ResultsControl();

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief Cambia la dificultad de los resultados
    /// \param diffty Nueva dificultad
    ///
    ////////////////////////////////////////////////////////////
    void setDiffty(const Configs::ID& diffty);

    ////////////////////////////////////////////////////////////
    /// \brief Aumenta el tiempo transcurrido
    /// \param dt Intervalo de tiempo
    ///
    ////////////////////////////////////////////////////////////
    void addElapsed(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa los puntos almacenados
    /// \param increment Incremento en los puntos
    ///
    ////////////////////////////////////////////////////////////
    void incPoints(int increment);

    ////////////////////////////////////////////////////////////
    /// \brief Decrementa los puntos almacenados
    /// \param decrement Decremento en los puntos
    ///
    ////////////////////////////////////////////////////////////
    void decPoints(int decrement);

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa el numero de fallas al teclear mal
    ///
    ////////////////////////////////////////////////////////////
    void incFails();

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa el numero de vidas ganadas
    /// \param increment Incremento en las vidas ganadas
    ///
    ////////////////////////////////////////////////////////////
    void incLifes(int increment);

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa el numero de limpiadores activados
    ///
    ////////////////////////////////////////////////////////////
    void incCleaners();

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa el numero de modos Shift activados
    ///
    ////////////////////////////////////////////////////////////
    void incShifts();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene los resultados
    /// \return Resultados
    ///
    ////////////////////////////////////////////////////////////
    const std::array<std::string, 8>& get() const;

private:
    sf::Time elapsed;  ///< Tiempo transcurrido
    int      points;   ///< Numero de puntos
    int      fails;    ///< Numero de fallas al teclear mal
    int      fpoints;  ///< Numero de puntos perdidos por fallas
    int      lifes;    ///< Numero de vidas ganadas
    int      cleaners; ///< Numero de activaciones de limpiadores
    int      shifts;   ///< Numero de activaciones del modo Shift
    std::array<std::string, 8> results; ///< Almacen de resultados
};

#endif // RESULTSCONTROL_H
