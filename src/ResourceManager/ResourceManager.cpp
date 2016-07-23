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

#include "ResourceManager.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Texture.hpp>

ResourceManager::ResourceManager()
{
    fontHolder.load(Fonts::ID::Default, "res/fonts/saxmono.ttf");
    shaderHolder.load(Shaders::ID::Fade, "res/shaders/fade.frag", sf::Shader::Fragment);
    shaderHolder.load(Shaders::ID::Circle, "res/shaders/circle.frag", sf::Shader::Fragment);

    textureHolder.load(Textures::ID::Background, "res/textures/background.png");
    textureHolder.load(Textures::ID::MainMenu, "res/textures/main-menu.png");
    textureHolder.load(Textures::ID::About, "res/textures/about.png");
    textureHolder.load(Textures::ID::DifftyMenu, "res/textures/difficulty-menu.png");
    textureHolder.load(Textures::ID::Starting, "res/textures/starting.png");
    textureHolder.load(Textures::ID::Paused, "res/textures/paused-menu.png");
    textureHolder.load(Textures::ID::QuitConfirm, "res/textures/quit-confirm-menu.png");
    textureHolder.load(Textures::ID::Wellcome, "res/textures/wellcome.png");
    textureHolder.load(Textures::ID::Game, "res/textures/game.png");
    textureHolder.load(Textures::ID::Letters, "res/textures/letters.png");
}

sf::Texture& ResourceManager::getTexture(const Textures::ID& textureId) const
{
    return textureHolder.get(textureId);
}

sf::Font& ResourceManager::getFont(const Fonts::ID& fontId) const
{
    return fontHolder.get(fontId);
}

sf::Shader& ResourceManager::getShader(const Shaders::ID shaderId) const
{
    return shaderHolder.get(shaderId);
}
