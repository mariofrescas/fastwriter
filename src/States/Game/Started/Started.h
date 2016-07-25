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

#ifndef STARTED_H
#define STARTED_H

#include "State.h"

#include "PointsControl.h"
#include "WantPointsControl.h"
#include "TimeControl.h"
#include "ShiftModeControl.h"
#include "LifesControl.h"
#include "CleanersControl.h"
#include "WordControl.h"
#include "GameConfManager.h"
#include <SFML/Graphics/RenderTexture.hpp>

////////////////////////////////////////////////////////////
/// \brief Describe la escena de juego iniciado
///
////////////////////////////////////////////////////////////
class Started : public State
{
public:
    explicit Started(StateManager& stateManager);

    void setGameDifficulty(const Configs::ID& diffty);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
    virtual const sf::Texture* getSnapShotTexture() override;
    virtual void reset() override;

private:
    sf::Sprite             background; ///< Fondo
    sf::Sprite             gameCase;   ///< Tablero de juego
    sf::Sprite             wordsCover; ///< Ocultar la aparicion de las letras
    PointsControl::Ptr     points;     ///< Control de puntos
    WantPointsControl::Ptr wantPoints; ///< Control de puntos deseados
    TimeControl::Ptr       time;       ///< Control de tiempo transcurrido
    ShiftModeControl::Ptr  shiftMode;  ///< Control de modo de juego Shift
    LifesControl::Ptr      lifes;      ///< Control de vidas
    CleanersControl::Ptr   cleaners;   ///< Control de limpiadores
    WordControl::Ptr       words;      ///< Control de palabras
    GameConfManager        confMngr;   ///< Configuracion de dificultad
    sf::RenderTexture      snapShot;   ///< Caputra de la escena
    int                    trapCount;  ///< Acomulacion de vidas perdidas
    int                    takeCount;  ///< Acomulacion de puntos ganados

    void handleInputLetter(char letter);
    void handleShiftModeActivation();
    void handleCleanerActivation();
};

#endif // STARTED_H
