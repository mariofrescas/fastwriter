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

#include "BidirectionalBar.h"

BidirectionalBar::BidirectionalBar(const sf::Vector2f& position,
                                   const sf::IntRect& start,
                                   const sf::IntRect& middle,
                                   const sf::IntRect& end,
                                   const sf::IntRect& total,
                                   const sf::Texture& texture)
    : TextureBar(position, start, middle, end, total, texture)
{
}

void BidirectionalBar::updateMiddle(float size)
{
    middle.setPosition
    (
        middle.getPosition().x - ((size - middle.getSize().x) / 2.f),
        middle.getPosition().y
    );
    middle.setSize
    (
        sf::Vector2f(size, middle.getSize().y)
    );
    middle.setTextureRect
    (
        sf::IntRect
        (
            middle.getTextureRect().left,
            middle.getTextureRect().top,
            middle.getSize().x,
            middle.getSize().y
        )
    );
}
