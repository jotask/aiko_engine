#pragma once

#include "../engine/entity.h"

namespace flappybird
{

    class Bird : public aiko::Entity
    {
    public:

        Bird();

        virtual void update(const aiko::TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

        void restart();

    };

}