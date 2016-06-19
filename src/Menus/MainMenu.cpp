#include "MainMenu.h"

#include "StateManager.h"
#include "ResourceManager.h"

#include <SFML/Graphics/RenderWindow.hpp>

MainMenu::MainMenu(StateManager& stateManager)
    : State(stateManager)
{
    using Textures = ResourceManager::Textures;
    ResourceManager& resMngr = getStateManager().getSharedContext().resourceManager;

    background.setTexture(resMngr.getTexture(Textures::Background));
}

void MainMenu::handleInput(const sf::Event& event)
{
}

void MainMenu::update(const sf::Time& dt)
{
}

void MainMenu::draw()
{
    sf::RenderWindow& window = getStateManager().getSharedContext().window;

    window.draw(background);
}
