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

#include "SoundPlayer.h"

SoundPlayer::SoundPlayer(ResourceManager& resMngr)
    : resMngr(resMngr)
{
}

void SoundPlayer::play(const Sounds::ID &sound)
{
    sounds.push_back(sf::Sound(resMngr.getSound(sound)));
    sounds.back().play();
}

void SoundPlayer::removeStoppedSounds()
{
    sounds.remove_if
    (
        [] (const sf::Sound& sound)
        {
            return sound.getStatus() == sf::Sound::Stopped;
        }
    );
}
