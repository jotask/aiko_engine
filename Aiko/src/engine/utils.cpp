#include "utils.h"


float Utils::random1D(float min, float max)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

sf::Vector2f Utils::randomPointInScreen()
{
    const float x = random1D(0.0f, (float) WIDTH );
    const float y = random1D(0.0f, (float) HEIGHT );
    return sf::Vector2f(x, y);
}

sf::Vector2f Utils::random2D()
{
    const float x = random1D(-1.0, 1.0f);
    const float y = random1D(-1.0, 1.0f);
    return sf::Vector2f(x, y);
}

sf::Color Utils::randomColor(bool alpha)
{
    const auto r = random(0, 255);
    const auto g = random(0, 255);
    const auto b = random(0, 255);
    const auto a = random(0, 255);

    if (alpha == true)
    {
        return sf::Color(r, g, b, a);
    }

    return sf::Color(r, g, b);

}

sf::Vector2f Utils::getGlobalCenter(sf::Shape& shape)
{
    // TODO implement
    const auto p = shape.getPosition();
    const auto b = shape.getGlobalBounds();

    sf::Vector2f localCenter;

    localCenter.x = 0;
    localCenter.y = 0;

    sf::Vector2f center(shape.getPosition());

    return center;
}