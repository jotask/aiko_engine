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

        virtual void init() {};

        virtual void preUpdate(const aiko::TimeStamp& delta) {};
        virtual void update(const aiko::TimeStamp& delta) = 0;
        virtual void postUpdate(const aiko::TimeStamp& delta) {};

        virtual void preRender(sf::RenderWindow&) {};
        virtual void render(sf::RenderWindow&) = 0;
        virtual void postRender(sf::RenderWindow&) {};

        virtual void preDebug(sf::RenderWindow&) {};
        virtual void debug(sf::RenderWindow&) {};
        virtual void postDebug(sf::RenderWindow&) {};
    };

}