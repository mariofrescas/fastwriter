#include "ResourceHolder.h"

// WARNING: Uncomment to disable assertions
// #define NDEBUG
#include <cassert>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

template<typename Identifier, typename Resource>
void ResourceHolder<Identifier, Resource>::load(Identifier id, const std::string& filename)
{
    auto res = std::make_unique<Resource>();

    if (!res->loadFromFile(filename))
    {
        throw std::runtime_error("Failed to load: " + filename);
    }

    resources[id] = std::move(res);
}

template<typename Identifier, typename Resource>
template<typename Parameter>
void ResourceHolder<Identifier, Resource>::load(Identifier id, const std::string& filename, const Parameter& exparam)
{
    auto res = std::make_unique<Resource>();

    if (!res->loadFromFile(filename, exparam))
    {
        throw std::runtime_error("Failed to load: " + filename);
    }

    resources[id] = std::move(res);
}

template<typename Identifier, typename Resource>
Resource& ResourceHolder<Identifier, Resource>::get(Identifier id) const
{
    assert(!(resources.find(id) == resources.end()));

    return *resources.find(id)->second;
}
