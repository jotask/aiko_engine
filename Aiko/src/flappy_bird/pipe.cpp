#include "pipe.h"

Pipe::Pipe()
    : Entity(std::make_unique<sf::RectangleShape>(sf::Vector2f(10.0f, 10.0f)))
{

}

void Pipe::update(const TimeStamp& delta)
{
    Entity::update(delta);
}

void Pipe::render(sf::RenderWindow& window)
{
    Entity::render(window);
}