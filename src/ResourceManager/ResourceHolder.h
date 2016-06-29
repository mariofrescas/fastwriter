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

#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

////////////////////////////////////////////////////////////
// Cabeceras
//
////////////////////////////////////////////////////////////
#include <map>
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
