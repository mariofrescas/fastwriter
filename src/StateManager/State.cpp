#include "State.h"

State::State(StateManager& stateManager)
    : mStateManager(stateManager)
{
}

StateManager& State::getStateManager() const
{
    return mStateManager;
}
