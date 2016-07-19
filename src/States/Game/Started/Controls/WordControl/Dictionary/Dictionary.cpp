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
