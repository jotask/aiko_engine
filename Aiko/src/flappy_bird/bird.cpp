#include "bird.h"

#include "../engine/utils.h"

#include <SFML/Graphics.hpp>

namespace flappybird
{

    // constexpr auto Bird::JUMP_FORCE = 1000;

    Bird::Bird()
        : BodyEntity(std::make_unique<sf::CircleShape>(30.0f, 30U))
        , m_canJump(true)
    {

    }

    void Bird::restart()
    {
        const auto pos = Utils::randomPointInScreen();
        m_pos = pos;
        std::cout << "bird restart hello world" << std::endl;
    }

    void Bird::update(const aiko::TimeStamp& delta)
    {

        Entity::update(delta);

        m_canJump = m_body->GetLinearVelocity().y >= 0.0f;

        // we want to jump if the space has been pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // we only want to jump if we are going downwards
            if (m_canJump == true)
            {
                m_canJump = false;
                // we want to clear all forces and apply our jump force
                m_body->SetLinearVelocity(b2Vec2(0, 0));
                m_body->SetAngularVelocity(0);
                m_body->ApplyLinearImpulse(b2Vec2(0, -JUMP_FORCE), m_body->GetWorldCenter(), true);
            }
        }

        manageRotation(delta.delta);

        //Entity::bounceScreen();
    }

    void Bird::render(sf::RenderWindow& window)
    {
        Entity::render(window);
    }

    void Bird::manageRotation(float delta)
    {
        /*
        if (currVerticalVelocity > -200) {
            float rotation = currVerticalVelocity + 200;
            desiredRotation = rotation / 15f;
        }
        if (currVerticalVelocity <= -200) {
            float rotation = currVerticalVelocity + 200;
            if (rotation < -400) rotation = -400;
            desiredRotation = rotation / 4.4f;
        }

        if (desiredRotation != bird.getRotation()) {
            if (desiredRotation > bird.getRotation()) {
                bird.setRotation(bird.getRotation() + 900 * delta);
                if (desiredRotation < bird.getRotation()) bird.setRotation(
                    desiredRotation);
            }
            if (desiredRotation < bird.getRotation()) {
                bird.setRotation(bird.getRotation() - 900 * delta);
                if (desiredRotation > bird.getRotation()) bird.setRotation(
                    desiredRotation);
            }
        }
        */
    }

}