#include "bird.h"

#include "../engine/utils.h"

#include <SFML/Graphics.hpp>

Bird::Bird()
    : Entity( std::make_unique<sf::CircleShape>(30.0f, 30U) )
{

}

void Bird::restart()
{
    const auto pos = Utils::randomPointInScreen();
    m_pos = pos;
    std::cout << "bird restart hello world" << std::endl;
}

void Bird::update(const TimeStamp& delta)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        // left key is pressed: move our character
        m_body->ApplyForce(b2Vec2(0, -100), m_body->GetWorldCenter(), true);
        // character.move(1, 0);
    }

    Entity::update(delta);
    //Entity::bounceScreen();
}

void Bird::render(sf::RenderWindow& window)
{
    Entity::render(window);
}