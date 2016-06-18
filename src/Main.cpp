#include <SFML/Graphics.hpp>

#include "StateManager.h"
#include "ResourceManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 500), "States");
    ResourceManager resManager;

    StateManager stateManager(StateManager::SharedContext(window, resManager));
    stateManager.pushState(StateManager::StateType::MainMenu);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            stateManager.handleInput(event);
        }

        stateManager.update(deltaTime);

        window.clear();
        stateManager.draw();
        window.display();
    }

    return 0;
}
