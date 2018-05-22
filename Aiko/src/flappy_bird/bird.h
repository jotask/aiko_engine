#pragma once

#include "entity.h"

class Bird : public Entity
{
public:
    Bird();

    virtual void update(const TimeStamp& delta);
    virtual void render(sf::RenderWindow& window);

    void restart();

};