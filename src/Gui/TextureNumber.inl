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

#include "TextureNumber.h"

#include <SFML/Graphics/RenderTarget.hpp>

template<std::size_t Number>
TextureNumber<Number>::TextureNumber(const sf::Vector2f& position,
                                     const std::array<sf::IntRect, 10>& rects,
                                     const sf::Texture& texture)
{
    this->rects['0'] = rects[0];
    this->rects['1'] = rects[1];
    this->rects['2'] = rects[2];
    this->rects['3'] = rects[3];
    this->rects['4'] = rects[4];
    this->rects['5'] = rects[5];
    this->rects['6'] = rects[6];
    this->rects['7'] = rects[7];
    this->rects['8'] = rects[8];
    this->rects['9'] = rects[9];

    setPosition(position);

    for (std::size_t i = 0; i < Number; ++i)
    {
        sprites[i].setTexture(texture);
        sprites[i].setPosition(0 + rects[0].width * i, 0);
    }
}

template<std::size_t Number>
void TextureNumber<Number>::setNumber(const std::string& number)
{
    for (std::size_t i = 0; i < Number; ++i)
    {
        sprites[i].setTextureRect(rects[number.at(i)]);
    }
}

template<std::size_t Number>
void TextureNumber<Number>::draw(sf::RenderTarget& target,
                                 sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (std::size_t i = 0; i < Number; ++i)
    {
        target.draw(sprites[i], states);
    }
}
