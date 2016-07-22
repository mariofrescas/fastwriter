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

#include "Started.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Started::Started(StateManager& stateManager)
    : State(stateManager),
      trapCount(0),
      takeCount(0)
{
    const ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const GameConf& gConf = confMngr.getCurrentConf();
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::ID::Background));

    constexpr float gcw = 1129.520;
    constexpr float gch = 757.696;
    float gcx = (windowSize.x / 2) - (gcw / 2);
    float gcy = (windowSize.y / 2) - (gch / 2);

    gameCase.setTexture(resMngr.getTexture(Textures::ID::Game));
    gameCase.setTextureRect(sf::IntRect(0, 0, gcw, gch));
    gameCase.setPosition(gcx, gcy);


    wordsCover.setTexture(resMngr.getTexture(Textures::ID::Game));
    wordsCover.setTextureRect(sf::IntRect(129.670, 172, 876.108, 43));
    wordsCover.setPosition(gcx + 129.670, gcy + 172);

    points = std::make_unique<PointsControl>
    (
        90,
        sf::Vector2f(gcx + 84, gcy + 35),
        resMngr.getFont(Fonts::ID::Default)
    );

    wantPoints = std::make_unique<WantPointsControl>
    (
        gConf.getWantPoints(),
        sf::Color(27, 156, 63),
        sf::FloatRect(gcx + 81, gcy + 135, 252, 12)
    );

    time = std::make_unique<TimeControl>
    (
        90,
        sf::Vector2f(gcx + 370, gcy + 35),
        resMngr.getFont(Fonts::ID::Default)
    );

    shiftMode = std::make_unique<ShiftModeControl>
    (
        sf::milliseconds(gConf.getShiftModeDuration()),
        sf::milliseconds(gConf.getShiftModeNecessaryTime()),
        sf::Color(140, 26, 50),
        sf::FloatRect(gcx + 369, gcy + 135 , 396, 12)
    );

    lifes = std::make_unique<LifesControl>
    (
        gConf.getInitLifes(),
        90,
        sf::Vector2f(gcx + 803, gcy + 35),
        resMngr.getFont(Fonts::ID::Default)
    );

    cleaners = std::make_unique<CleanersControl>
    (
        gConf.getDefaultCleaners(),
        gConf.getMaxCleaners(),
        sf::milliseconds(gConf.getAddInterval()),
        sf::Vector2f(gcx + 800, gcy + 124),
        resMngr.getTexture(Textures::ID::Game),
        sf::IntRect(1129.520, 0, 23, 23)
    );

    words = std::make_unique<WordControl>
    (
        "res/dictionaries/en.dic",
        sf::FloatRect(gcx + 129.670, gcy + 172, 1100, 520),
        resMngr.getTexture(Textures::ID::Letters)
    );

    if (!snapShot.create(windowSize.x, windowSize.y))
    {
        throw std::runtime_error("Can not create Wellcome Render Texture");
    }
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
            getStateManager().setCurrentState(States::ID::MainMenu);
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

    time->update(dt);
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
        lifes->decrement(gConf.getLifesDecrement());
        if (!lifes->remain())
        {
            // TODO: End Game
        }
    }

    if (takeCount > 0)
    {
        --takeCount;
        points->increment(gConf.getPointsIncrement());
        wantPoints->addPoints(gConf.getPointsIncrement());

        if (wantPoints->isFull())
        {
            lifes->increment(gConf.getLifesIncrement());
        }
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

    window.draw(wordsCover);
    window.draw(points->getGraph());
    window.draw(wantPoints->getGraph());
    window.draw(time->getGraph());
    window.draw(shiftMode->getGraph());
    window.draw(lifes->getGraph());

    for (auto& cleaner : cleaners->getGraph())
    {
        window.draw(cleaner);
    }
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

    snapShot.draw(wordsCover);
    snapShot.draw(points->getGraph());
    snapShot.draw(wantPoints->getGraph());
    snapShot.draw(time->getGraph());
    snapShot.draw(shiftMode->getGraph());
    snapShot.draw(lifes->getGraph());

    for (auto& cleaner : cleaners->getGraph())
    {
        snapShot.draw(cleaner);
    }
    snapShot.display();

    return &snapShot.getTexture();
}

void Started::handleInputLetter(char letter)
{
    const GameConf& gConf = confMngr.getCurrentConf();

    if (words->take(letter))
    {
        ++takeCount;
    }
    else
    {
        points->decrement(gConf.getPointsIncrement());
    }
}

void Started::handleShiftModeActivation()
{
    if (shiftMode->canActive())
    {
        shiftMode->active();
    }
}

void Started::handleCleanerActivation()
{
    if (cleaners->canClean())
    {
        cleaners->clean();
        takeCount += words->takeAll();
    }
}
