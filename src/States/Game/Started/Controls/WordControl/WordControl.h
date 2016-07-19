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

#ifndef WORDCONTROL_H
#define WORDCONTROL_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "WordMap.h"
#include "Dictionary.h"
#include <list>
#include <tuple>
#include <string>
#include <memory>

////////////////////////////////////////////////////////////
/// \brief Describe el control logico-grafico de las palabras
///
////////////////////////////////////////////////////////////
class WordControl
{
public:
    using Ptr = std::unique_ptr<WordControl>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Datos de cada letra
    ///
    ////////////////////////////////////////////////////////////
    struct Letter
    {
        char  character;  ///< Character de la letra
        float velocity;   ///< Velocidad de "caida"
        sf::Sprite graph; ///< Representacion grafica
    };

    ////////////////////////////////////////////////////////////
    /// \brief Configuracion para cada palabra
    ///
    ////////////////////////////////////////////////////////////
    struct WordConfig
    {
        float    velocity;     ///< Velocidad de "caida"
        int      length;       ///< Longitud de la palabra
        sf::Time dropInterval; ///< Intervalo de "caida"
    };

    ////////////////////////////////////////////////////////////
    /// \brief Crea un control de letras
    /// \param dictionaryPath Ubicacion del archivo de palabras
    /// \param dropArea Area de dropeo del control
    /// \param lettersTextura Textura para las letras
    ///
    ////////////////////////////////////////////////////////////
    WordControl(const std::string& dictionaryPath,
                const sf::FloatRect& dropArea,
                const sf::Texture& lettersTexture);

    ////////////////////////////////////////////////////////////
    /// \brief Reinicia el control a los valores por defecto
    ///
    ////////////////////////////////////////////////////////////
    void reset();

    ////////////////////////////////////////////////////////////
    /// \brief "Toma"/Elimina todas las letras del control
    /// \return Numero de letras "tomadas"/eliminadas
    ///
    ////////////////////////////////////////////////////////////
    int takeAll();

    ////////////////////////////////////////////////////////////
    /// \brief "Toma"/Elimina la ultima letra relacionada con
    ///        el caracter especificado
    /// \param letter Character que identifica la letra
    /// \return True = Existe una letra con el character especificado
    ///
    ////////////////////////////////////////////////////////////
    bool take(char letter);

    ////////////////////////////////////////////////////////////
    /// \brief "Suelta"/Agrega una letra al control
    /// \param elapsed Intervalo de tiempo
    /// \param config Configuracion unica para cada palabra
    ///
    ////////////////////////////////////////////////////////////
    void drop(const sf::Time& elapsed, const WordConfig& config);

    ////////////////////////////////////////////////////////////
    /// \brief Desplaza las letras hacia abajo
    /// \param dt Intervalo de tiempo
    ///
    ////////////////////////////////////////////////////////////
    void moveDown(const sf::Time& dt);

    ////////////////////////////////////////////////////////////
    /// \brief "Atrapa"/Elimina las letras que entran en contacto
    ///        con el fondo del area de dropeo
    /// \return Numero de letras "atrapadas"
    ///
    ////////////////////////////////////////////////////////////
    int trap();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la representacion grafica
    /// \return Referencia hacia la rep. grafica
    ///
    ////////////////////////////////////////////////////////////
    const std::list<Letter>& getGraph() const;

private:
    sf::Time           elapsedTime; ///< Tiempo transcurrido
    std::list<Letter>  letters;     ///< Lista de letras
    sf::FloatRect      dropArea;    ///< Area de trabajo
    const sf::Texture& lettTexture; ///< Textura para las letras
    Dictionary::Ptr    dictionary;  ///< Lista de palabras (characteres)
    WordMap::Ptr       wordMap;     ///< Mapa de palabras (longitud=>palabra)

    ////////////////////////////////////////////////////////////
    /// \brief Transforma un caracter a un valor numerico especifico
    /// \param letter Caracter a transformar
    /// \return Valor numerico
    ///
    ////////////////////////////////////////////////////////////
    int decodeLettChar(char letter) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una palabra aleatoria del mapa de palabras
    /// \param length Longuitud de las palabras posibles por obtener
    /// \return Referencia hacia la palabra
    ///
    ////////////////////////////////////////////////////////////
    const std::string& getRandWord(int length) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene un numero entero aleatorio
    /// \param min Valor minimo posible
    /// \param max Valor maximo posible
    /// \return Numero aleatorio
    ///
    ////////////////////////////////////////////////////////////
    int rand(int min, int max) const;
};

#endif // WORDCONTROL_H
