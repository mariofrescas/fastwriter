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

#include "Starting.h"

#include "MusicPlayer.h"
#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

Starting::Starting(StateManager& stateManager, State* parent)
    : State(stateManager, parent),
      playOnce1(true),
      playOnce2(false),
      playOnce3(false),
      playOnce4(false)
{
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Starting));
    background.setTextureRect(sf::IntRect(2, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    starting.setTexture(resMngr.getTexture(Textures::ID::Starting));
    starting.setTextureRect(sf::IntRect(112, 169, 268, 268));
    starting.setPosition
    (
        (windowSize.x / 2) - (starting.getGlobalBounds().width / 2),
        (windowSize.y / 2) - (starting.getGlobalBounds().height / 2)
    );

    countDown = std::make_unique<CountDownControl>
    (
        sf::seconds(3),
        sf::Vector2f((windowSize.x / 2) - (110 / 2), (windowSize.y / 2) - (168 / 2)),
        std::array<sf::IntRect, 10>
        {
            sf::IntRect(2, 169, 108, 168),
            sf::IntRect(36, 2, 96, 162),
            sf::IntRect(134, 2, 108, 165),
            sf::IntRect(244, 2, 110, 165),
            sf::IntRect(0, 0, 0, 0),
            sf::IntRect(0, 0, 0, 0),
            sf::IntRect(0, 0, 0, 0),
            sf::IntRect(0, 0, 0, 0),
            sf::IntRect(0, 0, 0, 0),
            sf::IntRect(0, 0, 0, 0)
        },
        resMngr.getTexture(Textures::ID::Starting)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Starting Render Texture");
    }
}

void Starting::handleInput(const sf::Event&)
{
}

void Starting::update(const sf::Time& dt)
{
    elapsed += dt;

    if (playOnce1)
    {
        playOnce1 = false;
        playOnce2 = true;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::CountDown
        );
    }

    if(elapsed >= sf::seconds(1) && playOnce2)
    {
        playOnce2 = false;
        playOnce3 = true;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::CountDown
        );
    }

    if(elapsed >= sf::seconds(2) && playOnce3)
    {
        playOnce3 = false;
        playOnce4 = true;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::CountDown
        );
    }

    if(elapsed >= sf::seconds(3) && playOnce4)
    {
        playOnce4 = false;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::CountDownFinish
        );
    }

    if (countDown->finished(dt))
    {
        getStateManager().setCurrentState
        (
            States::ID::Started,
            Transitions::ID::CircleOpen,
            sf::milliseconds(1000)
        );
        getStateManager().getSharedContext().musicPlayer.play
        (
            Music::ID::Started
        );

        reset();
    }
}

void Starting::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    window.draw(background);
    window.draw(starting);
    window.draw(*countDown.get());
}

const sf::Texture* Starting::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(sf::Sprite(*getParentState().getSnapShotTexture()));
    snapShot.draw(background);
    snapShot.draw(starting);
    snapShot.draw(*countDown.get());
    snapShot.display();

    return &snapShot.getTexture();
}

void Starting::reset()
{
    playOnce1 = true;
    countDown->reset();
    elapsed = sf::Time::Zero;
}
