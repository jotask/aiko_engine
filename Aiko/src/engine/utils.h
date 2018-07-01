#pragma once

#include "../constants.h"
#include <SFML/Graphics.hpp>

class Utils
{
public:

    static float random1D();
    static float random1D(float min, float max);

    template<class T>
    static T map(T value, T iStart, T iStop, T oStart, T oStop)
    {
        return oStart + (oStop - oStart) * ((value - iStart) / (iStop - iStart));
    }

    template <class T>
    int getArray(T x, T y, float SIZE_Y) { x * SIZE_Y + y; }


    static sf::Vector2f randomPointInScreen();
    static sf::Vector2f random2D();
    static sf::Color randomColor(bool alpha = false);

    static sf::Vector2f getGlobalCenter(sf::Shape&);

private:
    Utils()  = delete;
    ~Utils() = delete;
};

