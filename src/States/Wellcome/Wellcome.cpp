#include "Wellcome.h"

#include "StateManager.h"
#include "ResourceManager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Wellcome::Wellcome(StateManager& stateManager)
    : State(stateManager)
{
    using Textures = ResourceManager::Textures;
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;
    const sf::Vector2u& windowSize = getStateManager().getSharedContext().window.getSize();

    background.setTexture(resMngr.getTexture(Textures::Background));

    wellcome.setTexture(resMngr.getTexture(Textures::Wellcome));
    wellcome.setPosition(0, (windowSize.y / 2) - (wellcome.getTextureRect().height / 2));
}

void Wellcome::handleInput(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        getStateManager().pushState(StateManager::StateType::MainMenu);
    }
}

void Wellcome::update(const sf::Time&)
{
}

void Wellcome::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
    window.draw(wellcome);
}
