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

#include "MainMenu.h"

#include "StateManager.h"
#include "ResourceManager.h"

#include <SFML/Graphics/RenderWindow.hpp>

MainMenu::MainMenu(StateManager& stateManager)
    : State(stateManager)
{
    using Textures = ResourceManager::Textures;
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;

    background.setTexture(resMngr.getTexture(Textures::Background));
}

void MainMenu::handleInput(const sf::Event& event)
{
}

void MainMenu::update(const sf::Time& dt)
{
}

void MainMenu::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
}
