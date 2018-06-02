#include "wind.h"

#include <Box2D/Box2D.h>
#include "../perlinNoise/PerlinNoise.h"
#include "../../utils.h"

Wind::Wind()
    : m_delta(0.0f, 0.0f, 0.0f)
{
}

Wind::~Wind()
{

}

void Wind::update(const TimeStamp& delta)
{

    m_delta += sf::Vector3f(delta.delta, delta.delta, delta.delta);

    static constexpr unsigned int seed = 237;
    PerlinNoise pn(seed);
    //double noise = pn.noise(0.45, 0.8, 0.55);

    auto tmp1 = Utils::map<double>(pn.noise(m_delta.x, m_delta.y, m_delta.z), 0.0, 1.0, -1.0, 1.0);
    auto tmp2 = Utils::map<double>(pn.noise(m_delta.z, m_delta.y, m_delta.x), 0.0, 1.0, -1.0, 1.0);

    b2Vec2 gravity(static_cast<float32>(tmp1), static_cast<float32>(tmp2));

    static constexpr auto g = 9.98f;

    auto& m_gravity = m_physics.getGravity();
    m_gravity.x = gravity.x * g;
    m_gravity.y = gravity.y * g;

    auto& m_world = m_physics.getWorld();
    m_world.SetGravity(m_gravity);

}

void Wind::render(sf::RenderWindow& window)
{
    static constexpr bool drawBounds  = true;
    static constexpr bool drawLines   = true;

    const unsigned int separation = 100u;
    const auto windowSize = window.getSize();

    for (unsigned int i = 0; i < windowSize.x; i += separation)
    {
        for (unsigned int j = 0; j < windowSize.y; j += separation)
        {
            if (drawBounds)
            {
                static const sf::Vector2f size(1.0f, 1.0f);
                float x = static_cast<float>(i * size.x);
                float y = static_cast<float>(j * size.y);
                float w = size.x * separation;
                float h = size.y * separation;
                sf::RectangleShape shape;
                const auto color = Utils::randomColor();
                shape.setFillColor(sf::Color::Transparent);
                shape.setOutlineThickness(3.0f);
                shape.setOutlineColor(Utils::randomColor());
                shape.setPosition(sf::Vector2f(x, y));
                shape.setSize(sf::Vector2f(w, h));
                window.draw(shape);
            }
            if (drawLines)
            {
                static const sf::Vector2f size(1.0f, 1.0f);
                float w = size.x * separation;
                float h = size.y;
                float x = static_cast<float>( ( i * size.x ) /*+ ( w * 0.5f ) */);
                float y = static_cast<float>( ( j * size.y ) /*+ ( h * 0.5f ) */);
                if ( i!= 0 && j != 0) return;
                sf::Vertex line[2];
                line[0].position = sf::Vector2f(x, y);
                line[0].color = sf::Color::Red;
                line[1].position = sf::Vector2f(x + w, y + h);
                line[1].color = Utils::randomColor();
                window.draw(line, 2, sf::Lines);
            }
        }
    }
}