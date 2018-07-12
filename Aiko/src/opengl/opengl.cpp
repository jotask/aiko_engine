#include "opengl.h"

#include "../engine/aiko.h"

#include "shaders/static_shader.h"

namespace opengl
{

    Opengl::Opengl()
        : m_loader(std::make_unique<Loader>())
        , m_renderer(std::make_unique<Renderer>())
        , m_shader(std::make_unique<StaticShader>())
        , m_textureModel(nullptr)
    {
        if(false)
        {
            static std::vector<float> vertices
            ({
                -0.5f,  0.5f, 0.0f,
                -0.5f, -0.5f, 0.0f,
                 0.5f, -0.5f, 0.0f,
                 0.5f,  0.5f, 0.0f
                });

            static std::vector<GLuint> indices
            ({
                0, 1, 3,
                3, 1, 2
                });

            static std::vector<GLfloat> textureCoords =
            {
                0.0f, 0.0f,
                0.0f, 1.0f,
                1.0f, 1.0f,
                1.0f, 0.0f
            };

            const std::string tmp("image.png");
            const auto text = m_loader->loadTexture(tmp);
            auto model = m_loader->loadToVao(vertices, indices, textureCoords);
            auto texture = std::make_unique<Texture>(text);
            m_textureModel = std::make_unique<TexturedModel>(model, texture);
        }

        // debug
        if(true)
        {
            const std::string tmp("image.png");
            const auto text = m_loader->loadTexture(tmp);
            auto model = m_loader->loadTest();
            auto texture = std::make_unique<Texture>(text);
            m_textureModel = std::make_unique<TexturedModel>(model, texture);
        }

    }

    Opengl::~Opengl()
    {
    }

    void Opengl::update(const aiko::TimeStamp& delta)
    {

    }

    void Opengl::render(sf::RenderWindow&)
    {

        m_shader->start();

        m_renderer->prepare();
        m_renderer->render(*m_textureModel);
        m_renderer->end();

        m_shader->stop();
    }

}