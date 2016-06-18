#ifndef CONCRETESTATE_H
#define CONCRETESTATE_H

#include "State.h"

////////////////////////////////////////////////////////////
/// \brief Inclusiones internas
///
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Sprite.hpp>


////////////////////////////////////////////////////////////
/// \brief Declaraciones fordward
///
////////////////////////////////////////////////////////////
class StateManager;

namespace sf
{
    class Event;
    class Time;
}

////////////////////////////////////////////////////////////
/// \brief Define clase ejemplo 1
///
////////////////////////////////////////////////////////////
class ConcreteState1 : public State
{
public:
    ConcreteState1(StateManager& stateManager);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;

private:
    sf::Sprite sprite;
};

////////////////////////////////////////////////////////////
/// \brief Define clase ejemplo 2
///
////////////////////////////////////////////////////////////
class ConcreteState2 : public State
{
public:
    ConcreteState2(StateManager& stateManager);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
private:
    sf::Sprite sprite;
};

#endif // CONCRETESTATE_H
