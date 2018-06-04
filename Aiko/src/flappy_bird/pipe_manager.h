#pragma once

#include "pipe.h"
#include <vector>

namespace flappybird
{

    class PipeManager : public aiko::Entity
    {
    public:

        PipeManager();

        virtual void update(const aiko::TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

    private:

        std::vector<Pipe> m_pipes;

    };

}