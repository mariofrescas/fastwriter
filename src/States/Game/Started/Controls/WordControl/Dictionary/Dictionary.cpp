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

#include "Dictionary.h"

#include <fstream>

Dictionary::Dictionary(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to load: " + filename);
    }

    int lineCount = 0;
    std::string line = "";

    while (std::getline(file, line))
    {
        if (line.at(0) != '#')
        {
            lineCount++;
            words.push_back(line);
        }
    }

    if (lineCount == 0)
    {
        file.close();
        throw std::runtime_error("Invalid dictionary: " + filename);
    }

    file.close();
}

const std::list<std::string>& Dictionary::getWords() const
{
    return words;
}
