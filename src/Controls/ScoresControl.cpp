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

#include "ScoresControl.h"

#include "ScoresFile.h"
#include <SFML/Graphics/RenderTarget.hpp>

ScoresControl::ScoresControl(const std::string& filename,
                             const sf::Font& font,
                             const std::array<int, 6>& x,
                             const std::array<int, 10>& y)
    :
      filename(filename),
      font(font),
      x(x),
      y(y)
{
    setPosition(0, 0);
    update();
}

void ScoresControl::update()
{
    ScoresFile::Matrix matrix(ScoresFile::loadFromFile(filename));

    for(int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            scores[i].at(j).setFont(font);
            scores[i].at(j).setColor(sf::Color::Black);
            scores[i].at(j).setString(matrix[i].at(j));
            scores[i].at(j).setPosition(x[i], y[j]);
        }
    }
}

void ScoresControl::draw(sf::RenderTarget& target,
                         sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(std::size_t i = 0; i < scores.size(); ++i)
    {
        for (std::size_t j = 0; j < scores[i].size(); ++j)
        {
            target.draw(scores[i].at(j), states);
        }
    }
}
