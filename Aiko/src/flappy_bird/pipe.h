#pragma once

#include "../engine/entities/body_entity.h"

namespace flappybird
{

    class Pipe : public aiko::BodyEntity
    {
    public:
        Pipe();

        virtual void update(const aiko::TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

    };

}