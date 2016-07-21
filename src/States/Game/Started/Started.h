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

#include <SFML/Graphics/RenderTexture.hpp>
#include "PointsControl.h"
#include "WantPointsControl.h"
#include "TimeControl.h"
#include "ShiftModeControl.h"
#include "LifesControl.h"
#include "CleanersControl.h"
#include "WordControl.h"
#include "GameConfManager.h"

class Started : public State
{
public:
    explicit Started(StateManager& stateManager);

    virtual void handleInput(const sf::Event& event) override;
    virtual void update(const sf::Time& dt) override;
    virtual void draw() override;
    virtual const sf::Texture* getSnapShotTexture() override;

private:
    sf::Sprite background;
    sf::Sprite gameCase;
    sf::Sprite wordsCover;
    PointsControl::Ptr points;
    WantPointsControl::Ptr wantPoints;
    TimeControl::Ptr time;
    ShiftModeControl::Ptr shiftMode;
    LifesControl::Ptr lifes;
    CleanersControl::Ptr cleaners;
    WordControl::Ptr words;
    GameConfManager confMngr;
    sf::RenderTexture snapShot;
    int trapCount;
    int takeCount;

    void handleInputLetter(char letter);
    void handleShiftModeActivation();
    void handleCleanerActivation();
};

#endif // STARTED_H
