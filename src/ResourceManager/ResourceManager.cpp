#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    fontHolder.load(Fonts::Default, "fonts/Saxmono.ttf");

    textureHolder.load(Textures::Background, "textures/Background.png");
}

sf::Texture& ResourceManager::getTexture(const ResourceManager::Textures& textureId)
{
    return textureHolder.get(textureId);
}

sf::Font& ResourceManager::getFont(const ResourceManager::Fonts& fontId)
{
    return fontHolder.get(fontId);
}
