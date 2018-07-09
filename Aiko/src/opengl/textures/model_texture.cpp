#include "model_texture.h"

namespace opengl
{

    const float ModelTexture::textureCoords[] = { 0,0, 0,1, 1,1, 1,0 };

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