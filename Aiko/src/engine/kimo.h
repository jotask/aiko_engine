#pragma once

// sfml
#include <SFML/Graphics.hpp>

// aiko
#include "time.h"
#include "../constants.h"

class Kimo
{
public:

    virtual void update(const TimeStamp& delta) = 0;
    virtual void render(sf::RenderWindow&)      = 0;

};