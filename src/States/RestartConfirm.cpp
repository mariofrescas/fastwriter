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

#include "RestartConfirm.h"

#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

RestartConfirm::RestartConfirm(StateManager& stateManager, State* parent)
    : State(stateManager, parent)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::RestartConfirm));
    background.setTextureRect(sf::IntRect(2, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr int cw = 940;
    constexpr int ch = 156;
    int cx = (windowSize.x / 2) - (cw / 2);
    int cy = (windowSize.y / 2) - (ch / 2);

    constexpr int mc = 430;
    int mx = cx + 52;
    int my = cy + 47;

    restartConfirmMenu = std::make_unique<GraphicMenu>
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
                        States::ID::Paused,
                        Transitions::ID::CircleOpen,
                        sf::milliseconds(500)
                    );
                },
                sf::Vector2f(mx, my),
                sf::IntRect(36, 2, 253, 57),
                sf::IntRect(291, 2, 253, 57)
            },
            GraphicMenu::MenuOptionData
            {
                [&] ()
                {
                    getStateManager().getState(States::ID::Started).reset();
                    getStateManager().getSharedContext().soundPlayer.play
                    (
                        Sounds::ID::MenuClose
                    );
                    getStateManager().setCurrentState
                    (
                        States::ID::Starting,
                        Transitions::ID::CircleClose,
                        sf::milliseconds(500)
                    );
                },
                sf::Vector2f(mx + (mc * 1), my),
                sf::IntRect(878, 2, 330, 58),
                sf::IntRect(546, 2, 330, 58)
            }
        },
        GraphicMenu::MenuContainerData
        {
            sf::Vector2f(cx, cy),
            sf::IntRect(2, 62, cw, ch)
        },
        resMngr.getTexture(Textures::ID::RestartConfirm)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create RestartConfirm Render Texture");
    }
}

void RestartConfirm::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        restartConfirmMenu->execCurrentOption
        (
            sf::Vector2f(event.mouseButton.x, event.mouseButton.y)
        );
        reset();
    }
}

void RestartConfirm::update(const sf::Time&)
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;
    restartConfirmMenu->setCurrentOption
    (
        static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))
    );
}

void RestartConfirm::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    window.draw(background);
    window.draw(*restartConfirmMenu.get());
}

const sf::Texture* RestartConfirm::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    snapShot.draw(background);
    snapShot.draw(*restartConfirmMenu.get());
    snapShot.display();

    return &snapShot.getTexture();
}

void RestartConfirm::reset()
{
    restartConfirmMenu->setCurrentOption(sf::Vector2f(0, 0));
}

