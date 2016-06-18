#ifndef MAINMENU_H
#define MAINMENU_H

#include "State.h"

class MainMenu : public State
{
public:
    MainMenu(StateManager& stateManager);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
};

#endif // MAINMENU_H
