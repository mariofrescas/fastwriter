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
