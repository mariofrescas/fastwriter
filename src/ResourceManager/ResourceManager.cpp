#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    textureHolder.load(TextureId::ConcreteTexture1, "bg1.jpg");
    textureHolder.load(TextureId::ConcreteTexture2, "bg2.jpg");

    fontHolder.load(Fonts::Default, "saxmono.ttf");
}

sf::Texture& ResourceManager::getTexture(const ResourceManager::TextureId& textureId)
{
    return textureHolder.get(textureId);
}

sf::Font& ResourceManager::getFont(const ResourceManager::Fonts& fontId)
{
    return fontHolder.get(fontId);
}
