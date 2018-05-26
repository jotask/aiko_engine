#include "entity.h"

#include <iostream>

#include "../engine/utils.h"

constexpr float Entity::MAX_SPEED = 1000.0f;

const sf::Vector2f GRAVITY = sf::Vector2f(0.0f, 0.0f);

Entity::Entity(std::unique_ptr<sf::Shape>&& shape)
    : m_pos(Utils::randomPointInScreen())
    , m_vel(Utils::random2D())
    , m_acc(0.0f, 0.0f)
    , m_color(Utils::randomColor())
    , m_shape(std::move(shape))
    , m_angle(Utils::random1D() * 360.0f)
    , m_speed(Utils::random1D() * MAX_SPEED)
    , time(0.0f)
    , m_body(Physics::createCircle( m_pos, 1.0f ) )
    , m_applyGravity(true)
    , m_drawBounds(false)
    , m_drawShapes(true)
    , m_drawLines(true)
    , m_drawHeading(false)
{

}

Entity::~Entity()
{

}

void Entity::update(const TimeStamp& delta)
{
    if (false)
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
    else
    {
        // acceleration = force(time, position) / mass;
        // time += timestep;
        // position += timestep * velocity;
        // velocity += timestep * acceleration;
        m_acc.x = 0;
        m_acc.y = 0;
    }

}

void Entity::bounceScreen()
{
    if (m_pos.x < 0)
    {
        m_pos.x = 0;
        m_vel.x *= -1;
    }
    else if ((m_pos.x + m_shape->getLocalBounds().width) >= WIDTH)
    {
        m_pos.x = WIDTH - m_shape->getLocalBounds().width;
        m_vel.x *= -1;
    }

    if (m_pos.y < 0)
    {
        m_pos.y = 0;
        m_vel.y *= -1;
    }
    else if ((m_pos.y + m_shape->getLocalBounds().height) >= HEIGHT)
    {
        m_pos.y = HEIGHT - m_shape->getLocalBounds().height;
        m_vel.y *= -1;
    }
}

void Entity::render(sf::RenderWindow& window)
{

    const auto bounds = m_shape->getLocalBounds();

    if (m_drawBounds)
    {
        // drawbounds
        sf::RectangleShape shape;
        shape.setPosition(m_shape->getPosition());
        shape.setSize(sf::Vector2f(m_shape->getLocalBounds().width, m_shape->getLocalBounds().height));
        window.draw(shape);
    }

    if (m_drawShapes)
    {
        // draw shape
        m_shape->setPosition(m_pos);
        m_shape->setFillColor(m_color);
        window.draw(*m_shape);
    }

    if (m_drawLines)
    {
        // draw line. The head. Pointing
        const sf::Vector2f center(m_pos + sf::Vector2f(bounds.width * 0.5f, bounds.height * 0.5f));

        const auto radius = 50.0f;

        float x = center.x;
        float y = center.y;

        x += radius * sin(m_angle);
        y += radius * cos(m_angle);

        // TODO make const
        sf::Vector2f target(x, y);

        if (m_drawHeading)
        {

            target.x = center.x;
            target.y = center.y;

            const auto w = 30;
            const auto h = 30;

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

}

bool Entity::isColliding(Entity& other) const
{
    return m_shape->getGlobalBounds().intersects(other.m_shape->getGlobalBounds());
}