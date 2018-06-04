#pragma once

#include "../../components/component.h"

#include "../physics.h"

namespace aiko
{
    namespace physics
    {

        class PhysicsComponent : public Component
        {
        public:
            PhysicsComponent(const bool _drawDebug = true);
            ~PhysicsComponent();

            // virtual void update(const TimeStamp& delta) override;
            // virtual void render(sf::RenderWindow&) override;

        protected:

            friend class Physic;

            aiko::physics::Physics&       m_physics;

            bool           m_drawDebug;

        };

    }
}