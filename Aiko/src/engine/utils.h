#pragma once

#include "../constants.h"
#include <SFML/Graphics.hpp>

class Utils
{
public:

    static float random1D(float min, float max);

    static sf::Vector2f randomPointInScreen();
    static sf::Vector2f random2D();
    static sf::Color randomColor(bool alpha = false);

    static sf::Vector2f getGlobalCenter(sf::Shape&);

private:
    Utils()  = delete;
    ~Utils() = delete;
};

