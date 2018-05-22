#pragma once

// sfml
#include <SFML/Graphics.hpp>

// aiko
#include "../engine/time.h"
#include "../constants.h"

class Entity
{
public:

    Entity(sf::Shape*);
    ~Entity();

    virtual void update(const TimeStamp& delta);
    virtual void render(sf::RenderWindow& window);

    bool isColliding(Entity& other) const;

    void bounceScreen();

    sf::Vector2f      m_pos;
    sf::Vector2f      m_vel;
    sf::Vector2f      m_acc;

    sf::Color         m_color;
    
    sf::Shape*        m_bounds;
    float             m_angle;
    float             m_speed;

    float time;

    // virtual void update(const TimeStamp& delta) final override;
    // virtual void render(sf::RenderWindow&) final override;

private:
    static const float MAX_SPEED;

};