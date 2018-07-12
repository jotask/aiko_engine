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

        std::unique_ptr<Loader>             m_loader;
        std::unique_ptr<Renderer>           m_renderer;
        std::unique_ptr<ShaderProgram>      m_shader;

        std::unique_ptr<TexturedModel>      m_textureModel;


    };


}