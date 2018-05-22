#pragma once

#include "entity.h"

class Pipe : public Entity
{
public:
    Pipe();

    virtual void update(const TimeStamp& delta);
    virtual void render(sf::RenderWindow& window);

};