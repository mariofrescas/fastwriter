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

#include <SFML/Graphics/Text.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de vidas
///
////////////////////////////////////////////////////////////
class LifesControl
{
public:
    typedef std::unique_ptr<LifesControl> Ptr; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de vidas
    /// \param defaultLifes Vidas por defecto
    /// \param charSize Tamaño del texto grafico
    /// \param position Posicion del texto grafico
    /// \param font Fuente del texto grafico
    ///
    ////////////////////////////////////////////////////////////
    LifesControl(int defaultLifes,
                 unsigned charSize,
                 const sf::Vector2f& position,
                 const sf::Font& font);

    ////////////////////////////////////////////////////////////
    /// \brief Reconfigura las propiedades del control de vidas
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
    /// \brief Obtiene la representacion grafica
    /// \return Referencia hacia el texto grafico
    ///
    ////////////////////////////////////////////////////////////
    const sf::Text& getGraph() const;

    ////////////////////////////////////////////////////////////
    /// \brief Incrementa los puntos de vida en el control
    /// \param increment Incremento en la vida
    ///
    ////////////////////////////////////////////////////////////
    void increment(int increment);

    ////////////////////////////////////////////////////////////
    /// \brief Decrementa los puntos de vida el control
    /// \param decrement Decremento en la vida
    ///
    ////////////////////////////////////////////////////////////
    void decrement(int decrement);

    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si aun quedan vidas en el control
    /// \return True = Aun quedan vidas
    ///
    ////////////////////////////////////////////////////////////
    bool remain() const;

private:
    int      lifes;        ///< Numero de vidas
    int      defaultLifes; ///< Vidas por defecto
    bool     remainLifes;  ///< Aun quedan vidas
    sf::Text graph;        ///< Representacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la representacion grafica
    ///
    ////////////////////////////////////////////////////////////
    void updateGraph();
};

#endif // LIFESCONTROL_H
