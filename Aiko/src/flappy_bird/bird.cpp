#include "bird.h"

#include "../engine/utils.h"

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
    Entity::update(delta);
    //Entity::bounceScreen();
}

void Bird::render(sf::RenderWindow& window)
{
    Entity::render(window);
}