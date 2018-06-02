#pragma once

#include "time.h"
#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera();
    ~Camera();

    void update(const TimeStamp& delta);
    void render(sf::RenderWindow&);

};

