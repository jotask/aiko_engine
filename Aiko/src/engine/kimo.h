#pragma once

// sfml
#include <SFML/Graphics.hpp>

// aiko
#include "time.h"
#include "../constants.h"

namespace aiko
{
    class Kimo
    {
    public:

        virtual void update(const aiko::TimeStamp& delta) = 0;
        virtual void render(sf::RenderWindow&) = 0;
    };

}