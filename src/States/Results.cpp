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

#include "Results.h"

#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Results::Results(StateManager& stateManager, State* parent)
    : State(stateManager, parent)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Results));
    background.setTextureRect(sf::IntRect(2, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr int acw = 599;
    constexpr int ach = 648;
    int acx = (windowSize.x / 2) - (acw / 2);
    int acy = (windowSize.y / 2) - (ach / 2);

    container.setTexture(resMngr.getTexture(Textures::ID::Results));
    container.setTextureRect(sf::IntRect(2, 36, acw, ach));
    container.setPosition(acx, acy);

    for (std::size_t i = 0; i < results.size(); ++i)
    {
        results[i].setFont(resMngr.getFont(Fonts::ID::Default));
        results[i].setColor(sf::Color::White);
        results[i].setCharacterSize(25);
        results[i].setPosition(acx + 425, acy + 165 + (32 * i));
        results[i].setString("0");
    }

    options = std::make_unique<GraphicMenu>
    (
        std::list<GraphicMenu::MenuOptionData>
        {
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuClose
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::MainMenu,
                        Transitions::ID::Fade,
                        sf::milliseconds(1000)
                    );
                    reset();
                },
                sf::Vector2f(acx + 373, acy + 539),
                sf::IntRect(36, 2, 166, 28),
                sf::IntRect(204, 2, 166, 28)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(0, 0),
            sf::IntRect(0, 0, 0, 0)
        },
        resMngr.getTexture(Textures::ID::Results)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Results Render Texture");
    }
}

void Results::setResults(const std::array<std::string, 8>& results)
{
    for (std::size_t i = 0; i < results.size(); ++i)
    {
        this->results[i].setString(results[i]);
    }
}

void Results::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        options->execCurrentOption
        (
            sf::Vector2f(event.mouseButton.x, event.mouseButton.y)
        );
        reset();
    }
}

void Results::update(const sf::Time&)
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;
    options->setCurrentOption
    (
        static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))
    );
}

void Results::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    window.draw(background);
    window.draw(container);
    window.draw(*options.get());
    for (auto& r : results)
    {
        window.draw(r);
    }
}

const sf::Texture* Results::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    snapShot.draw(background);
    snapShot.draw(container);
    snapShot.draw(*options.get());
    for (auto& r : results)
    {
        snapShot.draw(r);
    }
    snapShot.display();

    return &snapShot.getTexture();
}

void Results::reset()
{
    options->setCurrentOption(sf::Vector2f(0, 0));
}
