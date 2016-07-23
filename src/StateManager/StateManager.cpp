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

#include "StateManager.h"

// WARNING: Uncomment to disable assertions
// #define NDEBUG
#include <cassert>

#include "Fade.h"
#include "CircleOpen.h"
#include "CircleClose.h"
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
                                           ResourceManager& resManager)
    : window(window),
      resourceManager(resManager)
{
}

StateManager::StateManager(const SharedContext& sharedContex)
{
    shdContex = std::make_unique<SharedContext>
    (
        sharedContex.window,
        sharedContex.resourceManager
    );

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

State& StateManager::getCurrentState() const
{
    assert(!(currentState == nullptr));

    return *currentState;
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
