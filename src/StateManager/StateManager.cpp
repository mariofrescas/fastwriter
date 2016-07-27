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

#include "StateManager.h"

// WARNING: Uncomment to disable assertions
// #define NDEBUG
#include <cassert>

#include "Fade.h"
#include "CircleOpen.h"
#include "CircleClose.h"
#include "Black.h"
#include "Wellcome.h"
#include "MainMenu.h"
#include "About.h"
#include "DifftyMenu.h"
#include "Starting.h"
#include "Started.h"
#include "Paused.h"
#include "QuitConfirm.h"
#include "RestartConfirm.h"

StateManager::SharedContext::SharedContext(sf::RenderWindow& window,
                                           MusicPlayer& musicPlayer,
                                           SoundPlayer& soundPlayer,
                                           ResourceManager& resManager)
    : window(window),
      musicPlayer(musicPlayer),
      soundPlayer(soundPlayer),
      resourceManager(resManager)
{
}

StateManager::StateManager(const SharedContext& sharedContex)
{
    shdContex = std::make_unique<SharedContext>
    (
        sharedContex.window,
        sharedContex.musicPlayer,
        sharedContex.soundPlayer,
        sharedContex.resourceManager
    );

    states[States::ID::Black] = std::make_unique<Black>(*this);
    states[States::ID::Wellcome] = std::make_unique<Wellcome>(*this);
    states[States::ID::MainMenu] = std::make_unique<MainMenu>(*this);
    states[States::ID::About] = std::make_unique<About>(*this);
    states[States::ID::DifftyMenu] = std::make_unique<DifftyMenu>(*this);
    states[States::ID::Started] = std::make_unique<Started>(*this);
    states[States::ID::Starting] = std::make_unique<Starting>
    (
        *this,
        states[States::ID::Started].get()
    );
    states[States::ID::Paused] = std::make_unique<Paused>
    (
        *this,
        states[States::ID::Started].get()
    );
    states[States::ID::QuitConfirm] = std::make_unique<QuitConfirm>
    (
        *this,
        states[States::ID::Paused].get()
    );
    states[States::ID::RestartConfirm] = std::make_unique<RestartConfirm>
    (
        *this,
        states[States::ID::Paused].get()
    );

    transitions[Transitions::ID::Fade] = std::make_unique<Fade>(*this);
    transitions[Transitions::ID::CircleOpen] = std::make_unique<CircleOpen>(*this);
    transitions[Transitions::ID::CircleClose] = std::make_unique<CircleClose>(*this);
}

void StateManager::setCurrentState(const States::ID& state)
{
    assert(!states.empty());
    assert(!(states.find(state) == states.end()));

    currentState = states[state].get();
}

void StateManager::setCurrentState(const States::ID& state,
                                   const Transitions::ID& transition,
                                   const sf::Time& duration)
{
    assert(!states.empty());
    assert(!(states.find(state) == states.end()));
    assert(!transitions.empty());
    assert(!(transitions.find(transition) == transitions.end()));
    assert(!(currentState->getSnapShotTexture() == nullptr));
    assert(!(states[state]->getSnapShotTexture() == nullptr));

    transitions[transition]->configure
    (
        duration,
        state,
        *currentState->getSnapShotTexture(),
        *states[state]->getSnapShotTexture()
    );

    currentState = transitions[transition].get();
}

State& StateManager::getState(const States::ID& state)
{
    return *states[state];
}

StateManager::SharedContext& StateManager::getSharedContext() const
{
    return *shdContex.get();
}

void StateManager::handleInput(const sf::Event& event)
{
    assert(!(currentState == nullptr));

    currentState->handleInput(event);
}

void StateManager::update(const sf::Time& dt)
{
    assert(!(currentState == nullptr));

    currentState->update(dt);
}

void StateManager::draw()
{
    assert(!(currentState == nullptr));

    currentState->draw();
}
