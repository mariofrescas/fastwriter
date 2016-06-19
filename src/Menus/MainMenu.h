#ifndef MAINMENU_H
#define MAINMENU_H

#include "State.h"

////////////////////////////////////////////////////////////
/// \brief Inclusiones internas
///
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Sprite.hpp>

class MainMenu : public State
{
public:
    MainMenu(StateManager& stateManager);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;

private:
    sf::Sprite background;
};

#endif // MAINMENU_H
