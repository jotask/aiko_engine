#pragma once

// stl
#include <memory>

// sfml
#include <SFML/Graphics.hpp>

#include "../physics/physics.h"
#include "../physics/physics_utils.h"

// aiko
#include "entity.h"

namespace aiko
{

    class BodyEntity : public Entity
    {
    public:

        BodyEntity(std::unique_ptr<sf::Shape>&&);
        ~BodyEntity();

        virtual void update(const TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

        bool isColliding(BodyEntity& other) const;

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
}