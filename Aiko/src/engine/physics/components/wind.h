#pragma once

#include "physicscomponent.h"
#include "../perlinNoise/PerlinNoise.h"

namespace aiko
{
    namespace physics
    {

        class Wind : public PhysicsComponent
        {
        public:
            Wind();
            ~Wind();

            void update(const TimeStamp& delta) final override;
            void render(sf::RenderWindow&)      final override;

        private:

            static constexpr unsigned int seed = 237;

            PerlinNoise pn;

            sf::Vector3f m_delta;
        };

    }
}