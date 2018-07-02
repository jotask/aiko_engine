#include "opengl.h"

#include "../engine/aiko.h"

#include "shaders/static_shader.h"

namespace opengl
{

    Opengl::Opengl()
        : m_loader(new Loader())
        , m_renderer(new Renderer())
        , m_model(nullptr)
        , m_shader(new aiko::StaticShader())
    {
        std::vector<float> vertices
        ({
            -0.5f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f
        });

        std::vector<GLuint> indices
        ({
            0, 1, 3,
            3, 1, 2
        });

        m_model = m_loader->loadToVao(vertices, indices);

    }

    Opengl::~Opengl()
    {
        delete m_shader;
    }

    void Opengl::update(const aiko::TimeStamp& delta)
    {

    }

    void Opengl::render(sf::RenderWindow&)
    {

        m_shader->start();

        m_renderer->prepare();
        m_renderer->render(*m_model);

        m_shader->stop();
    }

}