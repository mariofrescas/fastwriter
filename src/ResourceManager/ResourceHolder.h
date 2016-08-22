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

#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <map>
#include <string>
#include <memory>

////////////////////////////////////////////////////////////
/// \brief Mapa abstracto para recursos
/// \param Identifier Tipo de identificador para el recurso (Ej: enum)
/// \param Resource Tipo de recurso (Ej: sf::Texture)
///
////////////////////////////////////////////////////////////
template<typename Identifier, typename Resource>
class ResourceHolder
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Carga un recurso del disco y lo relaciona con un id
    /// \param id Identificador del recurso
    /// \param filename Ruta del recurso
    ///
    ////////////////////////////////////////////////////////////
    void load(Identifier id, const std::string& filename);

    ////////////////////////////////////////////////////////////
    /// \brief Carga un recurso del disco y lo relaciona con un id
    /// \param id Identificador del recurso
    /// \param filename Ruta del recurso
    /// \param exparam Parametros extra (Ej: Dimensiones de la textura)
    ///
    ////////////////////////////////////////////////////////////
    template<typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& exparam);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia al recurso que concuerde con el id
    /// \param id Identificador del recurso
    /// \return Referencia hacia el recurso
    ///
    ////////////////////////////////////////////////////////////
    Resource& get(Identifier id) const;

private:
    std::map<Identifier, std::unique_ptr<Resource>> resources; ///< Contenedor de recursos
};

#include "ResourceHolder.inl"

#endif // RESOURCEHOLDER_H
