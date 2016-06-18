#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
    textureHolder.load(TextureId::ConcreteTexture1, "bg1.jpg");
    textureHolder.load(TextureId::ConcreteTexture2, "bg2.jpg");
}

sf::Texture& ResourceManager::getTexture(const ResourceManager::TextureId& textureId)
{
    return textureHolder.get(textureId);
}
