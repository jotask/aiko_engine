#include "physics_utils.h"

namespace aiko
{
    namespace physics
    {

        b2Body* PhysicsUtils::createCircle(sf::Vector2f pos, float radius)
        {
            auto& physics = Physics::get();

            // Define the dynamic body. We set its position and call the body factory.
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            //bodyDef.type = b2_staticBody;
            //bodyDef.position.Set(0.0f, 4.0f);
            const auto tmp = sfVecToB2Vec(pos);
            bodyDef.position.Set(tmp.x, tmp.y);
            b2Body* body = physics.m_world.CreateBody(&bodyDef);

            // Define another box shape for our dynamic body.
            b2CircleShape dynamicBox;
            dynamicBox.m_radius = radius;
            //dynamicBox.SetAsBox(1.0f, 1.0f);

            // Define the dynamic body fixture.
            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;

            // Set the box density to be non-zero, so it will be dynamic.
            fixtureDef.density = 1.0f;

            // Override the default friction.
            fixtureDef.friction = 0.3f;

            fixtureDef.restitution = 0.6f; // Make it bounce a little bit

                                           // Add the shape to the body.
            body->CreateFixture(&fixtureDef);

            physics.m_bodies.push_back(body);

            return body;
        }

        b2Body* PhysicsUtils::createRectangle(sf::Vector2f pos, sf::Vector2f size)
        {

            auto& physics = Physics::get();

            // Define the dynamic body. We set its position and call the body factory.
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            //bodyDef.type = b2_staticBody;
            //bodyDef.position.Set(0.0f, 4.0f);
            const auto tmp = sfVecToB2Vec(pos);
            bodyDef.position.Set(tmp.x, tmp.y);
            b2Body* body = physics.m_world.CreateBody(&bodyDef);

            // Define another box shape for our dynamic body.
            b2PolygonShape dynamicBox;
            dynamicBox.SetAsBox(size.x, size.y);

            // Define the dynamic body fixture.
            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;

            // Set the box density to be non-zero, so it will be dynamic.
            fixtureDef.density = 1.0f;

            // Override the default friction.
            fixtureDef.friction = 0.3f;

            fixtureDef.restitution = 0.6f; // Make it bounce a little bit

                                           // Add the shape to the body.
            body->CreateFixture(&fixtureDef);

            physics.m_bodies.push_back(body);

            return body;
            return nullptr;
        };

        b2Body* PhysicsUtils::createPolygon(sf::Vector2f pos, std::vector<sf::Vector2f> vertices)
        {

            auto& physics = Physics::get();

            // Define the dynamic body. We set its position and call the body factory.
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            //bodyDef.type = b2_staticBody;
            //bodyDef.position.Set(0.0f, 4.0f);
            const auto tmp = sfVecToB2Vec(pos);
            bodyDef.position.Set(tmp.x, tmp.y);
            b2Body* body = physics.m_world.CreateBody(&bodyDef);

            static const int32 count = vertices.size();

            std::vector<b2Vec2> v;

            if (vertices.size() > 0)
            {
                std::cout << "from shape" << std::endl;
                for (const auto& vert : vertices)
                {
                    v.push_back({ vert.x, vert.y });
                }
            }
            else
            {
                std::cout << "from triangle" << std::endl;
                v.push_back({ 0.0f, 0.0f });
                v.push_back({ 1.0f, 0.0f });
                v.push_back({ 0.5f, 1.0f });
            }

            // Define another box shape for our dynamic body.
            b2PolygonShape dynamicBox;
            //dynamicBox.SetAsBox(1.0f, 1.0f);
            dynamicBox.Set(v.data(), count);

            // Define the dynamic body fixture.
            b2FixtureDef fixtureDef;
            fixtureDef.shape = &dynamicBox;

            // Set the box density to be non-zero, so it will be dynamic.
            fixtureDef.density = 1.0f;

            // Override the default friction.
            fixtureDef.friction = 0.3f;

            fixtureDef.restitution = 0.6f; // Make it bounce a little bit

                                           // Add the shape to the body.
            body->CreateFixture(&fixtureDef);

            physics.m_bodies.push_back(body);

            return body;

        };

    }
}