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

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <list>
#include <memory>
#include <string>

////////////////////////////////////////////////////////////
/// \brief Describe una lista de palabras
///
////////////////////////////////////////////////////////////
class Dictionary
{
public:
    using Ptr = std::unique_ptr<Dictionary>; ///< Puntero unico

    ////////////////////////////////////////////////////////////
    /// \brief Crea una lista de palabras en base a un archivo
    /// \param filename Ubicacion del archivo
    ///
    ////////////////////////////////////////////////////////////
    Dictionary(const std::string& filename);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la lista de palabras
    /// \return Referencia hacia la lista de palabras
    ///
    ////////////////////////////////////////////////////////////
    const std::list<std::string>& getWords() const;

private:
    std::list<std::string> words; ///< Lista de palabras
};

#endif // DICTIONARY_H
