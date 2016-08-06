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

#include "TextureBar.h"

TextureBar::Graph::Graph(const sf::RectangleShape& start,
                         const sf::RectangleShape& middle,
                         const sf::RectangleShape& end)
    :
      start(start),
      middle(middle),
      end(end)
{
}

TextureBar::TextureBar(const sf::Vector2f& position,
                       const sf::IntRect& start,
                       const sf::IntRect& middle,
                       const sf::IntRect& end,
                       const sf::IntRect& total,
                       const sf::Texture& texture)
    :
      middle(sf::Vector2f(middle.width, middle.height)),
      defX(position.x + start.width),
      total(total),
      start(sf::Vector2f(start.width, start.height)),
      end(sf::Vector2f(end.width, end.height))
{
    this->start.setTexture(&texture);
    this->start.setTextureRect(start);
    this->start.setPosition(position);

    this->middle.setTexture(&texture);
    this->middle.setTextureRect(middle);
    this->middle.setPosition(position.x + this->start.getSize().x, position.y);

    this->end.setTexture(&texture);
    this->end.setTextureRect(end);
    this->end.setPosition
    (
        this->middle.getPosition().x + this->middle.getSize().x,
        position.y
    );
}

const TextureBar::Graph& TextureBar::getGraph() const
{
    return graph;
}

void TextureBar::fillFull()
{
    middle.setPosition(defX, middle.getPosition().y);
    middle.setSize
    (
        sf::Vector2f
        (
            total.width - (start.getSize().x + end.getSize().x),
            total.height
        )
    );
    middle.setTextureRect
    (
        sf::IntRect
        (
            start.getTextureRect().left + start.getTextureRect().width,
            middle.getTextureRect().top,
            middle.getSize().x - (start.getSize().x + end.getSize().x),
            middle.getTextureRect().height
        )
    );

    updateEdges();
}

void TextureBar::empty()
{
    middle.setSize
    (
        sf::Vector2f
        (
            1,
            total.height
        )
    );
    middle.setTextureRect
    (
        sf::IntRect
        (
            start.getTextureRect().left + start.getTextureRect().width,
            middle.getTextureRect().top,
            middle.getTextureRect().left + 1,
            middle.getTextureRect().height
        )
    );

    updateEdges();
}

void TextureBar::adjustMiddle(float size)
{
    updateMiddle(size);
    updateEdges();
    if (checkIsFullGrown())
    {
        fillFull();
    }
    else if (checkIsFullShrank())
    {
        empty();
    }
}

TextureBar::~TextureBar()
{
}

void TextureBar::updateEdges()
{
    start.setPosition
    (
        middle.getPosition().x - start.getSize().x,
        start.getPosition().y
    );
    end.setPosition
    (
        middle.getPosition().x + middle.getSize().x,
        end.getPosition().y
    );
}

bool TextureBar::checkIsFullGrown()
{
    return (start.getSize().x + middle.getSize().x + end.getSize().x) >= total.width;
}

bool TextureBar::checkIsFullShrank()
{
    return (start.getPosition().x + start.getSize().x) >= end.getPosition().x;
}
