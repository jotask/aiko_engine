#pragma once

#include "time.h"
#include <SFML/Graphics.hpp>

class Kimo
{
public:

    virtual void update(const TimeStamp& delta) = 0;
    virtual void render(sf::RenderWindow&)      = 0;

};