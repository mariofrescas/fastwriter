#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    textureHolder.load(Textures::ConcreteTexture1, "bg1.jpg");
    textureHolder.load(Textures::ConcreteTexture2, "bg2.jpg");

    fontHolder.load(Fonts::Default, "fonts/saxmono.ttf");
}

sf::Texture& ResourceManager::getTexture(const ResourceManager::Textures& textureId)
{
    return textureHolder.get(textureId);
}

sf::Font& ResourceManager::getFont(const ResourceManager::Fonts& fontId)
{
    return fontHolder.get(fontId);
}
