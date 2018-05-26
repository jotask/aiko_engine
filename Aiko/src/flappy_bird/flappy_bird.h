#pragma once

#include <vector>
#include <memory>

#include "../engine/kimo.h"
#include "../engine/entity.h"

class FlappyBird : public Kimo
{
public:

    FlappyBird();

    virtual void update(const TimeStamp& delta) final override;
    virtual void render(sf::RenderWindow&) final override;

private:

    std::vector<std::unique_ptr<Entity>> m_entities;

};