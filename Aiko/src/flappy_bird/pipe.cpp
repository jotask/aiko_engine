#include "pipe.h"

namespace flappybird
{

    Pipe::Pipe()
        : BodyEntity(std::make_unique<sf::RectangleShape>(sf::Vector2f(10.0f, 10.0f)))
    {

    }

    void Pipe::update(const aiko::TimeStamp& delta)
    {
        Entity::update(delta);
    }

    void Pipe::render(sf::RenderWindow& window)
    {
        Entity::render(window);
    }

}