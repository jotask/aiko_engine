#pragma once

#include "physicscomponent.h"

class Wind : public PhysicsComponent
{
public:
    Wind();
    ~Wind();

    void update(const TimeStamp& delta) final override;
    void render(sf::RenderWindow&)      final override;

private:

    sf::Vector3f m_delta;
};

