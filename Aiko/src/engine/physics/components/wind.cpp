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

    //std::cout << "x:" << tmp1 << " y: " << tmp2 << " x:" << m_gravity.x << " y: " << m_gravity.y << std::endl;

    auto& m_world = m_physics.getWorld();
    m_world.SetGravity(m_gravity);

    std::cout << "wind" << std::endl;

}

void Wind::render(sf::RenderWindow&)
{

}