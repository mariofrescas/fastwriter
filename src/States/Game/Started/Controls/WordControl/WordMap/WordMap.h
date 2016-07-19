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

#ifndef WORDMAP_H
#define WORDMAP_H

#include <map>
#include <list>
#include <vector>
#include <string>
#include <memory>

////////////////////////////////////////////////////////////
/// \brief Describe un mapa de palabras (longitud => palabra)
///
////////////////////////////////////////////////////////////
class WordMap
{
public:
    using Ptr = std::unique_ptr<WordMap>;        ///< Puntero unico
    using WordVector = std::vector<std::string>; ///< Vector de palabras

    ////////////////////////////////////////////////////////////
    /// \brief Crea un mapa de palabras relacionadas con su longitud
    /// \param wordList Lista de palabras a relacionar
    ///
    ////////////////////////////////////////////////////////////
    WordMap(const std::list<std::string>& wordList);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene el mapa de palabras
    /// \return Referencia hacia el mapa de palabras
    ///
    ////////////////////////////////////////////////////////////
    const WordVector& getWords(int wordLength);

private:
    std::map<int, WordVector> words; ///< Mapa de palabras
};

#endif // WORDMAP_H
