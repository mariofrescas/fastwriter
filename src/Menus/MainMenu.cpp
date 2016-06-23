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

// WARNING: Uncomment to disable assertions
// #define NDEBUG
#include <cassert>

#include "StateManager.h"
#include "ResourceManager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(StateManager& stateManager)
    : State(stateManager)
{
    using Textures = ResourceManager::Textures;
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;

    initMenuRects();
    initMenuSprites();
    initMenuPositions();

    background.setTexture(resMngr.getTexture(Textures::Background));
}

void MainMenu::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        handleMouseMoved(event.mouseMove.x, event.mouseMove.y);
    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        handleMousePressed(event.mouseButton.x, event.mouseButton.y);
    }
}

void MainMenu::update(const sf::Time&)
{
}

void MainMenu::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);

    for (const auto& opt : menuSprites)
    {
        window.draw(opt.second);
    }
}

void MainMenu::handleMouseMoved(int x, int y)
{
    bool found = false;
    for (const auto& opt : menuSprites)
    {
        if (opt.second.getGlobalBounds().contains(x, y))
        {
            setCurrentOption(opt.first);
            found = true;
            break;
        }
    }
    if (!found)
    {
        setCurrentOption(Options::None);
    }
}

void MainMenu::setCurrentOption(const Options& option)
{
    if (currentOption != option)
    {
        if (option == Options::None)
        {
            menuSprites[currentOption].setTextureRect(menuRects[currentOption].first);
        }
        else
        {
            if (currentOption != Options::None)
            {
                menuSprites[currentOption].setTextureRect(menuRects[currentOption].first);
            }

            menuSprites[option].setTextureRect(menuRects[option].second);
        }

        currentOption = option;
    }
}

void MainMenu::handleMousePressed(int x, int y)
{
    for (const auto& opt : menuSprites)
    {
        if (opt.second.getGlobalBounds().contains(x, y))
        {
            menuOptionPressed(opt.first);
            break;
        }
    }
}

void MainMenu::menuOptionPressed(const Options& option)
{
    switch (option)
    {
    case Options::NewGame:
        break;
    case Options::Scores:
        break;
    case Options::Help:
        break;
    case Options::About:
        break;
    case Options::Exit:
        getStateManager().getSharedContext().window.close();
        break;
    default:
        assert(false);
        break;
    }
}

void MainMenu::initMenuRects()
{
    menuRects[Options::NewGame] = std::make_pair(sf::IntRect(0, 0, 661, 146), sf::IntRect(662, 0, 661, 146));
    menuRects[Options::Scores] = std::make_pair(sf::IntRect(0, 147, 661, 146), sf::IntRect(662, 147, 661, 146));
    menuRects[Options::Help] = std::make_pair(sf::IntRect(0, 294, 661, 146), sf::IntRect(662, 294, 661, 146));
    menuRects[Options::About] = std::make_pair(sf::IntRect(0, 441, 661, 146), sf::IntRect(662, 441, 661, 146));
    menuRects[Options::Exit] = std::make_pair(sf::IntRect(0, 588, 661, 146), sf::IntRect(662, 588, 661, 146));
}

void MainMenu::initMenuSprites()
{
    using Textures = ResourceManager::Textures;
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;

    menuSprites[Options::NewGame] = sf::Sprite(resMngr.getTexture(Textures::MainMenu));
    menuSprites[Options::Scores] = sf::Sprite(resMngr.getTexture(Textures::MainMenu));
    menuSprites[Options::Help] = sf::Sprite(resMngr.getTexture(Textures::MainMenu));
    menuSprites[Options::About] = sf::Sprite(resMngr.getTexture(Textures::MainMenu));
    menuSprites[Options::Exit] = sf::Sprite(resMngr.getTexture(Textures::MainMenu));

    for (auto& opt : menuSprites)
    {
        opt.second.setTextureRect(menuRects[opt.first].first);
    }
}

void MainMenu::initMenuPositions()
{
    const int width = getStateManager().getSharedContext().window.getSize().x;

    menuSprites[Options::NewGame].setPosition((width / 2) - (menuSprites[Options::NewGame].getTextureRect().width / 2), 17);
    menuSprites[Options::Scores].setPosition((width / 2) - (menuSprites[Options::Scores].getTextureRect().width / 2), 164);
    menuSprites[Options::Help].setPosition((width / 2) - (menuSprites[Options::Help].getTextureRect().width / 2), 311);
    menuSprites[Options::About].setPosition((width / 2) - (menuSprites[Options::About].getTextureRect().width / 2), 458);
    menuSprites[Options::Exit].setPosition((width / 2) - (menuSprites[Options::Exit].getTextureRect().width / 2), 605);
}
