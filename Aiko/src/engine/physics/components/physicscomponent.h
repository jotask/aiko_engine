#pragma once

#include "../../components/component.h"

#include "../physics.h"

class PhysicsComponent : public Component
{
public:
    PhysicsComponent();
    ~PhysicsComponent();

    // virtual void update(const TimeStamp& delta);
    // virtual void render(sf::RenderWindow&);

protected:
    
    friend class Physic;

    Physics&       m_physics;

};

