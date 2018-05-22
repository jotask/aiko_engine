#include "flappy_bird.h"

#include "bird.h"
#include "pipe.h"

#include "../engine/utils.h"

FlappyBird::FlappyBird()
{

    // add the bird
    //m_entities.push_back(std::make_unique<Bird>());
    // ad the pipes

    constexpr unsigned int MANY = 10;

    for (unsigned int i = 0; i < MANY; ++i)
    {
        //auto pipe = std::make_unique<Pipe>();
        //m_entities.push_back(std::move(pipe));
        m_entities.push_back(std::make_unique<Bird>());
    }

}

void FlappyBird::update(const TimeStamp& delta)
{
    for (unsigned int i = 0; i < m_entities.size(); ++i)
    {
        Entity* entity = m_entities[i].get();
        entity->update(delta);

        for (unsigned int j = 0; j < m_entities.size(); ++j)
        {
            if (i == j) continue;

            Entity* other = m_entities[j].get();

            if (entity->isColliding(*other) == true)
            {
                //printf("Colliding [ a = %d] with [ b = %d ] \n", i, j);
                entity->m_color = Utils::randomColor();
            }

        }

    }
}

void FlappyBird::render(sf::RenderWindow& window)
{
    for (auto& entity : m_entities)
    {
        entity->render(window);
    }
}