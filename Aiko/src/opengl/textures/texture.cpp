#include "texture.h"

namespace opengl
{

    std::vector<float> Texture::textureCoords =
    {
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };

    Texture::Texture(GLuint id)
        : m_textureId (id)
    {

    }

    Texture::~Texture()
    {

    }

    const GLuint Texture::getId() const
    {
        return m_textureId;
    }

}