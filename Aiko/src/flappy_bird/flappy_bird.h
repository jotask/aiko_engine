#pragma once

#include <vector>
#include <memory>

#include "../engine/kimo.h"
#include "../engine/entities/entity.h"
#include "../engine/camera.h"
#include "pipe_manager.h"

namespace flappybird
{

    class FlappyBird : public aiko::Kimo
    {
    public:

        FlappyBird();

        virtual void update(const aiko::TimeStamp& delta) final override;
        virtual void render(sf::RenderWindow&) final override;

    private:

        std::vector<std::unique_ptr<aiko::BodyEntity>> m_entities;

        std::unique_ptr<PipeManager> m_pipeManager;

        aiko::Camera m_camera;

    };

}