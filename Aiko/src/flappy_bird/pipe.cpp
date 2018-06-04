#include "pipe.h"

#include "pipe_manager.h"

namespace flappybird
{

    Pipe::Pipe(const PipeManager& manager)
        : BodyEntity(std::make_unique<sf::RectangleShape>(sf::Vector2f(10.0f, 10.0f)))
        , m_manager(manager)
        , m_index(0u)
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

    void Pipe::restart(unsigned int, sf::Vector2f)
    {

    }

}