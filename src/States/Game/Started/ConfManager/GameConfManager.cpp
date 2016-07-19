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

#include "GameConfManager.h"

#include "NormalConf.h"

GameConfManager::GameConfManager(const ConfType& defaultType)
{
    confs[ConfType::Normal] = std::make_unique<NormalConf>();

    currentConf = confs[defaultType].get();
}

void GameConfManager::setCurrentConf(const ConfType& confType)
{
    currentConf = confs[confType].get();
}

GameConf& GameConfManager::getCurrentConf() const
{
    return *currentConf;
}
