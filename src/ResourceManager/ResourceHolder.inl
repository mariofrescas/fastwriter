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
