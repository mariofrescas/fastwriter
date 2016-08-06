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

#ifndef TEXTUREBAR_H
#define TEXTUREBAR_H

#include <SFML/Graphics/RectangleShape.hpp>

namespace sf
{
    class Time;
}

////////////////////////////////////////////////////////////
/// \brief Describe una barra redimensionable de una textura
///
////////////////////////////////////////////////////////////
class TextureBar
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Encapsula la representacion grafica
    ///
    ////////////////////////////////////////////////////////////
    struct Graph
    {
        ////////////////////////////////////////////////////////////
        /// \brief Crea un objeto contenedor de la rep. grafica
        /// \param start Referencia hacia la rep. grafica de inicio
        /// \param middle Referencia hacia la rep. grafica de en medio
        /// \param end Referencia hacia la rep. grafica final
        ///
        ////////////////////////////////////////////////////////////
        Graph(const sf::RectangleShape& start,
              const sf::RectangleShape& middle,
              const sf::RectangleShape& end);

        const sf::RectangleShape& start;  ///< Rep. grafica inicial
        const sf::RectangleShape& middle; ///< Rep. grafica de en medio
        const sf::RectangleShape& end;    ///< Rep. grafica final
    };

    ////////////////////////////////////////////////////////////
    /// \brief Crea una barra en base a una textura
    /// \param position Posicion de la barra en la escena
    /// \param start Rect en textura de la rep. grafica inicial
    /// \param middle Rect en textura de la rep. grafica de en medio
    /// \param end Rect en textura de la rep. grafica final
    /// \param total Rect de la rep. grafica total: start + middle + end
    /// \param texture Textura de donde se obtienen los graficos
    ///
    ////////////////////////////////////////////////////////////
    TextureBar(const sf::Vector2f& position,
               const sf::IntRect& start,
               const sf::IntRect& middle,
               const sf::IntRect& end,
               const sf::IntRect& total,
               const sf::Texture& texture);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la rep. grafica
    /// \return Referencia al objeto encapsulador de la rep. grafica
    ///
    ////////////////////////////////////////////////////////////
    const Graph& getGraph() const;

    ////////////////////////////////////////////////////////////
    /// \brief Llena la barra completamente
    ///
    ////////////////////////////////////////////////////////////
    void fillFull();

    ////////////////////////////////////////////////////////////
    /// \brief Vacia la barra a un minimo aceptable start.w + 1 + end.w
    ///
    ////////////////////////////////////////////////////////////
    void empty();

    ////////////////////////////////////////////////////////////
    /// \brief Ajusta el tamaño de la barra
    /// \param size Nuevo tamaño de la barra
    ///
    ////////////////////////////////////////////////////////////
    void adjustMiddle(float size);

    ////////////////////////////////////////////////////////////
    /// \brief Destructor virtual!
    ///
    ////////////////////////////////////////////////////////////
    virtual ~TextureBar();

protected:
    sf::RectangleShape middle; ///< Rep. de en medio

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza las propiedades de la rep. de en medio
    /// \param size Nuevo tamaño de la barra
    ///
    ////////////////////////////////////////////////////////////
    virtual void updateMiddle(float size) = 0;

private:
    float              defX;  ///< Posicion inicial de la rep. mediana
    sf::IntRect        total; ///< Rect de la rep. total
    sf::RectangleShape start; ///< Rep. grafica de inicio
    sf::RectangleShape end;   ///< Rep. grafica final
    Graph graph = {start, middle, end}; ///< Encapsulacion grafica

    ////////////////////////////////////////////////////////////
    /// \brief Ajusta las posiciones de las rep. de inicio y final
    ///        con respecto a la rep. grafica de en medio
    ///
    ////////////////////////////////////////////////////////////
    void updateEdges();


    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si la barra esta llena
    /// \return True = Completamente llena
    ///
    ////////////////////////////////////////////////////////////
    bool checkIsFullGrown();

    ////////////////////////////////////////////////////////////
    /// \brief Comprueba si la barra esta vacia con minimo aceptable
    /// \return True = Completamente vacia
    ///
    ////////////////////////////////////////////////////////////
    bool checkIsFullShrank();
};

#endif // TEXTUREBAR_H
