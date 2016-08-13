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

#ifndef SCORESFILE_H
#define SCORESFILE_H

#include <memory>

////////////////////////////////////////////////////////////
/// \brief Describe el manejo del archivo de puntuaciones
///
////////////////////////////////////////////////////////////
class ScoresFile
{
public:
    using Matrix = std::array<std::array<std::string, 10>, 6>; ///< Matriz de puntuaciones

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene la matriz de puntuaciones
    /// \param filename Ubicacion del archivo
    ///
    ////////////////////////////////////////////////////////////
    static Matrix loadFromFile(const std::string& filename);

    ////////////////////////////////////////////////////////////
    /// \brief Almacena una puntuacion en la matriz de puntuaciones
    /// \param filename Ubicacion del archivo
    /// \param pointsp Columna de puntos en la matriz
    /// \param score Puntuacion a agregar
    ///
    ////////////////////////////////////////////////////////////
    static void trySaveScore(const std::string& filename,
                             const std::size_t& pointsp,
                             const std::array<std::string, 6>& score);
};

#endif // SCORESFILE_H
