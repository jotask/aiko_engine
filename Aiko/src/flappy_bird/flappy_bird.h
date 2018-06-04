#pragma once

#include <vector>
#include <memory>

#include "../engine/kimo.h"
#include "../engine/entity.h"
#include "../engine/camera.h"

namespace flappybird
{

    class FlappyBird : public aiko::Kimo
    {
    public:

        FlappyBird();

        virtual void update(const aiko::TimeStamp& delta) final override;
        virtual void render(sf::RenderWindow&) final override;

    private:

        std::vector<std::unique_ptr<aiko::Entity>> m_entities;

        aiko::Camera m_camera;

    };

}