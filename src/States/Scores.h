/*************************************************************************
**
** Fastwriter
** Copyright (C) 2016 Sysyfydev (sysyfydev@gmail.com)
**
** This software is provided 'as-is', without any express or implied warranty.
** In no event will the authors be held liable for any damages arising
** from the use of this software.
**
** Permission is granted to anyone to use this software for any purpose,
** including commercial applications, and to alter it and redistribute it freely,
** subject to the following restrictions:
**
** 1. The origin of this software must not be misrepresented;
**    you must not claim that you wrote the original software.
**    If you use this software in a product, an acknowledgment
**    in the product documentation is required.
**
** 2. Altered source versions must be plainly marked as such,
**    and must not be misrepresented as being the original software.
**
** 3. This notice may not be removed or altered from any source distribution.
**
*************************************************************************/

#ifndef SCORES_H
#define SCORES_H

#include "State.h"

#include "GraphicMenu.h"
#include "ScoresControl.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe la escena de puntuaciones
///
////////////////////////////////////////////////////////////
class Scores : public State
{
public:
    explicit Scores(StateManager& stateManager);

    void updateScores();

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
    virtual const sf::Texture* getSnapShotTexture() override;
    virtual void reset() override;

private:
    sf::Sprite         background; ///< Sprite de fondo
    sf::Sprite         container;  ///< Contendedor de puntuaciones
    GraphicMenu::Ptr   options;    ///< Opciones de la escena
    ScoresControl::Ptr scores;     ///< Lista de puntuaciones
    sf::RenderTexture  snapShot;   ///< Captura de la escena
};

#endif // SCORES_H
