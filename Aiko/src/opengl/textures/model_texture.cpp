#include "model_texture.h"

namespace opengl
{

    ModelTexture::ModelTexture(GLuint id)
        : m_textureId (id)
    {

    }

    ModelTexture::~ModelTexture()
    {

    }

    const GLuint ModelTexture::getId() const
    {
        return m_textureId;
    }

}