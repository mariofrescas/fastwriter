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
