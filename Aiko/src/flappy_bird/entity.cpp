#include "entity.h"

#include <iostream>

#include "../engine/utils.h"

const float Entity::MAX_SPEED = 1000.0f;

Entity::Entity(sf::Shape* shape)
    : m_pos(Utils::randomPointInScreen())
    , m_vel(Utils::random2D())
    , m_acc(0.0f, 0.0f)
    , m_color(Utils::randomColor())
    , m_bounds(shape)
    , m_angle(0.0f)
    , m_speed(Utils::random1D(0.0f, 1.0f) * MAX_SPEED)
    , time (0.0f)
{
    std::cout << "Entity created" << std::endl;
}

Entity::~Entity()
{
    delete m_bounds;

    std::cout << "Entity deleted" << std::endl;
}

void Entity::update(const TimeStamp& delta)
{

    time += delta.delta;

    m_angle += delta.delta;

    const auto x = m_vel.x;
    const auto y = m_vel.y;

    m_vel *= delta.delta;

    m_vel *= m_speed;

    m_pos += m_vel;

    m_vel.x = x;
    m_vel.y = y;

}

void Entity::bounceScreen()
{
    if (m_pos.x < 0)
    {
        m_pos.x = 0;
        m_vel.x *= -1;
    }
    else if ((m_pos.x + m_bounds->getLocalBounds().width) >= WIDTH)
    {
        m_pos.x = WIDTH - m_bounds->getLocalBounds().width;
        m_vel.x *= -1;
    }

    if (m_pos.y < 0)
    {
        m_pos.y = 0;
        m_vel.y *= -1;
    }
    else if ((m_pos.y + m_bounds->getLocalBounds().height) >= HEIGHT)
    {
        m_pos.y = HEIGHT - m_bounds->getLocalBounds().height;
        m_vel.y *= -1;
    }
}

void Entity::render(sf::RenderWindow& window)
{

    const auto bounds = m_bounds->getGlobalBounds();

    // drawbounds
    sf::RectangleShape shape;
    shape.setPosition(m_bounds->getPosition());
    shape.setSize(sf::Vector2f(m_bounds->getLocalBounds().width, m_bounds->getLocalBounds().height));
    //window.draw(shape);

    // draw shape
    m_bounds->setPosition(m_pos);
    m_bounds->setFillColor(m_color);
    window.draw(*m_bounds);


    // draw line. The head. Pointing
    const sf::Vector2f center(m_pos + sf::Vector2f(bounds.width * 0.5f, bounds.height * 0.5f));

    const auto radius = 50.0f;

    float x = center.x;
    float y = center.y;

    x += radius * sin(m_angle);
    y += radius * cos(m_angle);

    // TODO make const
    sf::Vector2f target(x, y);

    if (true)
    {

        x = 0.0f;
        y = 0.0f;

        const auto w = bounds.width;
        const auto h = bounds.height;

        (m_vel.x > 0) ? target.x += w : target.x -= w;
        (m_vel.y > 0) ? target.y += h : target.y -= h;
    }

    sf::Vertex line[2];
    line[0].position = center;
    line[0].color = sf::Color::Red;
    line[1].position = target;
    line[1].color = sf::Color::Yellow;

    window.draw(line, 2, sf::Lines);

}

bool Entity::isColliding(Entity& other) const
{
    return m_bounds->getGlobalBounds().intersects(other.m_bounds->getGlobalBounds());
}