#pragma once

// sfml
#include <SFML/Graphics.hpp>

// aiko
#include "../time.h"

class Component
{
public:
    Component();
    virtual ~Component();

    virtual void update(const TimeStamp& delta) = 0;
    virtual void render(sf::RenderWindow&) = 0;
    


};

