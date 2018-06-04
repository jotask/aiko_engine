#include "pipe_manager.h"

namespace flappybird
{

    PipeManager::PipeManager()
        : m_pipeSpace(3.0f)
        , m_index(0u)
    {
        constexpr unsigned int many = 1;
        for(unsigned int i = 0; i < many; ++i)
        {
            Pipe pipe(*this);
            m_pipes.push_back(pipe);
        }
    }

    void PipeManager::update(const aiko::TimeStamp& delta)
    {
        for (auto& p: m_pipes)
        {
            p.update(delta);
        }
    }

    void PipeManager::render(sf::RenderWindow& window)
    {
        for (auto& p : m_pipes)
        {
            p.render(window);
        }
    }

}