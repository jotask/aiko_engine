#pragma once

#include "environment.h"

namespace aiko
{

    namespace physics
    {

        class Environment3D : public Environment
        {
        public:
            Environment3D();
            virtual ~Environment3D();

            void init(sf::RenderWindow&);

            virtual void update(const aiko::TimeStamp& delta) = 0;
            virtual void render(sf::RenderWindow&) = 0;

            void run();

        };

    }

}