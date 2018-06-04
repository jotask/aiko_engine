#pragma once

#include "../engine/entities/body_entity.h"

namespace flappybird
{

    class PipeManager;

    class Pipe : public aiko::BodyEntity
    {
    public:

        Pipe(const PipeManager&);

        virtual void update(const aiko::TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

        void restart(unsigned int, sf::Vector2f);

        const PipeManager& m_manager;
        unsigned int m_index;

    };

}