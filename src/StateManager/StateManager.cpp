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

#include "MainMenu.h"

StateManager::SharedContext::SharedContext(sf::RenderWindow& window, ResourceManager& resManager)
    : window(window), resourceManager(resManager)
{
}

StateManager::StateManager(const SharedContext& sharedContex)
{
    shdContex = std::make_unique<SharedContext>(sharedContex.window, sharedContex.resourceManager);

    states[StateType::MainMenu] = std::make_unique<MainMenu>(*this);
}

void StateManager::pushState(const StateManager::StateType& state)
{
    assert(!states.empty());
    assert(!(states.find(state) == states.end()));

    stateStack.push(states[state].get());
}

void StateManager::popState()
{
    assert(!stateStack.empty());

    stateStack.pop();
}

StateManager::SharedContext& StateManager::getSharedContext() const
{
    return *shdContex.get();
}

void StateManager::handleInput(const sf::Event& event)
{
    assert(!stateStack.empty());

    stateStack.top()->handleInput(event);
}

void StateManager::update(const sf::Time& dt)
{
    assert(!stateStack.empty());

    stateStack.top()->update(dt);
}

void StateManager::draw()
{
    assert(!stateStack.empty());

    stateStack.top()->draw();
}
