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

#include "GraphicMenu.h"

GraphicMenu::GraphicMenu(const std::list<MenuOptionData>& menuData,
                         const MenuContainerData& containerData,
                         const sf::Texture& texture)
{
    menu.container.graph.setTexture(texture);
    menu.container.graph.setTextureRect(containerData.rect);
    menu.container.graph.setPosition(containerData.pos);
    menu.container.data = containerData;

    for (auto& data : menuData)
    {
        sf::Sprite s(texture, data.normal);
        s.setPosition(data.pos);
        menu.options.push_back(MenuOption{data, s});
    }
}

void GraphicMenu::setCurrentOption(const sf::Vector2f& point)
{
    sf::FloatRect rect(point.x, point.y, 1, 1);

    for (auto& option : menu.options)
    {
        if (option.graph.getGlobalBounds().intersects(rect))
        {
            option.graph.setTextureRect(option.data.hover);
        }
        else
        {
            option.graph.setTextureRect(option.data.normal);
        }
    }
}

void GraphicMenu::execCurrentOption(const sf::Vector2f& point)
{
    sf::FloatRect rect(point.x, point.y, 1, 1);

    for (auto& option : menu.options)
    {
        if (option.graph.getGlobalBounds().intersects(rect))
        {
            option.data.action();
            break;
        }
    }
}

const GraphicMenu::Menu& GraphicMenu::getGraphicMenu() const
{
    return menu;
}
