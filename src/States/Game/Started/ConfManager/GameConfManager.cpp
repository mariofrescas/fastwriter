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

#include "GameConfManager.h"

#include "HardConf.h"
#include "NormalConf.h"
#include "ExpertConf.h"

GameConfManager::GameConfManager(const Configs::ID& defaultConf)
{
    confs[Configs::ID::Hard] = std::make_unique<HardConf>();
    confs[Configs::ID::Normal] = std::make_unique<NormalConf>();
    confs[Configs::ID::Expert] = std::make_unique<ExpertConf>();

    currentConf = confs[defaultConf].get();
}

void GameConfManager::setCurrentConf(const Configs::ID& config)
{
    currentConf = confs[config].get();
}

GameConf& GameConfManager::getCurrentConf() const
{
    return *currentConf;
}
