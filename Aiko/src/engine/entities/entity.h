#pragma once

// stl
#include <memory>

// sfml
#include <SFML/Graphics.hpp>

#include "../physics/physics.h"

// aiko
#include "../../constants.h"
#include "../time.h"
#include "../utils.h"

namespace aiko
{

    class Entity
    {
    public:

        Entity();
        ~Entity();

        virtual void update(const TimeStamp& delta);
        virtual void render(sf::RenderWindow& window);

        // virtual void update(const TimeStamp& delta) final override;
        // virtual void render(sf::RenderWindow&) final override;

    };
}