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

#include "ScoresFile.h"

#include <fstream>
#include <sstream>

ScoresFile::Matrix ScoresFile::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to load: " + filename);
    }

    ScoresFile::Matrix scores;
    std::string line = "";

    for(std::size_t i = 0; i < scores.size(); ++i)
    {
        for (std::size_t j = 0; j < scores[i].size(); ++j)
        {
            std::getline(file, line);
            scores[i].at(j) = line;
        }
    }

    file.close();
    return scores;
}

void ScoresFile::trySaveScore(const std::string& filename,
                              const std::size_t& pointsp,
                              const std::array<std::string, 6>& score)
{
    std::size_t pos = 0;
    ScoresFile::Matrix scores = ScoresFile::loadFromFile(filename);

    for (std::size_t j = 0; j < scores[pointsp].size(); ++j)
    {
        if (std::stoi(score[pointsp]) > std::stoi(scores[pointsp].at(j)))
        {
            break;
        }
        else
        {
            ++pos;
        }
    }

    if (pos < scores[pointsp].size())
    {
        for(std::size_t i = 0; i < scores.size(); ++i)
        {
            for (std::size_t j = scores[i].size() - 1; j > pos; --j)
            {
                scores[i].at(j) = scores[i].at(j - 1);
            }
            scores[i].at(pos) = score[i];
        }

        std::ofstream file(filename, std::ios::trunc);

        if (!file.is_open())
        {
            throw std::runtime_error("Failed to load: " + filename);
        }

        for(std::size_t i = 0; i < scores.size(); ++i)
        {
            for (std::size_t j = 0; j < scores[i].size(); ++j)
            {
                file << scores[i].at(j) << "\n";
            }
        }

        file.close();
    }
}
