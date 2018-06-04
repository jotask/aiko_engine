#pragma once

#include  <SFML/Graphics.hpp>

#include "../../time.h"

#include "environment_type.h"

namespace aiko
{

    namespace physics
    {
    
        class Environment
        {
        public:
            Environment(const EnvironmentType type);
            virtual ~Environment();

            void init(sf::RenderWindow&);

            virtual void update(const aiko::TimeStamp& delta) = 0;
            virtual void render(sf::RenderWindow&) = 0;

        protected:

            EnvironmentType            m_type;

        };

    }

}