#pragma once

// stl
#include <memory>

// sfml
#include <SFML/Graphics.hpp>

#include "physics/physics.h"

// aiko
#include "time.h"
#include "../constants.h"
#include "utils.h"

class Entity
{
public:

    Entity(std::unique_ptr<sf::Shape>&&);
    ~Entity();

    virtual void update(const TimeStamp& delta);
    virtual void render(sf::RenderWindow& window);

    bool isColliding(Entity& other) const;

    void bounceScreen();

    sf::Vector2f      m_pos;
    sf::Vector2f      m_vel;
    sf::Vector2f      m_acc;

    sf::Color         m_color;
    
    std::shared_ptr<sf::Shape> m_shape;
    float             m_angle;
    float             m_speed;

    float time;

    // virtual void update(const TimeStamp& delta) final override;
    // virtual void render(sf::RenderWindow&) final override;

private:

    static b2Body* getBody(sf::Vector2f pos, sf::Shape* shape);

protected:

    static const float          MAX_SPEED;
    static const sf::Vector2f   GRAVITY;

    b2Body* m_body;

    sf::Clock m_clock;

    // physics
    bool m_applyGravity;

    // rendering
    bool m_drawBounds;
    bool m_drawShapes;
    bool m_drawLines;
    bool m_drawHeading;

};