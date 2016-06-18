#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

////////////////////////////////////////////////////////////
/// \brief Inclusiones internas
///
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
