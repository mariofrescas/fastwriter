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

#include "WordControl.h"

#include <random>
#include <SFML/Graphics/RenderTarget.hpp>

WordControl::WordControl(const std::string& dictionaryPath,
                         const sf::FloatRect& dropArea,
                         const sf::Texture& lettersTexture)
    : dropArea(dropArea),
      lettTexture(lettersTexture)
{
    setPosition(dropArea.left, dropArea.top);

    dictionary = std::make_unique<Dictionary>(dictionaryPath);
    wordMap = std::make_unique<WordMap>(dictionary->getWords());
}

void WordControl::reset()
{
    elapsedTime = sf::Time::Zero;
    letters.clear();
}

int WordControl::takeAll()
{
    int takeCount = letters.size();
    letters.clear();
    return takeCount;
}

bool WordControl::take(char letter)
{
    for (auto it = letters.begin(); it != letters.end();)
    {
        if (it->character == letter)
        {
            it = letters.erase(it);
            return true;
        }
        else
        {
            ++it;
        }
    }

    return false;
}

void WordControl::drop(const sf::Time& elapsed, const WordConfig& config)
{
    elapsedTime += elapsed;
    if (elapsedTime > config.dropInterval)
    {
        const std::string& word = getRandWord(config.length);
        float wordVel = config.velocity;

        int wordSize = word.size();
        int wordXpos = rand(0, dropArea.width - (wordSize * 43));

        for (int i = 0; i != wordSize; ++i)
        {
            char lettChar = word.at(i);
            sf::IntRect lettRect
            (
                decodeLettChar(lettChar) * 43,
                43 * rand(0, 7),
                43, 43
            );

            sf::Sprite lettSprite(lettTexture, lettRect);
            lettSprite.setPosition(wordXpos + (i * 43), 0);

            letters.push_back(Letter{lettChar, wordVel, lettSprite});
        }

        elapsedTime = sf::Time::Zero;
    }
}

void WordControl::moveDown(const sf::Time& dt)
{
    for (auto& letter : letters)
    {
        letter.graph.move(0, letter.velocity * dt.asSeconds());
    }
}

int WordControl::trap()
{
    sf::FloatRect trapRect
    (
        0, 0 + dropArea.height,
        dropArea.width, 1
    );

    int counter = 0;
    for (auto it = letters.begin(); it != letters.end();)
    {
        if (it->graph.getGlobalBounds().intersects(trapRect))
        {
            it = letters.erase(it);
            counter++;
        }
        else
        {
            ++it;
        }
    }

    return counter;
}

int WordControl::decodeLettChar(char letter) const
{
    int ret = 0;

    switch (letter)
    {
        case 'a': case 'A': ret = 0; break;
        case 'b': case 'B': ret = 1; break;
        case 'c': case 'C': ret = 2; break;
        case 'd': case 'D': ret = 3; break;
        case 'e': case 'E': ret = 4; break;
        case 'f': case 'F': ret = 5; break;
        case 'g': case 'G': ret = 6; break;
        case 'h': case 'H': ret = 7; break;
        case 'i': case 'I': ret = 8; break;
        case 'j': case 'J': ret = 9; break;
        case 'k': case 'K': ret = 10; break;
        case 'l': case 'L': ret = 11; break;
        case 'm': case 'M': ret = 12; break;
        case 'n': case 'N': ret = 13; break;
        case 'o': case 'O': ret = 14; break;
        case 'p': case 'P': ret = 15; break;
        case 'q': case 'Q': ret = 16; break;
        case 'r': case 'R': ret = 17; break;
        case 's': case 'S': ret = 18; break;
        case 't': case 'T': ret = 19; break;
        case 'u': case 'U': ret = 20; break;
        case 'v': case 'V': ret = 21; break;
        case 'w': case 'W': ret = 22; break;
        case 'x': case 'X': ret = 23; break;
        case 'y': case 'Y': ret = 24; break;
        case 'z': case 'Z': ret = 25; break;
    default:
        throw std::invalid_argument("Invalid character!");
    }

    return ret;
}

const std::string& WordControl::getRandWord(int length) const
{
    const WordMap::WordVector& words = wordMap->getWords(length);

    if (words.empty() && length > 1)
    {
        return getRandWord(length - 1);
    }

    return words.at(rand(0, words.size() - 1));
}

int WordControl::rand(int min, int max) const
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);

    return uni(rng);
}

void WordControl::draw(sf::RenderTarget& target,
                       sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (auto& s : letters)
    {
        target.draw(s.graph, states);
    }
}
