#include "flappy_bird.h"

#include "bird.h"
#include "pipe_manager.h"

#include "../engine/utils.h"

namespace flappybird
{

    FlappyBird::FlappyBird()
        : m_pipeManager     (nullptr)
    {

        // add the bird
        //m_entities.push_back(std::make_unique<Bird>());
        // ad the pipes

        constexpr unsigned int MANY = 1;

        for (unsigned int i = 0; i < MANY; ++i)
        {
            m_entities.push_back(std::make_unique<Bird>());
        }

        m_pipeManager = std::make_unique<PipeManager>();

    }

    void FlappyBird::update(const aiko::TimeStamp& delta)
    {
        // update all birds
        for (unsigned int i = 0; i < m_entities.size(); ++i)
        {
            aiko::BodyEntity* entity = m_entities[i].get();

            entity->update(delta);

            // check if bird collides with any pipe
            // if ( m_pipeManager->isColliding(*entity) == true)
            // {
            //    entity->m_color = Utils::randomColor();
            // }

        }
    }

    void FlappyBird::render(sf::RenderWindow& window)
    {
        m_camera.render(window);
        for (auto& entity : m_entities)
        {
            entity->render(window);
        }
    }

}