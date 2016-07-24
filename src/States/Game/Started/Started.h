/*************************************************************************
** Copyright (C) 2016 Sysyfydev <sysyfydev@gmail.com>.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
