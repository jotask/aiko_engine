#pragma once

#include "../engine/kimo.h"

#include "loader.h"
#include "renderer.h"

#include "shaders/shader_program.h"

#include "models/textured_model.h"
#include "models/raw_model.h"

namespace opengl
{

    class Opengl : public aiko::Kimo
    {
    public:
        Opengl();
        ~Opengl();

        virtual void update(const aiko::TimeStamp& delta);
        virtual void render(sf::RenderWindow&);

    private:

        Loader*      m_loader;
        Renderer*    m_renderer;

        RawModel*       m_model;
        TexturedModel*   m_textureModel;

        aiko::ShaderProgram* m_shader;

    };


}