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

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceHolder.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace sf
{
    class Font;
    class Shader;
    class Texture;
}

namespace Dictionaries
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de diccionarios
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        EN_DIC ///< Diccionario en ingles
    };
}

namespace Textures
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de texturas
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Wellcome,       ///< Textura para la escena de bienvenida
        MainMenu,       ///< Textura para la escena del menu principal
        Scores,         ///< Textura para la escena de puntuaciones
        About,          ///< Texutra para la escena de informacion "acerca de..."
        DifftyMenu,     ///< Textura para la escena del menu de dificultad
        Starting,       ///< Textura para la escena de "iniciando"
        Paused,         ///< Textura para la escena de juego pausado
        QuitConfirm,    ///< Textura para la escena de confirmar quitar el juego
        RestartConfirm, ///< Textura para la escena de confirmar reiniciar el juego
        Help,           ///< Textura para la escena de ayuda
        Results,        ///< Textura para la escena de resultados de juego
        Game,           ///< Textura para la escena del juego
        Letters,        ///< Texutra para todas las letras del juego
        Numbers         ///< Textura para contadores, temporizadores y relojes
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

namespace Sounds
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de efectos de sonido
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        MenuOpen,        ///< Id de efecto de sonido para abrir menus
        MenuClose,       ///< Id de efecto de sonido para cerrar menus
        TabChange,       ///< Id de efecto de sonido para cambiar de pestañas
        LifesIncrement,  ///< Id de efecto de sonido para cuando incrementan las vidas
        GameEnd,         ///< Id de efecto de sonido para cuando el juego ha terminado
        CountDown,       ///< Id de efecto de sonido para cuando esta corriendo la la cuenta de inicio de juego
        CountDownFinish, ///< Id de efecto de sonido para cuando termina la cuenta de inicio de juego
        ShiftModeStart,  ///< Id de efecto de sonido para cuando inicia el modo Shift
        ShiftModeFinish, ///< Id de efecto de sonido para cuando termina el modo Shift
        ShiftModeReady,  ///< Id de efecto de sonido para cuando esta listo el modo Shift
        CleanerActive,   ///< Id de efecto de sonido para activar un lipiador
        LetterTake,      ///< Id de efecto de sonido para tomar letras
        LetterTrap,      ///< Id de efecto de sonido para atrapar letras
        LetterTakeFail   ///< Id de efecto de sonido para cuando falla el tomar letras
    };
}

namespace Music
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de temas musicales
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Started ///< Tema musical para la escena Started
    };
}

namespace Other
{
    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de archivos generales
    ///
    ////////////////////////////////////////////////////////////
    enum class ID
    {
        Scores ///< Archivo de puntuaciones
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
    /// \param path Ruta donde se encuentran los recursos
    ///
    ////////////////////////////////////////////////////////////
    explicit ResourceManager(const std::string& path);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia a la textura que concuerde con el id
    /// \param textureId Identificador de la textura
    /// \return Referencia a la textura
    ///
    ////////////////////////////////////////////////////////////
    const sf::Texture& getTexture(const Textures::ID& textureId) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia a la fuente que concuerde con el id
    /// \param textureId Identificador de la fuente
    /// \return Referencia a la fuente
    ///
    ////////////////////////////////////////////////////////////
    const sf::Font& getFont(const Fonts::ID& fontId) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia al shader que concuerde con el id
    /// \param shaderId Identificador del shader
    /// \return Referencia al shader
    ///
    ////////////////////////////////////////////////////////////
    sf::Shader& getShader(const Shaders::ID& shaderId);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia al sonido que concuerde con el id
    /// \param soundId Identificador del sonido
    /// \return Referencia hacia el sonido
    ///
    ////////////////////////////////////////////////////////////
    const sf::SoundBuffer& getSound(const Sounds::ID& soundId) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia al diccionario que concuerde con el id
    /// \param soundId Identificador del diccionario
    /// \return Referencia hacia el diccionario
    ///
    ////////////////////////////////////////////////////////////
    const std::string& getDictionary(const Dictionaries::ID& dicId) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia al tema musical que concuerde con el id
    /// \param soundId Identificador del tema musical
    /// \return Referencia hacia el tema musical
    ///
    ////////////////////////////////////////////////////////////
    const std::string& getMusic(const Music::ID& musicId) const;

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia al archivo que concuerde con el id
    /// \param otherId Identificador del archivo
    /// \return Referencia hacia el archivo
    ///
    ////////////////////////////////////////////////////////////
    const std::string& getOther(const Other::ID& otherId) const;

private:
    ResourceHolder<Textures::ID, sf::Texture>   textureHolder; ///< Contenedor de texturas
    ResourceHolder<Fonts::ID, sf::Font>         fontHolder;    ///< Contenedor de fuentes
    ResourceHolder<Shaders::ID, sf::Shader>     shaderHolder;  ///< Contenedor de shaders
    ResourceHolder<Sounds::ID, sf::SoundBuffer> soundHolder;   ///< Contenedor de efectos de sonido
    std::map<Music::ID, std::string>            musicHolder;   ///< Contenedor de temas musicales
    std::map<Dictionaries::ID, std::string>     dicHolder;     ///< Contenedor de diccionarios
    std::map<Other::ID, std::string>            otherHolder;   ///< Contenedor de archivos generales
};

#endif // RESOURCEMANAGER_H
