#include "ConcreteState.h"

#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "ResourceManager.h"
#include <iostream>

ConcreteState1::ConcreteState1(StateManager& stateManager)
    : State(stateManager)
{
    sprite.setTexture(getStateManager().getSharedContext().resourceManager.getTexture(ResourceManager::TextureId::ConcreteTexture1));
}

void ConcreteState1::handleInput(const sf::Event &event)
{
    std::cout << "ConcreteState1: HandleInput" << std::endl;

    if (event.type == sf::Event::KeyPressed)
    {
        getStateManager().pushState(StateManager::StateType::ConcreteState2);
    }
}

void ConcreteState1::update(const sf::Time& dt)
{
    std::cout << "ConcreteState1: Update" << std::endl;
}

void ConcreteState1::draw()
{
    std::cout << "ConcreteState1: Draw" << std::endl;

    getStateManager().getSharedContext().window.draw(sprite);
}

ConcreteState2::ConcreteState2(StateManager& stateManager)
    : State(stateManager)
{
    sprite.setTexture(getStateManager().getSharedContext().resourceManager.getTexture(ResourceManager::TextureId::ConcreteTexture2));
}

void ConcreteState2::handleInput(const sf::Event& event)
{
    std::cout << "ConcreteState2: HandleInput" << std::endl;

    if (event.type == sf::Event::KeyPressed)
    {
        getStateManager().popState();
    }
}

void ConcreteState2::update(const sf::Time& dt)
{
    std::cout << "ConcreteState2: Update" << std::endl;
}

void ConcreteState2::draw()
{
    std::cout << "ConcreteState2: Draw" << std::endl;

    getStateManager().getSharedContext().window.draw(sprite);
}
