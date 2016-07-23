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

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceHolder.h"

namespace sf
{
    class Font;
    class Shader;
    class Texture;
}

namespace Textures
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de texturas
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Background,     ///< Textura de fondo general para el juego
        Wellcome,       ///< Textura para la escena de bienvenida
        MainMenu,       ///< Textura para la escena del menu principal
        About,          ///< Texutra para la escena de informacion "acerca de..."
        DifftyMenu,     ///< Textura para la escena del menu de dificultad
        Starting,       ///< Textura para la escena de "iniciando"
        Paused,         ///< Textura para la escena de juego pausado
        QuitConfirm,    ///< Textura para la escena de confirmar quitar el juego
        RestartConfirm, ///< Textura para la escena de confirmar reiniciar el juego
        Game,           ///< Textura para la escena del juego
        Letters         ///< Texutra para todas las letras del juego
    };
}

namespace Fonts
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de fuentes
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Default ///< Id de la fuente por defecto
    };
}

namespace Shaders
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de shaders
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Fade,  ///< Id del shader para transiciones Fade
        Circle ///< Id del shader para transiciones Circle
    };
}

////////////////////////////////////////////////////////////
/// \brief Contenedor de los recursos necesarios por la aplicacion
///
////////////////////////////////////////////////////////////
class ResourceManager
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Carga e inicializa los recursos y los relaciona con un id
    ///
    ////////////////////////////////////////////////////////////
    ResourceManager();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia a la textura que concuerde con el id
    /// \param textureId Identificador de la textura
    /// \return Referencia a la textura
    ///
    ////////////////////////////////////////////////////////////
    sf::Texture& getTexture(const Textures::ID& textureId) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia a la fuente que concuerde con el id
    /// \param textureId Identificador de la fuente
    /// \return Referencia a la fuente
    ///
    ////////////////////////////////////////////////////////////
    sf::Font& getFont(const Fonts::ID& fontId) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia al shader que concuerde con el id
    /// \param shaderId Identificador del shader
    /// \return Referencia al shader
    ///
    ////////////////////////////////////////////////////////////
    sf::Shader& getShader(const Shaders::ID shaderId) const;

private:
    ResourceHolder<Textures::ID, sf::Texture> textureHolder; ///< Contenedor de texturas
    ResourceHolder<Fonts::ID, sf::Font>       fontHolder;    ///< Contenedor de fuentes
    ResourceHolder<Shaders::ID, sf::Shader>   shaderHolder;  ///< Contenedor de shaders
};

#endif // RESOURCEMANAGER_H
