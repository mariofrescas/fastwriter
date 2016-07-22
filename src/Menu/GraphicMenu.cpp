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

#include "GraphicMenu.h"

GraphicMenu::GraphicMenu(const std::list<MenuOptionData>& menusData,
                         const MenuContainerData& containerData,
                         const sf::Texture& texture)
{
    menu.container.graph.setTexture(texture);
    menu.container.graph.setTextureRect(containerData.rect);
    menu.container.graph.setPosition(containerData.pos);
    menu.container.data = containerData;

    for (auto& data : menusData)
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
