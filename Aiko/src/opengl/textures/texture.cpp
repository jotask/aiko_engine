#include "texture.h"

namespace opengl
{

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