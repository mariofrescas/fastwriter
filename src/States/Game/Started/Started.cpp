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

#include "Started.h"

#include "MusicPlayer.h"
#include "SoundPlayer.h"
#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Started::Started(StateManager& stateManager)
    : State(stateManager),
      trapCount(0),
      takeCount(0),
      shiftStarted(false),
      shiftFinished(false)
{
    const ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const GameConf& gConf = confMngr.getCurrentConf();
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Game));
    background.setTextureRect(sf::IntRect(2, 2, 32, 32));
    background.setScale
    (   windowSize.x / background.getLocalBounds().width,
        windowSize.y / background.getLocalBounds().width
    );

    constexpr float gcw = 1130;
    constexpr float gch = 758;
    float gcx = (windowSize.x / 2) - (gcw / 2);
    float gcy = (windowSize.y / 2) - (gch / 2);

    gameCase.setTexture(resMngr.getTexture(Textures::ID::Game));
    gameCase.setTextureRect(sf::IntRect(2, 179, gcw, gch));
    gameCase.setPosition(gcx, gcy);

    controlPanel.setTexture(resMngr.getTexture(Textures::ID::Game));
    controlPanel.setTextureRect(sf::IntRect(2, 37, 1079, 140));
    controlPanel.setPosition(gcx + 26, gcy + 31);

    points = std::make_unique<PointsControl>
    (
        sf::Vector2f(gcx + 75, gcy + 45),
        std::array<sf::IntRect, 10>
        {
            sf::IntRect(2, 2, 52, 82),
            sf::IntRect(2, 86, 47, 80),
            sf::IntRect(2, 168, 52, 81),
            sf::IntRect(2, 251, 52, 81),
            sf::IntRect(2, 334, 53, 82),
            sf::IntRect(2, 418, 52, 81),
            sf::IntRect(2, 501, 52, 82),
            sf::IntRect(2, 585, 53, 81),
            sf::IntRect(2, 668, 52, 82),
            sf::IntRect(2, 752, 52, 82)
        },
        resMngr.getTexture(Textures::ID::Numbers)
    );

    wantPoints = std::make_unique<WantPointsControl>
    (
        gConf.getWantPoints(),
        sf::Vector2f(gcx + 76, gcy + 130),
        sf::IntRect(70, 2, 10, 23),
        sf::IntRect(70 + 10, 2, 1, 23),
        sf::IntRect(70 + 252, 2, 10, 23),
        sf::IntRect(70, 2, 262, 23),
        resMngr.getTexture(Textures::ID::Game)
    );

    time = std::make_unique<TimeControl>
    (
        sf::Vector2f(gcx + 390, gcy + 45),
        std::array<sf::IntRect, 11>
        {
            sf::IntRect(2, 2, 52, 82),
            sf::IntRect(2, 86, 47, 80),
            sf::IntRect(2, 168, 52, 81),
            sf::IntRect(2, 251, 52, 81),
            sf::IntRect(2, 334, 53, 82),
            sf::IntRect(2, 418, 52, 81),
            sf::IntRect(2, 501, 52, 82),
            sf::IntRect(2, 585, 53, 81),
            sf::IntRect(2, 668, 52, 82),
            sf::IntRect(2, 752, 52, 82),
            sf::IntRect(2, 836, 26, 65)
        },
        resMngr.getTexture(Textures::ID::Numbers)
    );

    shiftMode = std::make_unique<ShiftModeControl>
    (
        sf::milliseconds(gConf.getShiftModeDuration()),
        sf::milliseconds(gConf.getShiftModeNecessaryTime()),
        sf::Vector2f(gcx + 361, gcy + 128),
        sf::IntRect(334, 2, 10, 27),
        sf::IntRect(334 + 10, 2, 1, 27),
        sf::IntRect(334 + 395, 2, 15, 27),
        sf::IntRect(334, 2, 411, 27),
        resMngr.getTexture(Textures::ID::Game)
    );

    lifes = std::make_unique<LifesControl>
    (
        gConf.getInitLifes(),
        sf::Vector2f(gcx + 803, gcy + 45),
        std::array<sf::IntRect, 10>
        {
            sf::IntRect(2, 2, 52, 82),
            sf::IntRect(2, 86, 47, 80),
            sf::IntRect(2, 168, 52, 81),
            sf::IntRect(2, 251, 52, 81),
            sf::IntRect(2, 334, 53, 82),
            sf::IntRect(2, 418, 52, 81),
            sf::IntRect(2, 501, 52, 82),
            sf::IntRect(2, 585, 53, 81),
            sf::IntRect(2, 668, 52, 82),
            sf::IntRect(2, 752, 52, 82)
        },
        resMngr.getTexture(Textures::ID::Numbers)
    );

    cleaners = std::make_unique<CleanersControl>
    (
        gConf.getDefaultCleaners(),
        gConf.getMaxCleaners(),
        sf::milliseconds(gConf.getAddInterval()),
        sf::Vector2f(gcx + 800, gcy + 124),
        sf::IntRect(36, 2, 32, 33),
        resMngr.getTexture(Textures::ID::Game)
    );

    words = std::make_unique<WordControl>
    (
        resMngr.getDictionary(Dictionaries::ID::EN_DIC),
        sf::FloatRect(gcx + 129.670, gcy + 172, 1100, 520),
        resMngr.getTexture(Textures::ID::Letters)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Started Render Texture");
    }
}

void Started::setGameDifficulty(const Configs::ID& diffty)
{
    confMngr.setCurrentConf(diffty);
    GameConf& cConf = confMngr.getCurrentConf();

    shiftMode->reconfigure
    (
        sf::milliseconds(cConf.getShiftModeDuration()),
        sf::milliseconds(cConf.getShiftModeNecessaryTime())
    );

    lifes->reconfigure
    (
        cConf.getInitLifes()
    );

    cleaners->reconfigure
    (
        cConf.getDefaultCleaners(),
        cConf.getMaxCleaners(),
        sf::milliseconds(cConf.getAddInterval())
    );
}

void Started::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::A: handleInputLetter('a'); break;
        case sf::Keyboard::B: handleInputLetter('b'); break;
        case sf::Keyboard::C: handleInputLetter('c'); break;
        case sf::Keyboard::D: handleInputLetter('d'); break;
        case sf::Keyboard::E: handleInputLetter('e'); break;
        case sf::Keyboard::F: handleInputLetter('f'); break;
        case sf::Keyboard::G: handleInputLetter('g'); break;
        case sf::Keyboard::H: handleInputLetter('h'); break;
        case sf::Keyboard::I: handleInputLetter('i'); break;
        case sf::Keyboard::J: handleInputLetter('j'); break;
        case sf::Keyboard::K: handleInputLetter('k'); break;
        case sf::Keyboard::L: handleInputLetter('l'); break;
        case sf::Keyboard::M: handleInputLetter('m'); break;
        case sf::Keyboard::N: handleInputLetter('n'); break;
        case sf::Keyboard::O: handleInputLetter('o'); break;
        case sf::Keyboard::P: handleInputLetter('p'); break;
        case sf::Keyboard::Q: handleInputLetter('q'); break;
        case sf::Keyboard::R: handleInputLetter('r'); break;
        case sf::Keyboard::S: handleInputLetter('s'); break;
        case sf::Keyboard::T: handleInputLetter('t'); break;
        case sf::Keyboard::U: handleInputLetter('u'); break;
        case sf::Keyboard::V: handleInputLetter('v'); break;
        case sf::Keyboard::W: handleInputLetter('w'); break;
        case sf::Keyboard::X: handleInputLetter('x'); break;
        case sf::Keyboard::Y: handleInputLetter('y'); break;
        case sf::Keyboard::Z: handleInputLetter('z'); break;
        case sf::Keyboard::Escape:
            getStateManager().getSharedContext().musicPlayer.pause
            (
                true
            );
            getStateManager().getSharedContext().soundPlayer.play
            (
                Sounds::ID::MenuOpen
            );
            getStateManager().setCurrentState
            (
                States::ID::Paused,
                Transitions::ID::CircleClose,
                sf::milliseconds(500)
            );
            break;
        case sf::Keyboard::LShift:
            handleCleanerActivation();
            break;
        case sf::Keyboard::Space:
            handleShiftModeActivation();
            break;
        default:
            break;
        }
    }
}

void Started::update(const sf::Time& dt)
{
    const GameConf& gConf = confMngr.getCurrentConf();

    time->tick(dt);
    shiftMode->update(dt);
    cleaners->addTime(dt);

    if (!shiftMode->isActive())
    {
        WordControl::WordConfig wConf
        {
            gConf.getDropVelocity(),
            gConf.getWordLength(),
            sf::milliseconds(gConf.getDropTime())
        };

        words->drop(dt, wConf);
        words->moveDown(dt);
        trapCount += words->trap();
    }

    if (trapCount > 0)
    {
        --trapCount;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::LetterTrap
        );
        lifes->decrement(gConf.getLifesDecrement());
        if (!lifes->remain())
        {
//            getStateManager().getSharedContext().musicPlayer.stop();
//            getStateManager().getSharedContext().soundPlayer.play
//            (
//                Sounds::ID::GameEnd
//            );
//            getStateManager().setCurrentState
//            (
//                States::ID::MainMenu,
//                Transitions::ID::CircleClose,
//                sf::milliseconds(1000)
//            );
        }
    }

    if (takeCount > 0)
    {
        --takeCount;
        points->increment(gConf.getPointsIncrement());
        wantPoints->addPoints(gConf.getPointsIncrement());

        if (wantPoints->isFull())
        {
            getStateManager().getSharedContext().soundPlayer.play
            (
                Sounds::ID::LifesIncrement
            );
            lifes->increment(gConf.getLifesIncrement());
        }
    }

    if (!shiftMode->canActive() && !shiftMode->isActive() && shiftStarted)
    {
        shiftStarted = false;
        shiftFinished = true;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::ShiftModeFinish
        );
    }

    if (shiftMode->canActive() && shiftFinished)
    {
        shiftFinished = false;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::ShiftModeReady
        );
    }
}

void Started::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(gameCase);

    for (auto& letter : words->getGraph())
    {
        window.draw(letter.graph);
    }

    window.draw(controlPanel);
    window.draw(*points.get());
    window.draw(*wantPoints.get());
    window.draw(*time.get());
    window.draw(*shiftMode.get());
    window.draw(*lifes.get());
    window.draw(*cleaners.get());
}

const sf::Texture* Started::getSnapShotTexture()
{
    snapShot.clear();
    snapShot.draw(background);
    snapShot.draw(gameCase);

    for (auto& letter : words->getGraph())
    {
        snapShot.draw(letter.graph);
    }

    snapShot.draw(controlPanel);
    snapShot.draw(*points.get());
    snapShot.draw(*wantPoints.get());
    snapShot.draw(*time.get());
    snapShot.draw(*shiftMode.get());
    snapShot.draw(*lifes.get());
    snapShot.draw(*cleaners.get());
    snapShot.display();

    return &snapShot.getTexture();
}

void Started::reset()
{
    points->reset();
    wantPoints->reset();
    time->reset();
    shiftMode->reset();
    lifes->reset();
    cleaners->reset();
    words->reset();
    trapCount = 0;
    takeCount = 0;
    shiftStarted = false;
    shiftFinished = false;
}

void Started::handleInputLetter(char letter)
{
    const GameConf& gConf = confMngr.getCurrentConf();

    if (words->take(letter))
    {
        ++takeCount;
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::LetterTake
        );
    }
    else
    {
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::LetterTakeFail
        );
        points->decrement(gConf.getPointsIncrement());
    }
}

void Started::handleShiftModeActivation()
{
    if (shiftMode->canActive())
    {
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::ShiftModeStart
        );
        shiftStarted = true;
        shiftMode->active();
    }
}

void Started::handleCleanerActivation()
{
    if (cleaners->canClean())
    {
        getStateManager().getSharedContext().soundPlayer.play
        (
            Sounds::ID::CleanerActive
        );
        cleaners->clean();
        takeCount += words->takeAll();
    }
}
