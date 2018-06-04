#pragma once

#include "../engine/entities/body_entity.h"

namespace flappybird
{

    class Bird : public aiko::BodyEntity
    {
    public:

        static constexpr auto JUMP_FORCE = 5;

        Bird();

        virtual void update(const aiko::TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

        void restart();

    private:

        void manageRotation(float delta);

        bool m_canJump;

    };

}