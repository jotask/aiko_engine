#pragma once

#include "../engine/entity.h"

namespace flappybird
{

    class Pipe : public aiko::Entity
    {
    public:
        Pipe();

        virtual void update(const aiko::TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

    };

}